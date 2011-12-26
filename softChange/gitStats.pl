#!/usr/bin/perl

# git log --pretty=fuller --numstat --parents > /tmp/linux.log

#create table meta(id char(40), author varchar(200), audate timestamp, committer varchar(200), codate timestamp, ismerge boolean);
#copy meta from '/tmp/samba/meta.txt' DELIMITER ';';

#create table files(id char(40), filename varchar(200), linesadd int, linesrm int);
# copy files from '/tmp/samba/files.txt' DELIMITER ';' NULL '';




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

open(GIT, "git log --pretty=fuller --numstat --parents |") or die "unable to start git log in current directory";


open(FILES, ">/tmp/files.txt")      or die "unable to create files.txt";
open(LOGS, ">/tmp/logs.txt")        or die "unable to create logs.txt";
open(META, ">/tmp/meta.txt")        or die "unable to create meta.txt";
open(PARENTS, ">/tmp/parents.txt")  or die "unable to create parents.txt";

my $i;

while(<GIT>) {
    s/\\//g;
    chomp;
    if (/^commit (.+)$/) {
        $i++;

        if ($i % 100) {
            print ".";
        }

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
printf STDERR "processed $i commits\n";
close (LOGS);
close (FILES);
close (META);
close (PARENTS);
close GIT;
