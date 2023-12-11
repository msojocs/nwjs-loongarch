#!/bin/bash
set -e
export https_proxy=http://172.27.176.1:7890
git clone https://sourceware.org/git/binutils-gdb.git
cd binutils-gdb
mkdir build
cd build
../configure --prefix=/opt/loongarch64/toolchain --target=x86_64-linux-gnu --disable-nls --enable-shared --enable-64-bit-bfd --disable-werror
make -j12 && make install

rm ./* -rf
../configure --prefix=/opt/loongarch64/toolchain --target=loongarch64-linux-gnu --with-sysroot --disable-nls --enable-shared --enable-64-bit-bfd --disable-werror
make -j12 && make install