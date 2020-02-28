#!/usr/bin/env bash

loops=(1000000 10000000 100000000)
opts=(-O0 -O2 -O3)
src_proc=./src/whetstone.c
bin_proc=./bin/whetdc
num_repeats=3
LOG_FILE=log2.txt


for opt in ${opts[@]}; do
    gcc $opt $src_proc -o $bin_proc $opt -lm
    for loop in ${loops[*]};  do
        echo $opt $loop ":" | tee -a $LOG_FILE
        for ((i=1; i<=$num_repeats; i ++)) do
            $bin_proc $loop  | tee -a $LOG_FILE
        done
    done
done