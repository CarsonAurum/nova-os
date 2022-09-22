#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/nova.kernel isodir/boot/nova.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "nova" {
	multiboot /boot/nova.kernel
}
EOF
grub-mkrescue -o nova.iso isodir
