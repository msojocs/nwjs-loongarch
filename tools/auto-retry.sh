#!/bin/bash

root_dir=$(cd `dirname $0`/.. && pwd -P)

# 循环50次执行命令，直到成功为止
for i in $(seq 1 50); do
    echo "Attempt $i: Running command..."
    # 在这里替换为你想要执行的命令
    bash "$root_dir/tools/setup.sh"
    if [ $? -eq 0 ]; then
        echo "Command succeeded on attempt $i."
        exit 0
    else
        echo "Command failed on attempt $i. Retrying..."
        sleep 1  # 可选：等待1秒后重试
    fi
done