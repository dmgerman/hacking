#!/usr/bin/perl -w

use Strict;

if (scalar(@ARGV) != 1) {
    die "Usage $0 <filename>\n";
}


my $file = shift;

if (! -f $file) {
    die "File [$file] does not exist\n";
}

my $TMP_FILE = "/tmp/cleanLOCS.$$";

# we first remove comments, then remove empty lines

# copy it to a safe place
`cp -pf $file $TMP_FILE`;

# remove comments
`mangle -cw $TMP_FILE 2> /dev/null`;

open (IN, $TMP_FILE) || die "Unable to open temporal file [$TMP_FILE]\n";

while (<IN>) {
    chomp;
    s/\s+$//;
    next if ($_ eq "");
    print "$_\n";
}

close IN;

unlink $TMP_FILE;
