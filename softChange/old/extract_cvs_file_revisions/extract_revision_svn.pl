#!/usr/bin/perl  -w


use File::Basename;
use strict;

# Assume there is already a CVSROOT

# Assume that the checkout will happen in this directory

#local $cvsRoot = '/Users/dmg/local/extract_cvs_file_revisions/cvs';
#local $workingCopy = '/Users/dmg/local/extract_cvs_file_revisions/evolution';

my $file     = $ARGV[0];
my $revision = $ARGV[1];

my $outputFile;

my $TMP_FILE = "/tmp/cvsextractor.$$.error";

die "Usage $0 <filename> <revision>\n" unless $file ne "" and $revision ne "";

#die "No CVSROOT set\n" unless $ENV{CVSROOT} ne "";

my $debug = 1;

print STDERR "Extracting File: [$file] Revision: [$revision]\n" if $debug;

# Ok, error messages go to stderr, and normal messages to stdout. I
# guess I can assume that, if there is STDERR, then there is an error message.

# I think I should save that error message, and keep in in the database.

# So the output from this program should output one file.

# Exit code of 1 if there is an error, exit code of 0 if there is none.


# Get rid of the file first (let us hope the user knows what he/she is doing, maybe move it.

my ($dir);

($_, $dir) = fileparse($file, "");

if (!-d $dir) {
    die "Unable to process this file. Its directory does not exist in the local repository";
}


if (-f $file) {
    `mv -f $file /tmp`;
}

#Build command line.

# Let us assume we do this in the local directory.

my $command = "svn update -r $revision $file 2> $TMP_FILE  | ";

print STDERR "To execute $command\n" if $debug;

open(CVS, $command) || die "Unable to execute [$command]\n";

undef $/;

my $output = <CVS>;

close CVS;

#die "We got some output, we should not get any [$output]\n" if $output ne "";

print STDERR "Output from cvs: [$output]\n" if $debug;

# Verify size of TMP FILE.

my ($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size,
 $atime,$mtime,$ctime,$blksize,$blocks)
    = stat($TMP_FILE);

#if ($size == 0) {
    # We are ok, we can output revision
    $outputFile = $file;
my $exit = 0;
#} else {
#    $outputFile = $TMP_FILE;
#    $exit = 1;
#}

open(TMP_FILE, $outputFile) || die "Unable to read tmp file [$TMP_FILE]\n";
$output = <TMP_FILE>;

#if ($exit != 0) {
#    print "CVS ERROR:\n\n";
#}

print $output;

unlink $TMP_FILE;
exit $exit;


