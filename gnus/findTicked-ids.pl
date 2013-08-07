#!/usr/bin/perl
#
## This script retrieves the UIDs of Ticked messages 
## according to dovecot and outputs the list
## in a way that it can be used by gnus


use strict;

my $imapDir = shift;

die "usage $0 <imapdir>" unless -d $imapDir;

my $uid = "$imapDir/dovecot-uidlist";

open(UID, $uid) or die "unable to open $uid" ;

my $header = <UID>;

my @result = ();

while (<UID>) {
    my @f = split(' ');
    my $filename ;
    die "illegal record $_" unless scalar(@f) >=2 and scalar(@f) <= 4;
    $filename = $f[scalar(@f) -1];
    die "illegal filename $filename" unless $filename =~ s/^://;
    $filename = $imapDir . "/cur/". $filename . ":2,FS";
    if (-f $filename) {
	# ticked
	print STDERR "Filename $filename\n";
	push (@result, $f[0]);
    }
}
print join(' ', @result), "\n";
