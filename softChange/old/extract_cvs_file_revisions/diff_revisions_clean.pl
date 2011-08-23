#!/usr/bin/perl  -w


require Strict;

# Assume there is already a CVSROOT

# Assume that the checkout will happen in this directory

#local $cvsRoot = '/Users/dmg/local/extract_cvs_file_revisions/cvs';
#local $workingCopy = '/Users/dmg/local/extract_cvs_file_revisions/evolution';

if (scalar(@ARGV) != 4) {
    die "Usage $0 <database> <file> <revision1> <revision2>\n";
}

my $prefix   = $ARGV[0];
my $file     = $ARGV[1];
my $revision1 = $ARGV[2];
my $revision2 = $ARGV[3];

`extract_revisions.pl  ${prefix}/${file} $revision1 > /tmp/revision.$revision1`;
`extract_revisions.pl  ${prefix}/${file} $revision2 > /tmp/revision.$revision2`;

`mangle -cw /tmp/revision.$revision1 2> /dev/null`;
`mangle -cw /tmp/revision.$revision2 2> /dev/null`;


print `diff /tmp/revision.$revision1 /tmp/revision.$revision2`;

