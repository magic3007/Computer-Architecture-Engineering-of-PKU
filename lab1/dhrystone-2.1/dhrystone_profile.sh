#!/usr/bin/env bash

loops=(100000000 300000000 500000000 700000000 900000000)
programs=(./gcc_dry2 ./gcc_dry2reg)
num_repeats=3
LOG_FILE=log.txt


for prog in ${programs[@]}; do
    for loop in ${loops[*]};  do
        echo $prog $loop ":" | tee -a $LOG_FILE
        for ((i=1; i<=$num_repeats; i ++)) do
            time (echo "      Epoch " $i ":" $(echo $loop | $prog | grep "Dhrystones per Second:" | tr -cd "[0-9.]")  | tee -a $LOG_FILE)
            
        done
    done
done