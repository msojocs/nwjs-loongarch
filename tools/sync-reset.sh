#!/bin/bash
set -e

success() {
    echo -e "\033[42;37m 成功 \033[0m $1"
}
notice() {
    echo -e "\033[36m $1 \033[0m "
}
fail() {
    echo -e "\033[41;37m 失败 \033[0m $1"
}

root_dir=$(cd `dirname $0`/.. && pwd -P)

source_dir="$root_dir/source-code"
nwjs_dir="$source_dir/nwjs"
dirs=("src/third_party/boringssl/src" "src/third_party/devtools-frontend/src" "src/third_party/ffmpeg" "src/third_party/icu" "src/third_party/lss" "src/third_party/webdriver/pylib" "src/third_party/swiftshader" "src/tools/gyp")
for dir in ${dirs[@]};
do
  target_dir="$nwjs_dir/$dir"
  notice "clean: $target_dir"
  cd $target_dir && git checkout . && git clean -xdf
done