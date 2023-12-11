#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)

nwjs_dir="$root_dir/nwjs"
dirs=("src/third_party/boringssl/src" "src/third_party/devtools-frontend/src" "src/third_party/ffmpeg" "src/third_party/icu" "src/third_party/lss" "src/third_party/webdriver/pylib" "src/third_party/swiftshader" "src/tools/gyp")
for dir in ${dirs[@]};
do
  target_dir="$nwjs_dir/$dir"
  echo "clean: $target_dir"
  cd $target_dir && git checkout . && git clean -xdf
done