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
export PATH=$output_dir/cmake-3.20.5-linux-x86_64/bin:$PATH

mkdir -p $root_dir/cache
mkdir -p $output_dir

# 下载
notice "Start to download cmake..."
if [ ! -f "$root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz" ];then
  wget -c -O$root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz.tmp https://github.com/Kitware/CMake/releases/download/v$cmake_ver/cmake-$cmake_ver-linux-x86_64.tar.gz
  mv $root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz.tmp $root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz
fi

# 解压
notice "Start to extract cmake..."
if [ ! -d "$output_dir/cmake-$cmake_ver-linux-x86_64" ];then
  tar -zxf $root_dir/cache/cmake-$cmake_ver-linux-x86_64.tar.gz -C $output_dir
fi
