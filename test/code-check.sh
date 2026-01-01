#!/bin/bash

set -e

root_dir=$(cd `dirname $0`/.. && pwd -P)
cd $root_dir/source-code/nwjs/src
code .
code v8
code third_party/node-nw
code content/nw
