#!/usr/bin/perl

$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;


use DBI;
use strict;
use Getopt::Long;
use Pod::Usage;

require "ccfinder.pm";
require "softChange.pm";
require "processFunctions.pm";


my $coDir = "/tmp/co";
my $saveDir = "/tmp/save";
my $saveDirSelf = "/tmp/saveSelf";
my $findFiles = '*.c';
my $repoPrefix = "./";
my $suffix = '.cpp.ccfxprep';
my $callgraphBin = "$dir/create_callgraph.pl";

my $dryRun = 0; # do not compute diffs
my $verbose = 0;
my $debug = 0;
my $man = 0;
my $help = 0;
my $doCCfinder = 0;
my $getAllFiles = 0;

GetOptions("verbose"		  => \$verbose,
	   "debug"		  => \$debug,
	   "help"                 => \$help,
	   "man"                  => \$man,
           "ccfinder"             => \$doCCfinder,
           "cloning"              => \$doCCfinder,
           "coDir=s"              => \$coDir,
           "saveDir=s"            => \$saveDir,
           "filesToProcess=s"     => \$findFiles,
	   "ccfindersuffix=s"	  => \$suffix,
           "getAllFiles"          => \$getAllFiles,
	   ) or pod2usage(2);


pod2usage(1) if $help;
pod2usage(-verbose => 2) if $man;

pod2usage(1) if scalar(@ARGV) ==0 ;

my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $userName = 'dmg';
my $db = softChange->new($dbName);

my @revs = $db->Get_MRs_FuncMod();


mkdir $saveDirSelf;

my $first = $revs[0];

while (@revs) {
    my $r = shift @revs;
    my @filesInMR = $db->Get_Files_in_MR_FuncMod($r);


    my @theFiles;

    foreach my $f (@filesInMR) {
        my $prev = Get_File_Previous_Revision($dbh, $f, $r);
        print "$f, $r, $prev\n";
        if ($prev ne "") {
            my $new = "$saveDir/$r/$f";
            my $old = "$saveDir/$prev/$f";
            
            push @theFiles, $new;
            push @theFiles, $old;
        }
    }

    if (scalar(@theFiles)>0) {
        open (FILES, ">allfiles.txt") or die "unable to create output file [files.txt]\n";
        print FILES join("\n", @theFiles);
        close FILES;

        Do_CCFinder($r, \@theFiles);

        Copy_CCFinder_Files($saveDirSelf,$r,(), $prefix, $saveDir, $suffix);
    }
}



