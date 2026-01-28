#!/bin/bash
set -ex
root_dir=$(cd `dirname $0`/.. && pwd -P)
src_dir="$root_dir/source-code/nwjs/src"
cd $src_dir

ninja -C out/nw blink_platform_unittests -j10

$root_dir/test/qemu-loongarch64-docker.sh source-code/nwjs/src/out/nw/blink_platform_unittests $@
