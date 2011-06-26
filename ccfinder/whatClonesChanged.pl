#!/usr/bin/perl

$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;

use strict;
use DBI;
use File::Slurp;
use Digest::MD5 qw(md5_hex);
require "support.pm";
require "ccdiff.pm";
require "clone.pm";

my $dbName = shift @ARGV;

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $userName = 'dmg';

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});

my $sth = $dbh->prepare("select distinct(revid) from clonesets order by revid");
my $rc = $sth->execute();
my @row;

while ( @row = $sth->fetchrow_array ) {
    print "Processing [$row[0]] .................................... \n";
    what_Clones_Changed($row[0]);
}
$dbh->disconnect;
exit 0;

sub what_Clones_Changed
{
    my ($revid) = @_;
    my @clones = Load_Clones_in_MR($revid);
    my @filesChanged = Load_Files_Changed_in_MR($revid);
    my %prevRevisions;
    my %diffs;

    foreach my $c (@clones) {
	my $f = $c->filename;
	if (inList($f, \@filesChanged)) {
#	    print "$f was modified ";
	    # ok, at this point we know we have to check this particular clone.
	    # find its previous revisions
	    my $d;
	    my $prevRev = $prevRevisions{$f};
	    if (!defined($prevRev)) {
		$prevRev = Find_Previous_Revision($f, $revid);
		$prevRevisions{$f} = $prevRev;
		if ($prevRev eq "") {
		    # file did not exist to this point
		    print "NEw clone : ", $c->print, "\n";
#		    Insert_Clone_Operation($revid, $c, 'A');
		    next;
		}

		my $before = $prevRev . "/" . $f;
		my $after = $revid . "/" . $f;
		die "before [$before] does not exist" unless -f $before;
		die "after [$after] does not exist" unless -f $after;

#		print "before [$before] after [$after]\n";
		$d = ccdiff->new($before, $after);
#		$d->Hunk_Locations_Print ;
		$diffs{$f} = $d;
	    } 
	    if ($prevRev eq "") {
		# file did not exist to this point
		print "NEw clone : ", $c->print, "\n";
#		Insert_Clone_Operation($revid, $c, 'A');
		next;
	    }
	    
		$d = $diffs{$f};

		my ($fromL, $toL) = $c->lines;
		if ($d->region_Changed_After($fromL,$toL)) {
		    print "MOD clone ", $c->print, "\n";
#		    Insert_Clone_Operation($revid, $c, 'M');
		    my $type = $d->region_Changed_Type_After($fromL, $toL);
		    print "MOD clone [$type]\n";
		} 
	}
    }


}

sub Insert_Clone_Operation
{
    my ($revid,$c, $op) = @_;

    my $sth = $dbh->prepare("insert into clonechanges(revid, cloneset, filename, tokenBegin, typemod) values (?,?,?,?,?);");
    
    my $rc = $sth->execute($revid, $c->setId, $c->filename, $c->token_begin, $op);
    
}

sub Find_Previous_Revision
{
    my ($f, $revid) = @_;

    my $sth = $dbh->prepare("select max(revid) from funcmod where filename = ? and typemod <> 'I' and  revid < ?;");

    my $rc = $sth->execute($f, $revid);
    my @row;
    if ( @row = $sth->fetchrow_array ) {
	if (!defined ($row[0])) {
	    return "";
	}
	return $row[0];
    } else {
	die "Not found, something is wrong";
	return ();
    }
}




sub Load_Files_Changed_in_MR
{
    my ($revid) = @_;
    my @result;
    open(IN, "<$revid/filesChanged.txt") or die "Unable to open files that changed";
    
    while (<IN>) {
	chomp;
	s@^\./@@; # remove prefix ./
	push @result, $_;
#	print "Loading [$_]\n";
    }
    close IN;
    return @result;
}


sub Load_Clones_in_MR
{
    my ($revid) = @_;
    my @result;

    open(IN, "<${revid}/clonesInMR.txt") or die "Unable to open clones in MR $revid/clonesInMR.txt";

    
    while (<IN>) {
	chomp;
	s@^\./@@; # remove prefix ./
	my $c = clone->load($_);
	push @result, $c;
    }
    close IN;
    return @result;

}
