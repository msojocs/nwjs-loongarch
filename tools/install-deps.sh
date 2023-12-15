#!/bin/bash
sudo apt update
sudo apt install -y libmpc-dev texinfo bison flex
sudo apt install -y ninja-build python3
sudo apt install -y xz-utils python curl libcups2-dev libglib2.0-dev \
libnss3-dev \
libxkbcommon-dev \
libdrm-dev \
libgbm-dev \
libpango1.0-dev \
libdbus-1-dev \
gperf \
libx11-xcb-dev \
libkrb5-dev
sudo apt install -y gcc-multilib g++-multilib