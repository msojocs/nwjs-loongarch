#!/bin/bash
set -ex
root_dir=$(cd `dirname $0`/.. && pwd -P)

name="$1"
cd $root_dir/output/dist_nwjs/$name
if [ ! -d nwjs-sdk-*-linux-loong64 ]; then
    tar -zxf nwjs-sdk-*-linux-loong64.tar.gz
fi
$root_dir/test/qemu-loongarch64-docker.sh output/dist_nwjs/$name/nwjs-sdk-*-linux-loong64/nw --disable-gpu --no-sandbox