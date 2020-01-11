#!/bin/bash
CROSS_COMPILE=../arm-linux-gnueabi
RUNTIME_DIR=/data/samba_server

git clone http://shagit80-rd.rnd.huawei.com/toolchain -b samba arm-linux-gnueabi
cd ./src
./autogen.sh

sed -n '/cannot run test program while cross compiling/{x;d;};1h;1!{x;p;};${x;p;}' configure > configure.replace
sed -n '/cannot run test program while cross compiling/{x;d;};1h;1!{x;p;};${x;p;}' configure.replace > configure
rm configure.replace
sed -i '/cannot run test program while cross compiling/,+1d' configure

./configure \
    CC="$CROSS_COMPILE"/bin/arm-linux-gnueabi-gcc \
    AR="$CROSS_COMPILE"/bin/arm-linux-gnueabi-ar \
    LD="$CROSS_COMPILE"/bin/arm-linux-gnueabi-ld \
    RANLIB="$CROSS_COMPILE"bin/arm-linux-gnueabi-ranlib \
    --host=arm-linux-gnueabi \
    --target=arm-linux-gnueabi \
    CFLAGS="--static -s -pthread --sysroot="$CROSS_COMPILE"/arm-linux-gnueabi/libc" \
    --without-krb5 \
    --without-ldap \
    --without-ads \
    --disable-cups \
    --with-winbind=no \
    --enable-socket-wrapper \
    --prefix=$RUNTIME_DIR \
    --with-configdir=$RUNTIME_DIR/etc \
    SMB_BUILD_CC_NEGATIVE_ENUM_VALUES=yes \
    libreplace_cv_READDIR_GETDIRENTRIES=no \
    libreplace_cv_READDIR_GETDENTS=no \
    linux_getgrouplist_ok=yes \
    samba_cv_REPLACE_READDIR=no \
    samba_cv_HAVE_WRFILE_KEYTAB=yes \
    samba_cv_HAVE_KERNEL_OPLOCKS_LINUX=yes \
    samba_cv_HAVE_IFACE_IFCONF=yes \
    samba_cv_USE_SETRESUID=yes \
    ac_cv_have_setresuid_decl=no \
    ac_cv_have_setresgid_decl=no

make clean
make
