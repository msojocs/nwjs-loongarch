#!/bin/bash
set -e

success() {
  echo -e "\033[42;37m 成功 \033[0m $1"
}
notice() {
  echo -e "\033[36m $1 \033[0m "
}
error() {
  echo -e "\033[41;37m 失败 \033[0m $1"
}

root_dir=$(cd `dirname $0`/.. && pwd -P)
output_dir="$root_dir/output"

export PATH=$PATH:$output_dir/depot_tools
if [ ! -d "$output_dir/depot_tools" ];then
  cd $output_dir
  git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
fi
if [ -d "$output_dir/depot_tools" ];then
  cd $output_dir/depot_tools
  ./update_depot_tools
else
  error "depot_tools 拉取失败！"
fi