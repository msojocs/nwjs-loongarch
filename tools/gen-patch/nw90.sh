#!/bin/bash
set -ex

root_dir=$(cd `dirname $0`/../.. && pwd -P)
function gen_patch {
    git diff $1 > $root_dir/patch/nw90/$2.patch
}

gen_patch "source-code/nwjs/src/build/config/linux/libffi/BUILD.gn" libffi