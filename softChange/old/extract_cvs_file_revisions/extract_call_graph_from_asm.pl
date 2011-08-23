#!/usr/bin/perl


use strict;


my $filename = $ARGV[0];
my $assName = $ARGV[1];


die "Usage: $0 <filename> <assembly>" if $filename eq '' or $assName eq '';

die "File not found [$filename]" if not -f $filename;

open (IN, "/usr/local/bin/ectags -x $filename | ") || 
    die "Unable to start ectags \n";

my %functions;

while (<IN>) {
    my @record = split(/\s+/);
    if ($record[1] eq 'function') {
	$functions{$record[0]} = 1;
#	print "$record[0]\n";
    }
}

close IN;



open (IN, $assName) or die "Unable to read assembly file $assName\n";

my $inFunction;
my $currentFunction = '';

while (<IN>) {
    chomp;
    if (/^_([^:]+):/) {
	# This looks like declaration
	my $id = $1;
	if ($functions{$id}) {
#	    print "$1\n";
	    $currentFunction = $1;
	    $inFunction = 1;
	} else {
	    $inFunction = 0;
	    $currentFunction = 'NOT';
	} 
    } elsif (/^\.section/) {
	$inFunction = 0;
	$currentFunction = 'NOT';
    } elsif (/_([^\$]+)/) {
	my $call = $1;
	if ($functions{$call} && $currentFunction ne 'NOT') {
	    print "$currentFunction,$call\n";
	}
    }

}

close IN;

