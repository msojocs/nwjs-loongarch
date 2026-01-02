#!/bin/bash
set -ex
default_dir=$(cd `dirname $0`/.. && pwd -P)

github_dir=$(cd `dirname $0`/../.. && pwd -P)
root_dir="$github_dir/nw93"

if [ ! -d "$root_dir/.git" ]; then
    git clone https://github.com/msojocs/nwjs-loongarch.git $root_dir
fi

cd $root_dir
mkdir -p source-code
cd source-code
ln -s $default_dir/source-code/binutils-gdb binutils-gdb
ln -s $default_dir/source-code/llvm-project llvm-project
ln -s $default_dir/source-code/sysroot sysroot

cd $root_dir
mkdir -p output
ln -s $default_dir/output/* $root_dir/output/
ln -s $default_dir/output/.ccache $root_dir/output/.ccache
