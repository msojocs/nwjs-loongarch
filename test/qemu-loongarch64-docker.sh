#!/bin/bash
set -ex

root_dir=$(cd `dirname $0`/.. && pwd -P)

docker run --rm --privileged loongcr.lcpu.dev/multiarch/archlinux --reset -p yes
# apt update && apt install -y gdb build-essential libncurses-dev
# apt install libnss3-dev libatk1.0-dev libcups2-dev libxkbcommon-dev libxcomposite-dev libxdamage-dev libxrandr-dev libpango1.0-dev libdrm-dev libgbm-dev libasound2-data libasound2-dev
container_name="loongarchlinux-test"
# 检查docker image是否存在
if [ ! "$(docker images -q loongarchlinux-test-image 2> /dev/null)" ]; then
    $root_dir/test/build-image.sh
fi
# 检查docker 容器是否存在
if [ "$(docker ps -a | grep $container_name)" ]; then
    docker start $container_name
    # docker exec -it $container_name bash -c "ls -al ~/.config && rm -rf ~/.config/* && /workspace/source-code/nwjs/src/out/nw/nw --disable-gpu --no-sandbox"
    docker exec -it "$container_name" "$@"
    # gdb --args /workspace/output/dist_nwjs/nwjs-v0.94.1-linux-loong64/nw --disable-seccomp-sandbox http://google.com
else
    docker run -it \
        --name "$container_name" \
        --platform="linux/loong64" \
        --env="DISPLAY" \
        --volume="${XAUTHORITY:-${HOME}/.Xauthority}:/root/.Xauthority:ro" \
        --volume="/tmp/.X11-unix:/tmp/.X11-unix:ro" \
        -v "$root_dir":/workspace \
        -w /workspace \
        loongarchlinux-test-image:latest \
        bash -c "pacman -Syu --noconfirm nss atk cups libxkbcommon libxcomposite libxdamage libxrandr pango alsa-lib mesa libdrm && bash"
fi
# pacman -Sy --noconfirm mesa nss atk cups libxkbcommon libxcomposite libxdamage libxrandr pango alsa-lib