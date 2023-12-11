#!/bin/bash
mkdir -p /opt/loongarch64/sysroot/usr
mkdir ./sysroot
mount clfs-loongarch64-system-8.1-sysroot.squashfs ./sysroot
cp -raf ./sysroot/usr/include ./sysroot/usr/lib ./sysroot/usr/lib64 \
        ./sysroot/usr/share /opt/loongarch64/sysroot/usr
cp -raf ./sysroot/lib ./sysroot/lib64 /opt/loongarch64/sysroot/
umount ./sysroot