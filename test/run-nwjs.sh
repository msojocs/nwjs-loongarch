#!/bin/bash
set -ex
root_dir=$(cd `dirname $0`/.. && pwd -P)

name="$1"
cd "$root_dir/output/dist_nwjs/$name"

# Use a safe glob check: if no matching dir, extract the tarball.
# Handle multiple matches by taking the first one.
shopt -s nullglob
matches=(nwjs-sdk-*-linux-loong64)
if [ ${#matches[@]} -eq 0 ]; then
    tar -zxf nwjs-sdk-*-linux-loong64.tar.gz
    matches=(nwjs-sdk-*-linux-loong64)
fi
shopt -u nullglob
dir="${matches[0]}"

"$root_dir/test/qemu-loongarch64-docker.sh" "output/dist_nwjs/$name/$dir/nw" --disable-gpu --no-sandbox