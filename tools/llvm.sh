#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

max_thread=$(cat /proc/cpuinfo| grep "processor"| wc -l)
export JOBS=$max_thread

project_dir="$root_dir/llvm-project"
build_dir="$root_dir/llvm-project/build"
output_dir="$root_dir/output"
llvm_dir="$output_dir/llvm-18"
export PATH=$output_dir/toolchain/bin:$output_dir/cmake-3.20.5-linux-x86_64/bin:$PATH

notice "检查llvm项目是否存在"
if [ ! -d "$root_dir/llvm-project" ]; then
  notice "请确保阁下的网络稳定快速"
  notice "llvm-project not cloned, start to clone......"
  git clone -b llvmorg-17.0.6 https://github.com/llvm/llvm-project.git
fi

notice "检查llvm项目是否拉取成功"
if [ ! -f "$project_dir/README.md" ];then
  fail "README文件不存在，llvm源码拉取失败"
  exit 1
fi
mkdir -p $build_dir
mkdir -p $project_dir/build-compiler-rt

notice "Start to make llvm"
if [ ! -f "$llvm_dir/lib/cmake/llvm/LLVMConfigExtensions.cmake" ];then
  cd $project_dir
  cmake -S llvm -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang" -DCMAKE_INSTALL_PREFIX=$llvm_dir -DLLVM_DEFAULT_TARGET_TRIPLE="x86_64-linux-gnu;loongarch64-linux-gnu"
  cd "$build_dir"
  ninja -j$max_thread && ninja install
fi

if [ ! -f "$llvm_dir/lib/clang/18/lib/loongarch64-unknown-linux-gnu/libclang_rt.profile.a" ];then
  cd $project_dir/build-compiler-rt
  rm ./* -rf
  notice "cmake for loongarch64-unknown-linux-gnu"
  cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=$llvm_dir/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=$root_dir/sysroot" -DCMAKE_C_COMPILER=$llvm_dir/bin/clang -DCMAKE_C_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_C_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=$root_dir/sysroot" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=$llvm_dir/bin/llvm-nm -DCMAKE_RANLIB=$llvm_dir/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON  -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=$llvm_dir -DCMAKE_INSTALL_PREFIX=$llvm_dir/lib/clang/18
  ninja -j12 && ninja install
fi

if [ ! -f "$llvm_dir/lib/clang/18/lib/x86_64-unknown-linux-gnu/liborc_rt.a" ];then
  cd $project_dir/build-compiler-rt
  rm ./* -rf
  notice "cmake for x86_64-unknown-linux-gnu"
  cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=$llvm_dir/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="" -DCMAKE_C_COMPILER=$llvm_dir/bin/clang -DCMAKE_C_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_C_FLAGS="" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=$llvm_dir/bin/llvm-nm -DCMAKE_RANLIB=$llvm_dir/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON  -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=$llvm_dir -DCMAKE_INSTALL_PREFIX=$llvm_dir/lib/clang/18
  ninja -j$max_thread && ninja install
fi