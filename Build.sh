#! /bin/bash

mkdir -p Build

cmake -S . -B Build -G "Unix Makefiles" -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang
cd Build
make
