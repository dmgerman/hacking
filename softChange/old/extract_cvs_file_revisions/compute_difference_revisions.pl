#!/usr/bin/perl

# This program only detects lines added, removed and where they more/less happened

if (scalar(@ARGV) != 4) {
    die "Usage $0 <dbName> <filename> <revision1> <revision2>\n";
}

my $dbName = shift;
my $filename = shift;
my $originalRev = shift;
my $newRev  = shift;

my $database = 'mozilla';
my $prefix  = 'mozilla';


my $dbUser = 'dmg';

my $dbPassword = '';



use DBI;
use strict;


my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$dbUser", "");


my $check = $dbh->prepare("select state, cleanLines, newfile from 
                           FileRevisions where filename = ? and
                           revisionid = ?");

# check before
my $rc = $check->execute($filename, $originalRev);

my ($beforeState, $beforeCleanLines, $beforeText);

if (my @row = $check->fetchrow_array ) {
    ($beforeState, $beforeCleanLines, $beforeText) = @row;
} else {
    die "Version before does not exist\n";
}

$check->finish();


my $rc = $check->execute($filename, $newRev);

my ($afterState, $afterCleanLines, $afterText);

if (my @row = $check->fetchrow_array ) {
    ($afterState, $afterCleanLines, $afterText) = @row;
} else {
    die "Version after does not exist\n";
}

$check->finish();


# FIrst report added identifiers

print ">>>Identifiers added\n";
my $sth = $dbh->prepare("
                        select definition,typedef, index from revdefs 
                            where filename = ? and revisionid = ?
                        EXCEPT
                        select definition,typedef, index from revdefs 
                            where filename = ? and revisionid = ?
                        ");

my $rc = $sth->execute($filename, $newRev, $filename, $originalRev);

my @row;

while ( @row = $sth->fetchrow_array ) {
    my ($definition, $type, $index) = @row;
    print "$definition, $type, $index\n";
}

# Then report deleted identifiers

print ">>>Identifiers deleted\n";
my $sth = $dbh->prepare("
                        select definition,typedef, index from revdefs 
                            where filename = ? and revisionid = ?
                        EXCEPT
                        select definition,typedef, index from revdefs 
                            where filename = ? and revisionid = ?
                        ");


my $rc = $sth->execute($filename, $originalRev, $filename, $newRev);

my @row;

while ( @row = $sth->fetchrow_array ) {
    my ($definition, $type, $index) = @row;
    print "$definition, $type, $index\n";
}


print ">>>Identifiers changed\n";

my $sth = $dbh->prepare("
         select before.definition, before.typedef, before.index, before.cleanline, 
                after.cleanline, before.length,  after.length
             from (select definition,typedef, index, cleanline, length from revdefs 
                            where filename = ? and revisionid = ? ) as before,
                  (select definition,typedef, index, cleanline, length from revdefs 
                            where filename = ? and revisionid = ? ) as after
             where before.definition = after.definition and
                   before.typedef    = after.typedef    and 
                   before.index      = after.index
             order by before.cleanline
          ");
  
my $rc = $sth->execute($filename, $originalRev, $filename, $newRev);

my @row;

while ( @row = $sth->fetchrow_array ) {
    my ($definition, $type, $index, $lineBefore, $lineAfter, $originalLength, $newLength) = @row;
    if ($originalLength != $newLength) {
	print "$definition, $type, $index, $lineBefore, $lineAfter, $originalLength, $newLength\n";
    }
}

$dbh->disconnect;

