#!/bin/bash

rm -rf ./build
mkdir build
cd $(pwd)/build
cmake ..
make -j
