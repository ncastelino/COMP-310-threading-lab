#!/bin/sh

declare -a TIMES=();


for a in {1..100}
do
    TIMES+=(`./vector | cut -f 8 -d' '`);
done

sum=0.0;
for t in ${TIMES[@]}
do
    sum=`echo "$t+$sum" | bc`;
done

echo "scale=2; $sum/100.0" | bc;
