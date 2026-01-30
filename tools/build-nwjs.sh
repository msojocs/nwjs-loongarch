#!/bin/bash
set -ex

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
output_dir="$root_dir/output"
source_dir="$root_dir/source-code"
###############################################################
######关键######################################################
###不加会报错：##################################################
###/usr/bin/ld: unrecognised emulation mode: elf64loongarch####
###############################################################
llvm_version=$(node $root_dir/tools/parse-config.js --get-llvm-version $@)
build_mode=$(node $root_dir/tools/parse-config.js --get-build-mode $@)
export PATH="$output_dir/cmake-linux-x86_64/bin:$output_dir/llvm-$llvm_version/bin:$output_dir/toolchain/bin:$output_dir/depot_tools:$PATH"
src_dir="$source_dir/nwjs/src"
max_thread=$(($(cat /proc/cpuinfo| grep "processor"| wc -l) - 6))
source "$root_dir/tools/common/ccache.sh"

cd $src_dir

notice "Start to build nwjs"
ninja -C out/nw nwjs -j$max_thread

notice "Start to build node"
if [ "$build_mode" == "debug" ];then
  build_dir="Debug"
else
  build_dir="Release"
fi
ninja -C out/$build_dir node -j$max_thread
ninja -C out/nw copy_node

notice "Start to build components"
ninja -C out/nw credits.html
ninja -C out/nw nwjc -j$max_thread
ninja -C out/nw chromedriver -j$max_thread
ninja -C out/nw minidump_stackwalk -j$max_thread
# nw90不构建
# 使用ninja检查是否有payload构建目标
if ninja -C out/nw -t targets | grep 'payload'; then
  notice "开始构建payload"
  ninja -C out/nw payload -j$max_thread
else
  notice "当前版本不支持payload构建，跳过此步骤"
fi
