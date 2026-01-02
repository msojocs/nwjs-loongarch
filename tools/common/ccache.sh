#!/bin/bash

if [ -z "$root_dir" ]; then
    root_dir=$(cd `dirname $0`/../.. && pwd -P)
fi
export CCACHE_DIR="$root_dir/output/.ccache" # 缓存目录
export CCACHE_MAXSIZE="100G"     # 缓存最大容量
export CCACHE_COMPRESSION="zstd" # 使用 zstd 压缩

ccache -s