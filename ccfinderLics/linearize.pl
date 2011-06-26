#!/usr/bin/perl
use strict;

my $inSentence = 0;
my $previousWord = -1;
while(<>) {
    chomp;
    if (/(.+) \[([^\]]+)\]/) {
        my $what = $1;
        my $value = $2;
        if ($what eq 'ParEnd') {
            if ($inSentence) {
                print "<.>\n";
            }
            $inSentence = 0;
            $previousWord = -1;
            next;
        }
#        print "WHAT [$what]\n";
        my $sentWord = 
            ($what eq 'word') or 
            ($what eq 'id') or 
            ($what eq 'Copysymbol') or 
            ($what eq 'integer') or
            ($what eq 'All Rights Reserved')
            ;

        if ($inSentence == 0) {
            # things that can start a sentence
            next unless $sentWord;
        }
        if ($sentWord) {
            $inSentence = 1;
        }
        print "$value ";
        if ($what eq "word") {
            $previousWord = 1;
        } else {
            $previousWord = 0;
        }
        if ($what eq "SentenceEnd") {
            print "\n";
            $inSentence = 0;
        }
    } else {
        next if $_ =~ /fakeendofline/;
        next if $_ =~ /endofline/;
        next if $_ =~ /ENDOFINPUT/;
        die "illegal record [$_]\n";
    }
}
