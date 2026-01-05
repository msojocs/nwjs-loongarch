#!/bin/bash
set -ex

root_dir=$(cd `dirname $0`/.. && pwd -P)

docker run --rm --privileged tonistiigi/binfmt:qemu-v9.2.2-52 --install all
# apt update && apt install -y gdb build-essential libncurses-dev
container_name="loongarchlinux-test"
# 检查docker 容器是否存在
if [ "$(docker ps -a | grep $container_name)" ]; then
    docker start $container_name
    cd $root_dir/output/dist_nwjs
    version="0.94.1"
    name="nwjs-sdk-v$version-linux-loong64"
    if [ ! -d "$name" ]; then
        tar -zxf $name.tar.gz
    fi
    docker exec -it $container_name bash -c "ls -al ~/.config && rm -rf ~/.config/* && /workspace/source-code/nwjs/src/out/nw/nw --disable-gpu"
    # docker exec -it $container_name /workspace/output/dist_nwjs/$name/nw --disable-gpu
    # gdb --args /workspace/output/dist_nwjs/nwjs-v0.94.1-linux-loong64/nw --disable-seccomp-sandbox http://google.com
else
    docker run -it \
        --name "$container_name" \
        --cap-add SYS_PTRACE \
        --security-opt seccomp=unconfined \
        --env="DISPLAY" \
        --volume="${XAUTHORITY:-${HOME}/.Xauthority}:/root/.Xauthority:ro" \
        --volume="/tmp/.X11-unix:/tmp/.X11-unix:ro" \
        -v "$root_dir":/workspace \
        -w /workspace \
        jiegec/loong64-debian:latest \
        bash
fi
# pacman -S --noconfirm nss atk cups libxkbcommon libxcomposite libxdamage libxrandr pango alsa-lib