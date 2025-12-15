#!/bin/bash

_dir=$(cd `dirname $0`/.. && pwd -P)
mkdir -p "$_dir/tmp"
if [ -f "$_dir/tmp/.step" ];then
    CURRENT_STEP=`cat "$_dir/tmp/.step"`
    unset _dir
    if [ "$CURRENT_STEP" == "" ];then
        echo "default"
        CURRENT_STEP="STEP_START"
    fi
else
    CURRENT_STEP="STEP_START"
fi

STEP_START="STEP_START"
STEP_CMAKE_SUCCESS="STEP_CMAKE_SUCCESS"
STEP_GDB_SUCCESS="STEP_GDB_SUCCESS"
STEP_LLVM_SUCCESS="STEP_LLVM_SUCCESS"
STEP_DEPOT_TOOLS_SUCCESS="STEP_DEPOT_TOOLS_SUCCESS"
STEP_PULL_SRC_SUCCESS="STEP_PULL_SRC_SUCCESS"
STEP_DEPS_SUCCESS="STEP_DEPS_SUCCESS"
STEP_SYSROOT_SUCCESS="STEP_SYSROOT_SUCCESS"
STEP_BUILD_PREPARE_SUCCESS="STEP_BUILD_PREPARE_SUCCESS"
STEP_BUILD_SUCCESS="STEP_BUILD_SUCCESS"
STEP_PACK_SUCCESS="STEP_PACK_SUCCESS"


step_switch() {
    echo -e "\033[42;36m 切换步骤-> \033[0m $1"
    CURRENT_STEP=$1
    _dir=$(cd `dirname $0`/.. && pwd -P)
    echo -n "$1" > "$_dir/tmp/.step"
    unset _dir
}

step_error() {
    echo -e "\033[41;37m 步骤异常-> \033[0m $1 $2"
    step_switch $2
    CURRENT_STEP=$1
    exit
}

step_over() {
    _dir=$(cd `dirname $0`/.. && pwd -P)
    echo -n "" > "$_dir/tmp/.step"
    unset _dir
}