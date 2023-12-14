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
trap 'catchError $LINENO "$BASH_COMMAND"' ERR # 捕获错误情况
catchError() {
  exit_code=$?
  fail "重置变更"
  "$root_dir/tools/sync-reset.sh"
  if [ $exit_code -ne 0 ]; then
      fail "\033[31mcommand: $2\n  at $0:$1\n  at $STEP\033[0m"
  fi
  exit $exit_code
}
branch=$1
if [ -z "$branch" ];then
  branch="nw80"
fi
notice "target branch: $branch"
export NO_AUTH_BOTO_CONFIG="$root_dir/config/.boto"
output_dir="$root_dir/output"
nwjs_dir="$root_dir/nwjs"
src_dir="$nwjs_dir/src"
export PATH=$PATH:$output_dir/toolchain/bin:$output_dir/cmake-3.20.5-linux-x86_64/bin:$output_dir/depot_tools

# 拉取源代码
mkdir -p "$nwjs_dir"
cd $nwjs_dir
gclient config --name=src https://github.com/nwjs/chromium.src.git@origin/nw80

notice "pull v8 with branch: $branch"
if [ ! -d "$nwjs_dir/src/v8" ];then
  git clone -b $branch https://github.com/nwjs/v8.git src/v8
else
  cd "$nwjs_dir/src/v8" && git checkout $branch --force
fi

notice "pull node-nw with branch: $branch"
if [ ! -d "$nwjs_dir/src/third_party/node-nw" ];then
  git clone -b $branch https://github.com/nwjs/node.git src/third_party/node-nw
else
  cd "$nwjs_dir/src/third_party/node-nw" && git checkout $branch --force
fi

notice "pull nw with branch: $branch"
if [ ! -d "$nwjs_dir/src/content/nw" ];then
  git clone -b $branch https://github.com/loongson/nw.js.git src/content/nw
else
  cd "$nwjs_dir/src/content/nw" && git checkout $branch --force
fi

gclient sync --with_branch_heads