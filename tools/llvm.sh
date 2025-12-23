#!/bin/bash
set -ex

root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

max_thread=$(($(cat /proc/cpuinfo| grep "processor"| wc -l) - 6))
export JOBS=$max_thread

source_dir="$root_dir/source-code"
project_dir="$source_dir/llvm-project"
build_dir="$project_dir/build"
output_dir="$root_dir/output"

llvm_version=$(node $root_dir/tools/parse-config.js --get-llvm-version $@)
llvm_tag=$(node $root_dir/tools/parse-config.js --get-llvm-tag $@)
llvm_repo=$(node $root_dir/tools/parse-config.js --get-llvm-repo $@)
llvm_build_arg=$(node $root_dir/tools/parse-config.js --get-llvm-build-arg $@)
rt_build_arg=$(node $root_dir/tools/parse-config.js --get-llvm-rt-build-arg $@)
export PATH=$output_dir/toolchain/bin:$output_dir/cmake-linux-x86_64/bin:$PATH
llvm_dir="$output_dir/llvm-$llvm_version"

notice "检查llvm项目是否存在"
if [ ! -d "$project_dir" ]; then
  notice "请确保阁下的网络稳定快速"
  notice "llvm-project not cloned, start to clone......"
  cd "$source_dir"
  git clone $llvm_repo
fi

notice "检查llvm项目是否拉取成功"
if [ ! -f "$project_dir/README.md" ];then
  fail "README文件不存在，llvm源码拉取失败"
  exit 1
fi

cd "$source_dir/llvm-project"
# 检查是否merge状态
if [ "$(git status --porcelain)" != "" ]; then
  warn "llvm项目处于未提交状态，自动恢复到最新tag状态"
  git reset --hard HEAD
fi
git fetch origin $llvm_tag
git checkout $llvm_tag --force

mkdir -p $build_dir
mkdir -p $project_dir/build-compiler-rt

notice "Start to make llvm"
if [ ! -f "$llvm_dir/lib/cmake/llvm/LLVMConfigExtensions.cmake" ];then
  cd $project_dir
  cmake -S llvm -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$llvm_dir $llvm_build_arg
  cd "$build_dir"
  ninja -j$max_thread && ninja install
fi

if [ ! -f "$llvm_dir/lib/clang/$llvm_version/lib/loongarch64-unknown-linux-gnu/libclang_rt.profile.a" ];then
  cd $project_dir/build-compiler-rt
  rm ./* -rf
  notice "cmake for loongarch64-unknown-linux-gnu"
  cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=$llvm_dir/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=$source_dir/sysroot" -DCMAKE_C_COMPILER=$llvm_dir/bin/clang -DCMAKE_C_COMPILER_TARGET=loongarch64-unknown-linux-gnu -DCMAKE_C_FLAGS="-mcmodel=medium -mabi=lp64d --target=loongarch64-linux-gnu --sysroot=$source_dir/sysroot" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=$llvm_dir/bin/llvm-nm -DCMAKE_RANLIB=$llvm_dir/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=$llvm_dir -DCMAKE_INSTALL_PREFIX=$llvm_dir/lib/clang/$llvm_version $rt_build_arg
  ninja -j$max_thread && ninja install
fi

if [ ! -f "$llvm_dir/lib/clang/$llvm_version/lib/x86_64-unknown-linux-gnu/liborc_rt.a" ];then
  cd $project_dir/build-compiler-rt
  rm ./* -rf
  notice "cmake for x86_64-unknown-linux-gnu"
  cmake ../compiler-rt/ -G Ninja -DCMAKE_AR=$llvm_dir/bin/llvm-ar -DCMAKE_ASM_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_ASM_FLAGS="" -DCMAKE_C_COMPILER=$llvm_dir/bin/clang -DCMAKE_C_COMPILER_TARGET=x86_64-unknown-linux-gnu -DCMAKE_C_FLAGS="" -DLLVM_ENABLE_PER_TARGET_RUNTIME_DIR=ON -DCMAKE_NM=$llvm_dir/bin/llvm-nm -DCMAKE_RANLIB=$llvm_dir/bin/llvm-ranlib  -DCOMPILER_RT_BUILD_BUILTINS=ON -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_MEMPROF=OFF -DCOMPILER_RT_BUILD_PROFILE=ON -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_DEFAULT_TARGET_ONLY=ON -DLLVM_CMAKE_DIR=$llvm_dir -DCMAKE_INSTALL_PREFIX=$llvm_dir/lib/clang/$llvm_version $rt_build_arg
  ninja -j$max_thread && ninja install
fi