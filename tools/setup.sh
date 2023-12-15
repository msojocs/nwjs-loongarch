#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
tools_dir="$root_dir/tools"
source "$tools_dir/common/step.sh"

# cmake
if [ $CURRENT_STEP == $STEP_START ];then
  "$tools_dir/cmake.sh"
  step_switch $STEP_CMAKE_SUCCESS
fi

# binutils-gdb
if [ $CURRENT_STEP == $STEP_CMAKE_SUCCESS ];then
  "$tools_dir/binutils-gdb.sh"
  step_switch $STEP_GDB_SUCCESS
fi

# sysroot
if [ $CURRENT_STEP == $STEP_GDB_SUCCESS ];then
  "$tools_dir/sysroot.sh"
  step_switch $STEP_SYSROOT_SUCCESS
fi

# llvm build
if [ $CURRENT_STEP == $STEP_SYSROOT_SUCCESS ];then
  "$tools_dir/llvm.sh"
  step_switch $STEP_LLVM_SUCCESS
fi

# depot_tools
if [ $CURRENT_STEP == $STEP_LLVM_SUCCESS ];then
  "$tools_dir/depot-tools.sh"
  step_switch $STEP_DEPOT_TOOLS_SUCCESS
fi

# pull src
if [ $CURRENT_STEP == $STEP_DEPOT_TOOLS_SUCCESS ];then
  "$tools_dir/pull-src.sh"
  step_switch $STEP_PULL_SRC_SUCCESS
fi

# build prepare
if [ $CURRENT_STEP == $STEP_PULL_SRC_SUCCESS ];then
  "$tools_dir/build-prepare.sh"
  step_switch $STEP_BUILD_PREPARE_SUCCESS
fi

# build
if [ $CURRENT_STEP == $STEP_BUILD_PREPARE_SUCCESS ];then
  "$tools_dir/build-nwjs.sh"
  step_switch $STEP_BUILD_SUCCESS
fi

# pack
if [ $CURRENT_STEP == $STEP_BUILD_SUCCESS ];then
  "$tools_dir/pack.sh"
  step_switch $STEP_PACK_SUCCESS
fi
step_over