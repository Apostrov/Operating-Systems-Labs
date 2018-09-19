#!/bin/bash
while true; do
    if ln file file.lock
    then
        count=0
        while [[ $count != 1000 ]]; do
            count=$(($count + 1))
            n=`tail file -c 1`
            printf $(($n + 1)) >> file
        done
        rm file.lock
        break
    else
        sleep 1
    fi
done