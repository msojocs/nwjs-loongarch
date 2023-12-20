#!/bin/bash
set -e
root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

src_dir="$root_dir/source-code"
src_dir="$src_dir/nwjs/src"
output_dir="$root_dir/output"

cd "$src_dir"
mkdir -p "$output_dir/dist_nwjs/"{simple,sdk}

notice "Start to pack"
python content/nw/tools/package_binaries.py -p out/nw -a loong64 -n symbol
mv "out/nw/dist/"* "$output_dir/dist_nwjs/simple"

notice "Start to pack SDK"
python content/nw/tools/package_binaries.py -p out/nw -a loong64 -n symbol -m sdk
mv "out/nw/dist/"* "$output_dir/dist_nwjs/sdk"

> "$output_dir/dist_nwjs/SHASUMS256.txt"
cat "$output_dir/dist_nwjs/simple/SHASUMS256.txt" >> "$output_dir/dist_nwjs/SHASUMS256.txt"
cat "$output_dir/dist_nwjs/sdk/SHASUMS256.txt" >> "$output_dir/dist_nwjs/SHASUMS256.txt"

mv "$output_dir/dist_nwjs/simple/nwjs"* "$output_dir/dist_nwjs"
mv "$output_dir/dist_nwjs/sdk/nwjs"* "$output_dir/dist_nwjs"
mv "$output_dir/dist_nwjs/sdk/nw-"* "$output_dir/dist_nwjs"

rm -rf "$output_dir/dist_nwjs/simple" "$output_dir/dist_nwjs/sdk"