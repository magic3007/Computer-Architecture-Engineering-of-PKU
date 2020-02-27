#!/usr/bin/env bash

loops=(1000000 10000000 100000000 1000000000)
programs=(./bin/whetdc)
num_repeats=3
LOG_FILE=log.txt


for prog in ${programs[@]}; do
    for loop in ${loops[*]};  do
        echo $prog $loop ":" | tee -a $LOG_FILE
        for ((i=1; i<=$num_repeats; i ++)) do
            echo "      Epoch " $i ":" $($prog $loop | grep "C Converted Double Precision Whetstones" | tr -cd "[0-9.]")  | tee -a $LOG_FILE
        done
    done
done