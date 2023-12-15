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
max_thread=$(cat /proc/cpuinfo| grep "processor"| wc -l)
export JOBS=$max_thread
source_dir="$root_dir/source-code"
output_dir="$root_dir/output"
toolchain_dir="$output_dir/toolchain"

if [ ! -d "$source_dir/binutils-gdb" ]; then
  notice "binutils-gdb not cloned, start to clone......"
  mkdir -p "$source_dir"
  cd "$source_dir"
  git clone https://sourceware.org/git/binutils-gdb.git
fi

project_dir="$source_dir/binutils-gdb"
build_dir="$project_dir/build"
mkdir -p "$build_dir"
mkdir -p "$toolchain_dir"
cd "$source_dir/binutils-gdb/build"

cd "$project_dir"
git checkout tags/gdb-14.1-release
if [ ! -f "$toolchain_dir/bin/x86_64-linux-gnu-ld" ];then
  notice "configure binutils-gdb for x86_64"
  rm ./* -rf
  ../configure --prefix=$toolchain_dir --target=x86_64-linux-gnu --disable-nls --enable-shared --enable-64-bit-bfd --disable-werror
  notice "make binutils-gdb for x86_64"
  make -j$max_thread && make install
fi

if [ ! -f "$toolchain_dir/bin/loongarch64-linux-gnu-ld" ];then
  rm ./* -rf
  notice "configure binutils-gdb for loongarch64"
  ../configure --prefix=$toolchain_dir --target=loongarch64-linux-gnu --with-sysroot --disable-nls --enable-shared --enable-64-bit-bfd --disable-werror
  notice "make binutils-gdb for loongarch64"
  make -j$max_thread && make install
fi