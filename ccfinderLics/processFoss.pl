#!/usr/bin/perl

while (<>){
    chomp;
    if (-f) {
        next if $_ =~ /meta$/;
        print "$_\n";
        print `perl simple.pl '$_'`
    }
}
