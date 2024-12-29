#!/bin/sh

seq "$1" | while read number
do
    word=''
    [ $(($number % 3)) -eq 0 ] && word="${word}FIZZ";
    [ $(($number % 5)) -eq 0 ] && word="${word}BUZZ";
    echo "${word:-$number}"
done
