#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

source_dir="$root_dir/source-code"
src_dir="$source_dir/nwjs/src"
output_dir="$root_dir/output"
llvm_dir="$output_dir/llvm-18"

source "$root_dir/config/nw-version.sh"
if [ ! -d "$src_dir/build/linux/debian_bullseye_loong64-sysroot" ];then
  cd "$src_dir/build/linux"
  ln -s "../../../../sysroot" "debian_bullseye_loong64-sysroot"
fi

# patch
patch_dir="$root_dir/patches/$nw_version"
if [ -f "$patch_dir/patch.js" ]; then
  notice "Start to patch."
  node "$patch_dir/patch.js" "$src_dir"
else
  warn "No patches was found."
fi

notice "Start to gen nw"
cd "$src_dir"
if [ -f "$patch_dir/gen.sh" ];then
  source "$patch_dir/gen.sh"
else
  echo $llvm_dir
  ./buildtools/linux64/gn gen out/nw --args='clang_use_chrome_plugins=false treat_warnings_as_errors=false dcheck_always_on=false use_gold=false use_lld=false clang_base_path="'$llvm_dir'" is_debug=false is_component_build=false is_component_ffmpeg=true target_cpu="loong64" use_sysroot=false'
fi

notice "start to prepare gyp"
# 参考 http://buildbot-master.nwjs.io:8010/builders/nw83_linux64/builds/0/steps/node_gyp/logs/stdio
PYTHONPATH=${PWD}/third_party/node-nw/tools/v8_gypfiles GYP_CHROMIUM_NO_ACTION=0 GYP_CROSSCOMPILE=1 python3 ./third_party/node-nw/tools/gyp/gyp_main.py -I third_party/node-nw/common.gypi -D building_nw=1 -D clang=1 -D target_arch=loong64 -D clang_base_dir="$llvm_dir" third_party/node-nw/node.gyp