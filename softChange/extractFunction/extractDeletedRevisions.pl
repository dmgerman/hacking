#!/usr/bin/perl
#print $0;
$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;


use DBI;
use strict;

require 'dmgextract.pm';
require 'dmgsoftchange.pm';

my $dryRun = 0; # do not compute diffs
my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $userName = 'dmg';

my $TMP_FILE = "/tmp/$$-temp.c";

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});


my $sth = $dbh->prepare("select count(*) from revisions natural join files where filename in 
 (select filename from revisions natural join files where extension in ('.c') );");
my $rc = $sth->execute;

my ($count)  =$sth->fetchrow_array;

print "TODO $count\n";

$sth = $dbh->prepare("select filename, revid as revision, deleted from revisions natural join files where filename in 
 (select filename from revisions natural join files where extension in ('.c')) order by filename asc, revision asc");
$rc = $sth->execute;


my @row;
my $prevFile = '';
my $prevRev = -1;
while ( @row = $sth->fetchrow_array ) {
    my ($file, $rev, $deleted, $developer) = @row;

    my ($author) = Get_Author_Of_MR($dbh, $rev);
    print STDERR "TODO: $count;$row[0]:$row[1]:$row[2]:$author\n";
    $count--;
    
    if ($prevFile ne $file) {
	die "first revision is a delete! $file:$rev$deleted\n" if $deleted;
	# first revision
	
	# make sure the directory exists 
	{
	    my @dirs = split('/', $file);
	    pop @dirs;
#    print join('::', @dirs) , "\n";
	    
	    my $c = '.';
	    foreach my $d (@dirs) {
		$c .= "/" . $d;
#	print "dir: $c\n";
		if (! -d $c) {
		    print STDERR   `svn update -r$rev $c`;
		}
	    }
	}
	

	print STDERR `svn update -r$rev $file`;
	Process_First($file, $rev, $author) unless $dryRun;
    } elsif ($deleted) {
	Process_Last($file, $prevRev, $author, $rev) unless $dryRun;
    } else {
	Process($file, $rev, $prevRev, $author) unless $dryRun;
    }

    $prevFile = $file;
    $prevRev = $rev;
}



$dbh->disconnect;

unlink $TMP_FILE;

exit 0;


