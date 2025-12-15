#!/bin/bash

success() {
    echo -e "\033[42;37m 成功 \033[0m $1"
}
notice() {
    echo -e "\033[36m $1 \033[0m "
}
fail() {
    echo -e "\033[41;37m 失败 \033[0m $1"
}
warn() {
    echo -e "\033[31m $1 \033[0m "
}
git_clone() {
    num=1
    while [ $num -le 2000 ]; do
        git fetch $1
        if [ $? -ne 0 ]; then
            num=$(($num+1))
        else
            break
        fi
    done
    git checkout FETCH_HEAD
    git remote add origin $1
    git pull origin main
    git checkout main
}