#!/bin/bash
set -ex

root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"
source "$root_dir/tools/common/ccache.sh"

source_dir="$root_dir/source-code"
src_dir="$source_dir/nwjs/src"
output_dir="$root_dir/output"
llvm_version=$(node $root_dir/tools/parse-config.js --get-llvm-version $@)
llvm_dir="$output_dir/llvm-$llvm_version"

nw_version=$(node $root_dir/tools/parse-config.js --get-nw-version $@)
nw_gen_arg=$(node $root_dir/tools/parse-config.js --get-nw-gen-arg $@)
nw_gyp_arg=$(node $root_dir/tools/parse-config.js --get-nw-gyp-arg $@)
nw_gyp_method=$(node $root_dir/tools/parse-config.js --get-nw-gyp-method $@)

# patch
node "$root_dir/tools/patch-apply.js" "$nw_version"

if [ ! -d "$src_dir/build/linux/debian_bullseye_loong64-sysroot" ];then
  cd "$src_dir/build/linux"
  ln -s "../../../../sysroot" "debian_bullseye_loong64-sysroot"
fi

notice "Start to gen nw"
mkdir -p $output_dir/out
cd "$src_dir"

# sudo mount -t tmpfs -o size=20G tmpfs $output_dir/out
# TODO: 需要确认
# if [ ! -s "out" ];then
#   ln -s $src_dir/out out
# fi

./buildtools/linux64/gn gen out/nw --args="clang_use_chrome_plugins=false treat_warnings_as_errors=false dcheck_always_on=false clang_base_path=\"$llvm_dir\" is_debug=false is_component_build=false is_component_ffmpeg=true target_cpu=\"loong64\" use_sysroot=false cc_wrapper=\"env CCACHE_SLOPPINESS=time_macros ccache\" $nw_gen_arg"

# https://nwjs.readthedocs.io/en/latest/For%20Developers/Building%20NW.js/
notice "start to prepare gyp"
# 参考 http://buildbot-master.nwjs.io:8010/builders/nw83_linux64/builds/0/steps/node_gyp/logs/stdio
export GYP_CHROMIUM_NO_ACTION=0
export GYP_CROSSCOMPILE=1
export GYP_DEFINES="building_nw=1 clang=1 target_arch=loong64 remove_webcore_debug_symbols=1 clang_base_dir=$llvm_dir buildtype=Official $nw_gyp_arg"
export GYP_GENERATORS=ninja
export GYP_GENERATOR_FLAGS=output_dir=out
export PYTHONPATH=${src_dir}/third_party/node-nw/tools/v8_gypfiles
if [ "$nw_gyp_method" == "v1" ];then
  ./build/gyp_chromium -I third_party/node-nw/common.gypi third_party/node-nw/node.gyp --no-duplicate-basename-check
else
  python3 third_party/node-nw/tools/gyp/gyp_main.py -I third_party/node-nw/common.gypi third_party/node-nw/node.gyp
fi

notice "Check gen result"
if [ ! -d "$src_dir/out/nw" ];then
  fail "out/nw 文件夹不存在"
  exit 1;
fi
if [ ! -d "$src_dir/out/Release" ];then
  fail "out/Release 文件夹不存在"
  exit 1;
fi