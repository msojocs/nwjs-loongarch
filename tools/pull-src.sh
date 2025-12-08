#!/bin/bash
set -ex

root_dir=$(cd `dirname $0`/.. && pwd -P)
success() {
    echo -e "\033[42;37m 成功 \033[0m $1"
}
notice() {
    echo -e "\033[36m $1 \033[0m "
}
warn() {
    echo -e "\033[31m $1 \033[0m "
}
fail() {
    echo -e "\033[41;37m 失败 \033[0m $1"
}
trap 'catchError $LINENO "$BASH_COMMAND"' ERR # 捕获错误情况
catchError() {
  exit_code=$?
  fail "重置变更"
  # "$root_dir/tools/sync-reset.sh"
  # gclient sync -D
  "$root_dir/tools/sync-reset.sh"
  if [ $exit_code -ne 0 ]; then
      fail "\033[31mcommand: $2\n  at $0:$1\n  at $STEP\033[0m"
  fi
  exit $exit_code
}
source "$root_dir/config/nw-version.sh"
branch=$nw_version
notice "target branch: $branch"
export NO_AUTH_BOTO_CONFIG="$root_dir/config/.boto"
output_dir="$root_dir/output"
source_dir="$root_dir/source-code"
nwjs_dir="$source_dir/nwjs"
src_dir="$nwjs_dir/src"
export PATH=$output_dir/toolchain/bin:$output_dir/cmake-linux-x86_64/bin:$output_dir/depot_tools:$PATH

# git 地址
chromium_repo="https://github.com/nwjs/chromium.src.git"
v8_repo="https://github.com/nwjs/v8.git"
node_repo="https://github.com/nwjs/node.git"
nw_repo="https://github.com/loongson/nw.js.git"

chromium_repo="http://127.0.0.1:3000/msojocs/chromium.src.git"
v8_repo="http://127.0.0.1:3000/msojocs/v8.git"
node_repo="http://127.0.0.1:3000/msojocs/node.git"
nw_repo="http://127.0.0.1:3000/msojocs/nw.js.git"

# 拉取源代码
mkdir -p "$nwjs_dir"
cd $nwjs_dir
gclient config --name=src $chromium_repo@origin/$branch

notice "pull v8 with branch: $branch"
if [ ! -f "$nwjs_dir/src/v8/README.md" ];then
  cd "$nwjs_dir"
  git clone -b $branch $v8_repo src/v8
else
  cd "$nwjs_dir/src/v8" && git checkout $branch --force
fi

notice "pull node-nw with branch: $branch"
if [ ! -d "$nwjs_dir/src/third_party/node-nw" ];then
  cd "$nwjs_dir"
  git clone -b $branch $node_repo src/third_party/node-nw
else
  cd "$nwjs_dir/src/third_party/node-nw" && git checkout $branch --force
fi

notice "pull nw with branch: $branch"
if [ ! -d "$nwjs_dir/src/content/nw" ];then
  cd "$nwjs_dir"
  # git clone -b $branch https://github.com/nwjs/nw.js.git src/content/nw
  git clone -b $branch "$nw_repo" src/content/nw
else
  cd "$nwjs_dir/src/content/nw"
  git remote set-url origin "$nw_repo"
  git reset --hard HEAD~2
  git checkout -B $branch origin/$branch --force
  git pull
fi

if [ -f "$nwjs_dir/src/README.md" ];then
  cd "$nwjs_dir/src" && git checkout $branch --force
fi

notice "Start to sync..."
if read -t 60 -p "execute 'gclient sync -D'? (Y/N):" name    # -t，设置输入超时时间（本语句设置超时时间为5秒），默认单位是秒；-p，指定输入提示
then                                              # 如果不超过5秒
  if [ "y" = "$name" ] || [ "Y" = "$name" ];then
    "$root_dir/tools/sync-reset.sh"
    gclient sync -D
  fi
else                                              # 超过5秒
    echo "Timeout"
fi
gclient sync --with_branch_heads