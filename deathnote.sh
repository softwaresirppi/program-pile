#!/bin/bash
# COLORS goD DAMMIT
printf "\x1b[37;40;1m oof"
clear
trap "echo -e \"\nhow dare you -_-\"" INT

# Center print
printf '\n\n'
echo "DEATH N0TE" | while read -r text
do printf %*s $((($(tput cols) + $(echo $text | wc -c)) / 2)) "$text"
done
printf '\n\n\n'

# Notes
while read prog
do 
  if [ "$prog" != "\n" ]
  then 
    pkill -i $prog
  fi
done
