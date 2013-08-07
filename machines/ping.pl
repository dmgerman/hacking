#!/usr/bin/perl

foreach $a (1..255) {
    print "checking 192.168.1.$a\n";
    print `ping -c 2 192.168.1.$a`;
}
