#!/usr/bin/perl

use strict;

my %months  = (
    "January" => 1,
    "February" => 2,
    "March" => 3,
    "April" => 4,
    "May" => 5,
    "June" => 6,
    "July" => 7,
    "August" => 8,
    "September" => 9,
    "October" => 10,
    "November" => 11,
    "December" => 12
);

my $month;
my $year;

while (<>) {
    chomp;
    next if /^\s*$/;
    if (/^\*/) {
        # new month
        die "invalid month [$_]" unless /^\*\s+(\w+)\s(\d+)$/ ;
        print STDERR "month [$1]", $months{$1}, "\n";
        $month = $months{$1};
        $year = $2;
    } else {
        die "invalid forma [$_]" unless /^([0-9,-]+)\s+([A-Za-z,-]+)\s+(.+)$/;
        printf "%04d/%02d/%02d;\"%s\"\n", $year, $month, $1, $3;
    }
    
}
