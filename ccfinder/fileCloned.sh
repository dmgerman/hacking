#!/bin/bash -e

rm -f sortedClonePairs.txt fileclones.txt files.txt clonepairs.txt

ccfinder P $1 | printClones.pl

sort -n -t ';' -k1 -k3 -k5 -k7 -k2 -k4 -k6 -k8 clonepairs.txt  > sortedClonePairs.txt

simplify.pl sortedClonePairs.txt | sort -n -k 1,1 > fileclones.txt
sort -n -k 1,1 -t ';' files.txt > sortedFiles.txt

rm -f sortedClonePairs.txt

~/bin/myjoin.pl sortedFiles.txt fileclones.txt | computeFileClonedProp.pl | sort -n -k 3 -t ';'




