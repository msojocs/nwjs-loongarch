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

export PATH=$PATH:$root_dir/toolchain/bin:$root_dir/cmake-3.20.5-linux-x86_64/bin

if [ ! -d "$root_dir/llvm-project" ]; then
  notice "llvm-project not cloned, start to clone......"
  git clone https://github.com/llvm/llvm-project.git
fi

project_dir="$root_dir/llvm-project"
build_dir="$root_dir/llvm-project/build"
output_dir="$root_dir/output"
llvm_dir="$output_dir/llvm-18"

mkdir -p $build_dir
mkdir -p $project_dir/build-compiler-rt

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
  cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=$llvm_dir/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=/opt/loongarch64/sysroot" -DCMAKE_C_COMPILER=$llvm_dir/bin/clang -DCMAKE_C_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_C_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=/opt/loongarch64/sysroot" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=$llvm_dir/bin/llvm-nm -DCMAKE_RANLIB=$llvm_dir/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON  -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=$llvm_dir -DCMAKE_INSTALL_PREFIX=$llvm_dir/lib/clang/18
  ninja -j12 && ninja install
fi

if [ ! -f "$llvm_dir/lib/clang/18/lib/x86_64-unknown-linux-gnu/liborc_rt.a" ];then
  cd $project_dir/build-compiler-rt
  rm ./* -rf
  notice "cmake for x86_64-unknown-linux-gnu"
  cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=$llvm_dir/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="" -DCMAKE_C_COMPILER=$llvm_dir/bin/clang -DCMAKE_C_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_C_FLAGS="" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=$llvm_dir/bin/llvm-nm -DCMAKE_RANLIB=$llvm_dir/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON  -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=$llvm_dir -DCMAKE_INSTALL_PREFIX=$llvm_dir/lib/clang/18
  ninja -j$max_thread && ninja install
fi