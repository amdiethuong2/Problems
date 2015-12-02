#!/bin/bash
# $1 for name
# $2 for problem
n=0; x=0;
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  timeout 1s ./$2 < $c.in > output.out 
  if diff -w $c.out output.out > /dev/null ; then let "n = n + 1"; fi
done
echo $1 $2 $n $x >> /home/ll931110/gateway/OnlineJudge1.0/Scoreboard/ranklist.txt
