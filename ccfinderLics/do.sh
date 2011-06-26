#!/bin/bash

perl ~/w/hacking/ccfinderLics/simple.pl $1 | perl ~/w/hacking/ccfinderLics/linearize.pl > $1.linear
