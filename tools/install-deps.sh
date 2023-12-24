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

src_dir="$root_dir/source-code/nwjs/src"

dep_script="$src_dir/build/install-build-deps.sh"

if [ -f "$dep_script" ];then
  notice "阁下已经拉取了源码，开始执行项目的依赖安装脚本....."
  "$dep_script" --no-chromeos-fonts
fi

sudo apt update

notice "Install packages for binutil-gdb"
sudo apt install -y libmpc-dev texinfo bison flex

notice "Install packages for llvm-project"
sudo apt install -y ninja-build python3

notice "Install packages for nwjs"
sudo apt install -y python \
libpango1.0-dev \
libdbus-1-dev \
libx11-xcb-dev
# xz-utils \
# curl \
# libcups2-dev \
# libglib2.0-dev \
# libnss3-dev \
# libxkbcommon-dev \
# libdrm-dev \
# libgbm-dev \
# gperf \
# libkrb5-dev
sudo apt install -y gcc-multilib g++-multilib