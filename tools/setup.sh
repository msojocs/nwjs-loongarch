#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
tools_dir="$root_dir/tools"

# cmake
"$tools_dir/cmake.sh"

# binutils-gdb
"$tools_dir/binutils-gdb.sh"

# llvm build
"$tools_dir/llvm.sh"

# depot_tools
"$tools_dir/depot-tools.sh"

# pull src
"$tools_dir/pull-src.sh"

# sysroot
"$tools_dir/sysroot.sh"

# build prepare
"$tools_dir/build-prepare.sh"

# build
"$tools_dir/build-nwjs.sh"

# pack
"$tools_dir/pack.sh"