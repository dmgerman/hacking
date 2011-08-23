#!/usr/bin/perl

use strict;
use DBI;
use File::Basename;

my $periodExtensions = "(m4|c|h|png|in|sh|am|ics|glade|im|txt|ps|" .
    "xml|xpm|sgml|dat|urls|pl|types|vcf|java|uml|" .
    "gif|jpg|" .
    "html|gnorba|oat|db|y|oafinfo|idl|po|pm|" .
    "log|jpg|msg|galview|cvsignore|list|csv|" .
    "def|ps|l|tab|wav|dia|lyx|TXT|i|schema|1|" .
    "make|gladep|mt|mime|out|omf|oaf|table|e-table)";
# These "extensions" do not have a .
my $otherExtensions = "ChangeLog|TODO|README|mbox|LICENSE|NEWS|AUTHORS|INSTALL|THANKS";

my $dbName = shift @ARGV;

if ($dbName eq "") {
    die "$0 <dbName>\n";
}
my $userName = 'dmg';
my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});


my $file;
my $retrieving;

# simple state machine.
# Any ^From means a new message
# any Message ID just output
# any RCS is the file,
# if we are in a file, then the second retrieving is the one we need

while (<>) {
    chomp;
    if (/^From/) {
	# we really dont' do anything. Assume everything is nicely formatted
    }
    if (/^Message/) {
	print $_, "\n";
	$file = "";
    } 
    if (/^  RCS/) {
	if (m@apache-1.3/(.*),v@) {
	    $file = $1;
	    $retrieving = 0;
	    #print "Located file $file\n";
	} elsif (m@/export/home/cvs/apache/(.*),v@) {
	    # the normal repository in first part of 1997
	    $file = $1;
	    $retrieving = 0;
	    #print "Located file $file\n";
	} elsif (m@/export/home/cvs/apachen/(.*),v@) {
	    # moved to this location around 09-1997
	    $file = $1;
	    $retrieving = 0;
	    #print "Located file $file\n";
	} elsif (m@/home/cvs/apachen/(.*),v@) {
	    # an alias for export/home/cvs/apachen
	    $file = $1;
	    $retrieving = 0;
	    #print "Located file $file\n";
	} else {
	    print "   Unable to match repository [$_]\n";
	}
    }
    if (/^  retrieving revision (.*)$/) {
	my $rev = $1;
	$retrieving ++;
#	print "Retr $retrieving:$rev\n";
	if ($retrieving == 2) {
	    print "   $file,${rev}\n";
	    #find filename and revision for this 
	    my $mrid = Find_Revision($rev,$file,0);
	    if ($mrid) {
		print "             [$mrid]\n";
	    } else {
		print "             MR filename [$file][$rev] does not exist!\n";
	    }
	}
    }
}


sub Find_Revision
{
    my ($cvsRev,$file,$rec) = @_;
    
    if ($cvsRev =~ /^([0-9]+)\.([0-9]+)$/) {
	my $cvsRev = $2;
#	print "$cvsRev\n";

	my $sth = $dbh->prepare("select filename, revid from revisions where filename = ? order by revid limit ?");

	my $rc = $sth->execute($file, $cvsRev);
	
	my $revid = "";
	while (my @row = $sth->fetchrow_array ) {
	    $revid = $row[1];
	}
	if ($revid eq "") {
	    
	    # try again, with src/main instead of src
	    if ($rec != 1) {

		my $newFile = Find_Match($file);
		if ($newFile eq "") {
		    return "";
		}
		return Find_Revision("1.$cvsRev",$newFile, 1);
	    }
	} else {
#	    print "MR [$revid]\n";
	}
	return $revid;
    } else {
	print  "        >>>Not a valid revision... [$cvsRev] skip\n";
	return "";
    }

}

sub Find_Match
{
    my ($filename) = @_;
    my ($base, $dir, $ext) = fileparse($filename, "(\\.$periodExtensions|$otherExtensions)");

    my $sth = $dbh->prepare("select filename from files where basename = ? and extension = ?");
    my $rc = $sth->execute($base, $ext);
    my $new;
    
    my $count = 0;
    while (my @row = $sth->fetchrow_array ) {
	$count++;
	$new = $row[0];
    }
    if ($count == 0) {
	print  "        No file for this name [$filename]\n";
	return "";
    }
    if ($count > 1) {
	print     "       Two or more  files with same name [$filename]\n";
	return "";
    }
    print "    [$new]\n";
    return $new;

}
