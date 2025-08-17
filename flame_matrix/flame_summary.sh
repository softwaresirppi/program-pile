#!/usr/bin/env bash
# USAGE: builder.sh bois.cav gals.csv
delim=','
boisFile=$1
galsFile=$2
echo -n -e $delim
for gal in $(cat $galsFile)
do
	echo -n -e $gal$delim
done
for boi in $(cat $boisFile)
do
	echo -n -e '\n' $boi$delim
	for gal in $(cat $galsFile)
	do
		echo -n -e $(echo "$boi $gal" | flames.o)$delim
	done
done
