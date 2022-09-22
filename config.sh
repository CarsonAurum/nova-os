SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"

export CC_PREFIX=${HOME}/opt/cross/bin/

export MAKE=${MAKE:-make}
export HOST=${HOST:-$(./default-host.sh)}

export AR=${CC_PREFIX}${HOST}-ar
export AS=${CC_PREFIX}${HOST}-as
export CC=${CC_PREFIX}${HOST}-gcc

export PREFIX=/usr
export EXEC_PREFIX=$PREFIX
export BOOTDIR=/boot
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

export CFLAGS='-O2 -g'
export CPPFLAGS=''

# Configure the cross-compiler to use the desired system root.
export SYSROOT="$(pwd)/sysroot"
export CC="$CC --sysroot=$SYSROOT"

# Work around that the -elf gcc targets doesn't have a system include directory
# because it was configured with --without-headers rather than --with-sysroot.
if echo "$HOST" | grep -Eq -- '-elf($|-)'; then
  export CC="$CC -isystem=$INCLUDEDIR"
fi