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

if [ ! -d "$root_dir/binutils-gdb" ]; then
  notice "binutils-gdb not cloned, start to clone......"
  git clone https://sourceware.org/git/binutils-gdb.git
fi

max_thread=$(cat /proc/cpuinfo| grep "processor"| wc -l)
export JOBS=$max_thread

cd binutils-gdb
mkdir build
cd build
toolchain_dir="$root_dir/toolchain"
mkdir -p "$toolchain_dir"

notice "configure binutils-gdb for x86_64"
../configure --prefix=$toolchain_dir --target=x86_64-linux-gnu --disable-nls --enable-shared --enable-64-bit-bfd --disable-werror
notice "make binutils-gdb for x86_64"
make && make install

rm ./* -rf
notice "configure binutils-gdb for loongarch64"
../configure --prefix=$toolchain_dir --target=loongarch64-linux-gnu --with-sysroot --disable-nls --enable-shared --enable-64-bit-bfd --disable-werror
notice "make binutils-gdb for loongarch64"
make && make install