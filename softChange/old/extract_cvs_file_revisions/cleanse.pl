#!/usr/bin/perl

use Strict;

while (<>) {
    chomp;
    s/[ \t]+//g;
    s/[{}]//g;
    s/\;/\;\n/g;
    print $_;
}


