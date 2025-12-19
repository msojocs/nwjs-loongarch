#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

source_dir="$root_dir/source-code"
src_dir="$source_dir/nwjs/src"
output_dir="$root_dir/output"
llvm_version=$(node $root_dir/tools/parse-config.js --get-llvm-version $@)
llvm_dir="$output_dir/llvm-$llvm_version"

nw_version=$(node $root_dir/tools/parse-config.js --get-nw-version $@)
nw_gen_arg=$(node $root_dir/tools/parse-config.js --get-nw-gen-arg $@)

# patch
node "$root_dir/tools/patch-apply.js" "$nw_version"

if [ ! -d "$src_dir/build/linux/debian_bullseye_loong64-sysroot" ];then
  cd "$src_dir/build/linux"
  ln -s "../../../../sysroot" "debian_bullseye_loong64-sysroot"
fi

notice "Start to gen nw"
cd "$src_dir"
./buildtools/linux64/gn gen out/nw --args="clang_use_chrome_plugins=false treat_warnings_as_errors=false dcheck_always_on=false clang_base_path=\"$llvm_dir\" is_debug=false is_component_build=false is_component_ffmpeg=true target_cpu=\"loong64\" use_sysroot=false $nw_gen_arg"

# https://nwjs.readthedocs.io/en/latest/For%20Developers/Building%20NW.js/
# TODO: nw93 此处生成命令改变了
notice "start to prepare gyp"
# 参考 http://buildbot-master.nwjs.io:8010/builders/nw83_linux64/builds/0/steps/node_gyp/logs/stdio
export GYP_CHROMIUM_NO_ACTION=0
export GYP_CROSSCOMPILE=1
if [ "$nw_version" == "nw93" ];then
  export GYP_DEFINES=target_arch=loong64 building_nw=1 clang=1 icu_use_data_file_flag=1 host_arch=x64 nwjs_sdk=1 disable_nacl=0
  export GYP_GENERATORS=ninja
  export GYP_GENERATOR_FLAGS=output_dir=out
  python3 third_party/node-nw/tools/gyp/gyp_main.py -I third_party/node-nw/common.gypi -D msvs_version=2021 -D build_type=Release_x64 -D building_nw=1 -D clang=1 -D target_arch=loong64 -D clang_base_dir=$llvm_dir third_party/node-nw/node.gyp
else
  PYTHONPATH=${PWD}/third_party/node-nw/tools/v8_gypfiles ./build/gyp_chromium -I third_party/node-nw/common.gypi -D building_nw=1 -D clang=1 -D target_arch=loong64 -D clang_base_dir=$llvm_dir third_party/node-nw/node.gyp --no-duplicate-basename-check
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