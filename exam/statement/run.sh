#!/bin/bash
# $1 for name
# $2 for problem
n=0; x=0;
g++ checker.cpp -g -o checker
for ((c = 1; ; c++)) do
  if (! find $c.in > /dev/null); then break; fi
  let "x = x + 1";
  timeout 2s ./$2 < $c.in > output.out 
  ./checker $c.in $c.out output.out answer.txt
  if diff -w answer.txt OK.txt > /dev/null ; then let "n = n + 1"; fi
  rm -rf answer.txt
done
rm -rf $2
echo $1 $2 $n $x >> /home/ll931110/gateway/OnlineJudge1.0/Scoreboard/ranklist.txt
