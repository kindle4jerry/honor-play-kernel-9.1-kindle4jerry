#!/bin/bash
cd ./src
make clean
cp ../etc/Makefile ./Makefile
cp ../etc/config.h ./include/config.h
make
