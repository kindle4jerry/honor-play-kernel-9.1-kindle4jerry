#!/bin/bash
../arm-linux-gnueabi/bin/arm-linux-gnueabi-gcc --static -s -pthread --sysroot="../arm-linux-gnueabi/arm-linux-gnueabi/libc" -o arm_server server_test.c 
