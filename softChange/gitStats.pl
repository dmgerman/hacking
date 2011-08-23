#!/usr/bin/perl

# git log --pretty=fuller --numstat > /tmp/linux.log



use strict;

my $commit;
my $author;
my $date;
my $commitDate;
my $committer;

my $inLog = 0;
my $inFiles = 0;

my $testOnly = -1;
my $log;
my $isMerge = 0;

open(FILES, ">files.txt")      or die "unable to create files.txt";
open(LOGS, ">logs.txt")        or die "unable to create logs.txt";
open(META, ">meta.txt")        or die "unable to create meta.txt";
open(PARENTS, ">parents.txt")  or die "unable to create parents.txt";

while(<>) {
    s/\\//g;
    chomp;
    if (/^commit (.+)$/) {
        my @ids = split(/ /, $1);
        $commit = shift @ids;

        foreach my $c (@ids) {
            print PARENTS "$commit;$c\n";
        }

        $isMerge = 0;
        $inFiles = 0;
        $inLog = 0;
        $date = "";
        $commitDate = "";
        $author = "";
        $committer = "";
        $log = "";
        die "partial run" if (--$testOnly == 0) ;
    } elsif (/^Author: +(.+)$/) {
        $author = $1;
    } elsif (/^Commit: +(.+)$/) {
        $committer = $1;
    } elsif (/^Merge: +(.+)$/) {
        $isMerge = 1;
    } elsif (/^AuthorDate:\s+(.+)$/) {
        $date = $1;
    } elsif (/^CommitDate:\s+(.+)$/) {
        $commitDate = $1;
        print META "$commit;$author;$date;$committer;$commitDate;$isMerge\n";
    } elsif (/^([0-9-]+)\t([0-9-]+)\t(.+)$/) {
        my $linesAd;
        my $linesRem;
        my $file;
        $inFiles = 1;
        ($linesAd, $linesRem, $file) = ($1, $2, $3);
        die unless $linesAd ne "" and $linesRem ne "" and $file ne "";
        die unless $file !~ /;/;
        $linesAd = "" if ($linesAd eq "-") ;
        $linesRem = "" if ($linesRem eq "-") ;

        print FILES "$commit;$file;$linesAd;$linesRem\n";
    } elsif ($_ eq "") {
        if (not $inFiles and not $inLog) {
            # the log is starting
            $inLog = 1;
        } elsif ($inLog) {
            # flush log
            $log =~ s/\r/<<RETURN>>/g;
            $log =~ s/\n/<<NL>>/g;
            $log =~ s/\\/<<BACKSLASH>>/g;
            $log =~ s/;/<<SEMICOLON>>/g;
            print LOGS "$commit;$log\n";
            $inLog = 0;
        }
    } elsif ($inLog) {
        die unless /^    (.*)$/;
        $log .= $1 . "<<NL>>";
    } else {
        die "Where the hell am I [$_][$inLog][$inFiles][$_]\n";
    }

}

close (LOGS);
close (FILES);
close (META);
close (PARENTS);
