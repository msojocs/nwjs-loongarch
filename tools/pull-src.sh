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

nw_version=$(node $root_dir/tools/parse-config.js --get-nw-version $@)

export NO_AUTH_BOTO_CONFIG="$root_dir/config/.boto"
output_dir="$root_dir/output"
source_dir="$root_dir/source-code"
nwjs_dir="$source_dir/nwjs"
src_dir="$nwjs_dir/src"
export PATH=$output_dir/toolchain/bin:$output_dir/cmake-linux-x86_64/bin:$output_dir/depot_tools:$PATH

# git 地址
chromium_repo=$(node $root_dir/tools/parse-config.js --get-chromium-repo $@)
chromium_checkout_target=$(node $root_dir/tools/parse-config.js --get-chromium-checkout-target $@)
v8_repo=$(node $root_dir/tools/parse-config.js --get-v8-repo $@)
v8_checkout_target=$(node $root_dir/tools/parse-config.js --get-v8-checkout-target $@)
node_repo=$(node $root_dir/tools/parse-config.js --get-node-repo $@)
node_checkout_target=$(node $root_dir/tools/parse-config.js --get-node-checkout-target $@)
nw_repo=$(node $root_dir/tools/parse-config.js --get-nw-repo $@)
nw_checkout_target=$(node $root_dir/tools/parse-config.js --get-nw-checkout-target $@)

# 拉取源代码
mkdir -p "$nwjs_dir"
cd $nwjs_dir
gclient config --name=src $chromium_repo@$chromium_checkout_target

node $root_dir/tools/modify-gclient-config.js

notice "pull v8 with target: $v8_checkout_target"
if [ ! -f "$nwjs_dir/src/v8/README.md" ];then
  cd "$nwjs_dir"
  git clone $v8_repo src/v8
else
  cd "$nwjs_dir/src/v8" && git checkout $v8_checkout_target --force
fi

notice "pull node-nw with target: $node_checkout_target"
if [ ! -d "$nwjs_dir/src/third_party/node-nw" ];then
  cd "$nwjs_dir"
  git clone $node_repo src/third_party/node-nw
else
  cd "$nwjs_dir/src/third_party/node-nw" && git checkout $node_checkout_target --force
fi

notice "pull nw with target: $nw_checkout_target"
if [ ! -d "$nwjs_dir/src/content/nw" ];then
  cd "$nwjs_dir"
  git clone "$nw_repo" src/content/nw
else
  cd "$nwjs_dir/src/content/nw"
  git remote set-url origin "$nw_repo"
  git reset --hard HEAD~2
  git pull origin $nw_checkout_target
  git checkout $nw_checkout_target --force
fi

if [ -f "$nwjs_dir/src/README.md" ];then
  cd "$nwjs_dir/src"
  git fetch origin $chromium_checkout_target
  git checkout $chromium_checkout_target --force
fi

"$root_dir/tools/sync-reset.sh"
notice "Start to sync..."
if read -t 60 -p "execute 'gclient sync -D'? (Y/N):" name    # -t，设置输入超时时间（本语句设置超时时间为5秒），默认单位是秒；-p，指定输入提示
then                                              # 如果不超过5秒
  if [ "y" = "$name" ] || [ "Y" = "$name" ];then
    gclient sync -D --force
    exit 0
  fi
else                                              # 超过5秒
    echo "Timeout"
fi
gclient sync --with_branch_heads
"$root_dir/tools/sync-reset.sh"
gclient sync --with_branch_heads