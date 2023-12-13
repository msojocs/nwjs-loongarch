#!/bin/bash
root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

src_dir="$root_dir/nwjs/src"
output_dir="$root_dir/output"

cd "$src_dir"
mkdir -p "$output_dir/dist_nwjs/"{simple, sdk}

notice "Start to pack"
python content/nw/tools/package_binaries.py -p out/nw -a loong64 -n symbol
mv "out/nw/dist/"* "$output_dir/dist_nwjs"

notice "Start to pack SDK"
python content/nw/tools/package_binaries.py -p out/nw -a loong64 -n symbol -m sdk
mv "out/nw/dist/"* "$output_dir/dist_nwjs"