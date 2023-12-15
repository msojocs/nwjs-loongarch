#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
success() {
    echo -e "\033[42;37m 成功 \033[0m $1"
}
notice() {
    echo -e "\033[36m $1 \033[0m "
}
fail() {
    echo -e "\033[41;37m 失败 \033[0m $1"
}

source_dir="$root_dir/source-code"
src_dir="$source_dir/nwjs/src"
output_dir="$root_dir/output"
llvm_dir="$output_dir/llvm-18"
cd "$src_dir"

if [ ! -d "$src_dir/build/linux/debian_bullseye_loong64-sysroot" ];then
  cd "$src_dir/build/linux"
  ln -s "../../../../sysroot" "debian_bullseye_loong64-sysroot"
fi

notice "start to gen nw"
./buildtools/linux64/gn gen out/nw --args='clang_use_chrome_plugins=false treat_warnings_as_errors=false dcheck_always_on=false use_gold=false use_lld=false clang_base_path="'$llvm_dir'" is_debug=false is_component_build=false is_component_ffmpeg=true target_cpu="loong64" use_sysroot=false'

notice "start to prepare gyp"
PYTHONPATH=${PWD}/third_party/node-nw/tools/v8_gypfiles GYP_CHROMIUM_NO_ACTION=0 GYP_CROSSCOMPILE=1 ./build/gyp_chromium -I third_party/node-nw/common.gypi -D building_nw=1 -D clang=1 -D target_arch=loong64 -D clang_base_dir="$llvm_dir" third_party/node-nw/node.gyp --no-duplicate-basename-check