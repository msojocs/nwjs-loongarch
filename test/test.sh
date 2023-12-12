#!/bin/bash

set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)

if [ ! -d "$root_dir/binutils-gdb" ]; then
  echo "not found"
else
  echo "found"
fi