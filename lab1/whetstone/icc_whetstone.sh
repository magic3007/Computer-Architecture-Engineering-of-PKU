#!/usr/bin/env bash

loops=(1000000 10000000 100000000 1000000000)
bin_proc=./icc_whetstone
num_repeats=3
LOG_FILE=log_icc.txt


for loop in ${loops[*]};  do
    echo "icc -O3" $loop ":" | tee -a $LOG_FILE
    for ((i=1; i<=$num_repeats; i ++)) do
        $bin_proc $loop  | tee -a $LOG_FILE
    done
done
