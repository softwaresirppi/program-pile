N="$1"
echo BY PRINTF SEQ
time printf $'apple\n%.0s' $(seq "$N")
echo BY PRINTF YES
time printf $'apple\n%.0s' $(yes | head -n "$N")
echo BY FOR LOOP
time for i in $(seq "$N")
do echo 'apple'
done
echo BY WHILE LOOP
i=0
time while [ "$i" -lt "$N" ]
do echo 'apple'; i=$((i + 1));
done
