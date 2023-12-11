#!/bin/bash
set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)

export PATH=$PATH:/opt/loongarch64/toolchain/bin:$root_dir/cmake-3.20.5-linux-x86_64/bin:$root_dir/depot_tools

cd $root_dir
cd depot_tools
./update_depot_tools