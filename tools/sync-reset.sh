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
dirs=("src"
"src/third_party/boringssl/src"
"src/third_party/devtools-frontend/src"
"src/third_party/ffmpeg"
"src/third_party/icu"
"src/third_party/lss"
"src/third_party/webdriver/pylib"
"src/third_party/swiftshader"
"src/third_party/angle/third_party/VK-GL-CTS/src"
"src/third_party/breakpad/breakpad"
"src/third_party/catapult"
"src/third_party/dawn"
"src/third_party/dawn/third_party/webgpu-cts"
"src/third_party/dawn/third_party/webgpu-headers"
"src/third_party/perfetto"
"src/third_party/skia"
"src/third_party/vulkan-deps/vulkan-validation-layers/src"
"src/third_party/wayland/src"
"src/third_party/webrtc"
"src/third_party/xnnpack/src"
"src/tools/gyp"
)
for dir in ${dirs[@]};
do
  target_dir="$nwjs_dir/$dir"
  if [ -d "$target_dir" ];then
    notice "clean: $target_dir"
    cd $target_dir && git checkout . && git clean -xdf
  else
    notice "skip: $target_dir"
  fi
done