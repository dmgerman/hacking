#!/usr/bin/perl

use DBI;
use strict;

my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "dmg", "",
		       { RaiseError => 1});



#first set the length of those which have a successor

my $sth = $dbh->prepare("
        update revdefs set length = 
 	   (select min(rev.cleanline) - revdefs.cleanline
	     from revdefs as rev
	          where 
	             rev.filename =  revdefs.filename and 
	             rev.revisionid = revdefs.revisionid and 
	             rev.cleanLine > revdefs.cleanLine
               )	
");
			
my $rc = $sth->execute;

#THen set the last

my $sth = $dbh->prepare("
      update revdefs set length = 
 	(select rev.cleanLines
	     from FileRevisions as rev
	          where 
	             rev.filename =  revdefs.filename and 
	             rev.revisionid = revdefs.revisionid
              ) - cleanLine
           where length is null
");

my $rc = $sth->execute;

$dbh->disconnect;

