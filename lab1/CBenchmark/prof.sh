#!/usr/bin/env bash


if [[ "$1" == "quick_sort" || "$1" == "gemm" ||  "$1" == "ackermann" ]]; then
    mkdir build
    cd build
    cmake ..
    make -j$(nproc) $1
    echo  ./bin/"$@"
    ./bin/"$@"
else
    echo "Usage: $0 <gemm|quick_sort|ackermann> <...params>"
    echo "          $0 gemm <N> <K> <M>"
    echo "          $0 quick_sort <N>"
    echo "          $0 ackermann <m> <n>"
fi