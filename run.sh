#!/bin/bash

export CC=gcc

if [ -d "./build" ]; then 
	rm -rf ./build;
fi

mkdir build && cd build
cmake3 ..
cmake3 --build .

for i in ./main_A.* ./main_B.* ./main_AB.*; do echo "$i:"; LD_LIBRARY_PATH=./A:./B:$LD_LIBRARY_PATH $i; done
