## CMake
https://github.com/Kitware/CMake/releases?page=9

## binutil-gdb
```
apt install libmpc-dev
sudo apt-get install texinfo
apt install bison flex
```
## llvm-project
apt install ninja-build
apt install python3

## nwjs
```
./build/install-build-deps.sh
sudo apt install xz-utils python curl
sudo apt install libcups2-dev
sudo apt install libglib2.0-dev \
libnss3-dev \
libxkbcommon-dev \
libdrm-dev \
libgbm-dev \
libpango1.0-dev \
libdbus-1-dev \
gperf \
libx11-xcb-dev \
libkrb5-dev
```

修改：`nwjs/src/build/config/linux/libffi/BUILD.gn`:
```
config("libffi") {
  #libs = [ ":libffi_pic.a" ] # 注释掉
  libs = [ "ffi" ] # 新增一行
}
```

## ninja -C out/Release node

```
sudo apt-get install gcc-multilib g++-multilib
# cstring string 头文件缺失
export CPLUS_INCLUDE_PATH=/usr/include/x86_64-linux-gnu/c++/9/32:/usr/include/c++/9:$CPLUS_INCLUDE_PATH

export LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/9:$LIBRARY_PATH
```