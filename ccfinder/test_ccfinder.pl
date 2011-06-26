#!/usr/bin/perl

$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;

use strict;

package main;

require "ccfinder.pm";

my $ccFile = shift @ARGV;

#my $ccFinder = ccfinder->new("/Users/dmg/working/trunk/conf/trunk/hacking/ccfinder",['before.c','after.c']);


my $ccFinder;
my %parms;

$ccFinder = ccfinder->new('');

$ccFinder->load_File($ccFile);

print "Done\n";
die;
$parms{function} = sub { my ($self, $file) = @_; print STDERR "File " , $file->{name}, "\n"; };
$ccFinder->iterate_Files(\%parms);
die;

die;

#if ($whatToTest eq "list") {
#    $ccFinder = ccfinder->new("");
#    $ccFinder->set_Files_List(['before.c', 'after.c','mod_proxy.c','http_core.c']);
#    $ccFinder->execute([],"a.ccfxd");
#}  elsif ($whatToTest eq 'withFileList') {
#    $ccFinder = ccfinder->new("");
#    $ccFinder->execute('rip.txt', "a.ccfxd");
#} elsif ($whatToTest eq 'load') {
#    $ccFinder = ccfinder->new("./apache/");
#    $ccFinder->load_File("a.ccfxd");
#} else {
#    die "$0 (list|withFileList|load)\n";
#}
#
#
my %parms;

# display files
$parms{function} = sub { my ($self, $file) = @_; print STDERR "File " , $file->{name}, "\n"; };
$ccFinder->iterate_Files(\%parms);

$ccFinder->print("clonesStats.txt");

#printf "Length of raw data %d\n", length($ccFinder->get_ccdata_raw);

#print $ccFinder->get_ccdata_pretty;
#print $ccFinder->print;

my @setsClones = $ccFinder->get_Clones_Sets_Selected(['./http_core.c']);

print STDERR "Clone set", join(":", @setsClones), "\n";

if (scalar(@setsClones) > 0) {
    print $ccFinder->print_Clones_Set_Selected(\@setsClones, "clonesInMR.txt");
    print $ccFinder->extract_Clones_Set_Selected(\@setsClones);
    print $ccFinder->extract_Clones_Abstract_Set_Selected(\@setsClones);
} else {
    print STDERR "No clones in this MR\n";
}

#print "--after.c-------------------\n";
#print $ccFinder->print_Clones_Selected(['after.c']);

exit 0;
