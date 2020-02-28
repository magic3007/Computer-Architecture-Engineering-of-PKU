#!/usr/bin/env bash

loops=(1000000 10000000 100000000)
programs=(./bin/whetdc)
num_repeats=1
LOG_FILE=log.txt


for prog in ${programs[@]}; do
    for loop in ${loops[*]};  do
        echo $prog $loop ":" | tee -a $LOG_FILE
        for ((i=1; i<=$num_repeats; i ++)) do
            $prog $loop  | tee -a $LOG_FILE
        done
    dones
done