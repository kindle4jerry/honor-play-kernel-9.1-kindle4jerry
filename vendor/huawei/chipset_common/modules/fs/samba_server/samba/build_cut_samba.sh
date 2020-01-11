#!/bin/bash
git clone http://shagit80-rd.rnd.huawei.com/toolchain -b samba arm-linux-gnueabi
cd ./src
cp ../etc/Makefile ./Makefile
cp ../etc/config.h ./include/config.h
make
