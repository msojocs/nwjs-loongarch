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
export PATH=$PATH:/opt/loongarch64/toolchain/bin:$root_dir/cmake-3.20.5-linux-x86_64/bin:$root_dir/depot_tools

# 拉取源代码
cd $root_dir
mkdir -p nwjs
cd nwjs
# gclient config --name=src https://github.com/nwjs/chromium.src.git@origin/nw80
# git clone -b nw80 https://github.com/nwjs/v8.git src/v8
# git clone -b nw80 https://github.com/nwjs/node.git src/third_party/node-nw
# git clone -b nw80 https://github.com/loongson/nw.js.git src/content/nw
gclient sync --with_branch_heads