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

output_dir="$root_dir/output"
cmake_ver="3.20.5"
# 下载
if [ ! -f "$root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz" ];then
  wget -O$root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz https://github.com/Kitware/CMake/releases/download/v$cmake_ver/cmake-$cmake_ver-linux-x86_64.tar.gz
fi
# 解压
if [ ! -d "$output_dir/cmake-$cmake_ver-linux-x86_64" ];then
  tar -zxf $root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz -C $output_dir
fi