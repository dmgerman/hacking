#!/usr/bin/perl


use strict;


my $filename = $ARGV[0];


die "Usage: $0 <filename>" if $filename eq '';

die "File not found [$filename]" if not -f $filename;

open (IN, "/usr/local/bin/ectags -x $filename | ") ||
    die "Unable to start ectags \n";

my %functions;
my %lines;

while (<IN>) {
    my @record = split(/\s+/);
#    if ($record[1] eq 'function') {
	$functions{$record[0]} = $record[1];

	$lines{$record[2]} = $record[0];

#	print "$record[0]:$record[2]\n";
#    }
}

close IN;


open (IN, $filename) or die "Unable to open input [$filename]\n";

my $line;
my $def = 0;
my $inside = 0;
my $first = 1;
while (<IN>) {
    chomp;
    $line ++;
    if (defined $lines{$line}) {
	my $name = $lines{$line};
	if ($functions{$name} eq 'function') {
	    if ($first == 0) {
		print "--EOF--\n";
	    }
	    $first = 0;
	    print "function: $name\n";
	    $inside = 1;
	}
	$def++;
    } elsif (/^}/) {
	print "$_\n" if $inside;
	$inside = 0;
    }
    if ($inside) {
	print "$_\n";
    }
}

close IN;
