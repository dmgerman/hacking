#!/usr/bin/perl

use strict;

$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;

require "cctokens.pm";

if (scalar(@ARGV) == 0) {
    die "Usage: $0 <ccfinder .cpp.ccfxprep filename> <token#> <token#>...<token#>\n\nPrints the linenumber:columnnumber:bytenumber of each token\n";
}

my $fileName = shift @ARGV;

my $tokens = cctokens->new($fileName);

while (my $tokenNo = shift @ARGV) {
    print join ":", $tokens->token_Translate($tokenNo);
    print "\n";
}
