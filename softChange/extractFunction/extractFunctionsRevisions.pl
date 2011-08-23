#!/usr/bin/perl
$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;

use strict;

require 'dmgextract.pm';

my $empty= '/tmp/empty.txt';

`echo "" > $empty`;

my $svnupdate = 'svn update ';

my $myDiff = '/Users/dmg/bin/funcDiff' ;

my $file = shift @ARGV;

die unless $file ne '';

print STDERR "To do [$file]\n";


print STDERR `svn update $file`;

open (IN, "svn log '$file' | egrep '^r[0-9]'| cut -c2- | sort -n |") or die "Unable to get log for file $file \n";

my $first = 1;

my $prevRev = '';
my $currRev = '';

while (<IN>) {
    print STDERR $_;
    my @fields = split(/ +\| +/);
#    print $fields[1], "\n";
    $currRev = $fields[0];
    if ($first) {
	$first = 0;
	Process_First($file, $currRev, $fields[1]);	
    } else {
	Process($file, $currRev, $prevRev, $fields[1]);
#	print `$svndiff -r$currRev:$prevRev $file`;
    }
    $prevRev = $currRev;
}
close IN;


