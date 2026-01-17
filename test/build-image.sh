#!/bin/bash

root_dir=$(cd `dirname $0`/.. && pwd -P)

docker run --rm --privileged loongcr.lcpu.dev/multiarch/archlinux --reset -p yes

cd $root_dir/test
docker build --platform=linux/loong64 -t loongarchlinux-test-image .