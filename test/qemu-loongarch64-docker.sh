#!/bin/bash

root_dir=$(cd `dirname $0`/.. && pwd -P)

docker run --rm --privileged loongcr.lcpu.dev/multiarch/archlinux --reset -p yes
# 检查docker 容器是否存在
if [ "$(docker ps -a | grep loongarchlinux-test)" ]; then
    docker start loongarchlinux-test
    cd $root_dir/output/dist_nwjs
    tar -zxf nwjs-v0.100.1-linux-loong64.tar.gz
    docker exec -it loongarchlinux-test source-code/nwjs/src/out/nw/nw --disable-gpu --no-sandbox
else
    docker run -it \
        --name loongarchlinux-test \
        --platform="linux/loong64" \
        --env="DISPLAY" \
        --volume="${XAUTHORITY:-${HOME}/.Xauthority}:/root/.Xauthority:ro" \
        --volume="/tmp/.X11-unix:/tmp/.X11-unix:ro" \
        -v "$root_dir":/workspace \
        -w /workspace \
        ghcr.io/loongarchlinux/archlinux:latest \
        bash
fi
# pacman -S --noconfirm nss atk cups libxkbcommon libxcomposite libxdamage libxrandr pango alsa-lib