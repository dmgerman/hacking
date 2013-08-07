#!/bin/bash

grep ";$1;" restaurantsVictoria.txt | cut -d ';' -f 1 | lynx -dump - > data/$1.TXT

