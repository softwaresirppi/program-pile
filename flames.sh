#!/bin/sh
boy=$1
girl=$2
letters=$(
    echo "$boy$girl" |
    fold -w1 |
    sort |
    uniq |
    wc -l
)
strike_out() {
    if [ "$1" -eq 1 ]
    then echo 0
    else echo "$(( ($(strike_out $(($1 - 1)) "$2") + $2) % $1 ))"
    fi
}
set -- Friend Lover Affection Marriage Enemy Sister
eval echo \$"$(($(strike_out 6 "$letters") + 1))"
