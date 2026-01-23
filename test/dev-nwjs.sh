#!/bin/bash
set -ex
root_dir=$(cd `dirname $0`/.. && pwd -P)


"$root_dir/test/qemu-loongarch64-docker.sh" bash -c "rm -rf ~/.config && source-code/nwjs/src/out/nw/nw $@"