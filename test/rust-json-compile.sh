#!/bin/bash
set -ex
root_dir=$(cd `dirname $0`/.. && pwd -P)
src_dir="$root_dir/source-code/nwjs/src"
cd $src_dir

ninja -C out/nw test_serde_json_lenient -j2

$root_dir/test/qemu-loongarch64-docker.sh source-code/nwjs/src/out/nw/test_serde_json_lenient
# nw95 crash
# nw96 ok
# nw97 ok