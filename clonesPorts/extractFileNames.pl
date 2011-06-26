#!/usr/bin/perl

while (<>) {
    chomp;
    die "illegal record $_" unless 
        /^entry\(path=(.*), group=/; #)/;
    print "$1\n";
}
