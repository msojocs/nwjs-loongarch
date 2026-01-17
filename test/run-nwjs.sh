#!/bin/bash
set -ex
root_dir=$(cd `dirname $0`/.. && pwd -P)

version="0.92.1"
if [ ! -z "$1" ]; then
    version="$1"
fi
cd $root_dir/output/dist_nwjs
name="nwjs-sdk-v$version-linux-loong64"
if [ ! -d "$name" ]; then
    tar -zxf $name.tar.gz
fi
$root_dir/test/qemu-loongarch64-docker.sh output/dist_nwjs/$name/nw --disable-gpu --no-sandbox