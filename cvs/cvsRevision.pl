#!/usr/bin/perl

use strict;

my $root = @ENV{CVSROOT};
my $file = shift;

die 'no CVSROOT' unless $root ne "";

my $last = `cvs log $file | grep '^head:'`;
chomp $last;

die unless $last =~ s/^head: 1\.([0-9]+)$/$1/;

print "[$last]\n";

my $i = 41;
while ($i >= 1) {
    print `cvs update -r 1.$i $file`;
    `mv $file $file.$i`;
    $i--;
}



