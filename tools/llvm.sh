#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)

export PATH=$PATH:/opt/loongarch64/toolchain/bin:$root_dir/cmake-3.20.5-linux-x86_64/bin
# git clone https://github.com/llvm/llvm-project.git
project_dir="$root_dir/llvm-project"
build_dir="$root_dir/llvm-project/build"
# cd $project_dir
# cmake -S llvm -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang" -DCMAKE_INSTALL_PREFIX=/opt/loongarch64/llvm-18 -DLLVM_DEFAULT_TARGET_TRIPLE="x86_64-linux-gnu;loongarch64-linux-gnu"
# cd "$project_dir/build"
# ninja -j12 && ninja install

mkdir -p $project_dir/build-compiler-rt
cd $project_dir/build-compiler-rt
# cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=/opt/loongarch64/llvm-18/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=/opt/loongarch64/sysroot" -DCMAKE_C_COMPILER=/opt/loongarch64/llvm-18/bin/clang -DCMAKE_C_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_C_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=/opt/loongarch64/sysroot" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=/opt/loongarch64/llvm-18/bin/llvm-nm -DCMAKE_RANLIB=/opt/loongarch64/llvm-18/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON  -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=/opt/loongarch64/llvm-18 -DCMAKE_INSTALL_PREFIX=/opt/loongarch64/llvm-18/lib/clang/18
# ninja -j12 && ninja install
# rm ./* -rf
# exit 1
cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=/opt/loongarch64/llvm-18/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="" -DCMAKE_C_COMPILER=/opt/loongarch64/llvm-18/bin/clang -DCMAKE_C_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_C_FLAGS="" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=/opt/loongarch64/llvm-18/bin/llvm-nm -DCMAKE_RANLIB=/opt/loongarch64/llvm-18/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON  -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=/opt/loongarch64/llvm-18 -DCMAKE_INSTALL_PREFIX=/opt/loongarch64/llvm-18/lib/clang/18
ninja -j12 && ninja install