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
cache_dir="$root_dir/cache"
sysroot_name="clfs-loongarch64-system-8.1-sysroot.squashfs"
# 下载
if [ ! -f "$cache_dir/$sysroot_name" ];then
  wget -c -O"$cache_dir/$sysroot_name.tmp" https://github.com/loongson/build-tools/releases/download/2023.08.08/clfs-loongarch64-system-8.1-sysroot.squashfs
  mv $cache_dir/$sysroot_name.tmp $cache_dir/$sysroot_name
fi
# 解压
if [ -z "$(ls -A $source_dir/sysroot)" ];then
  unsquashfs -d $source_dir/sysroot -no-xattrs $cache_dir/$sysroot_name usr/include usr/lib usr/lib64 usr/share lib lib64
fi