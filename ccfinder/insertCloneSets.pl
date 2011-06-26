#!/usr/bin/perl

$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;

use strict;
use DBI;
use File::Slurp;
use Digest::MD5 qw(md5_hex);

my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $userName = 'dmg';

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});

open(IN, "find . -name '*.cloneAbs' -print |") or  die "Unable to execute find\n";

while (<IN>) {
    chomp;
    my $text = read_file( $_) ;    
    if (!m@\./([0-9]+)/(.*)\.cloneAbs$@) {
	die "Unable to match filename $_\n";
    }
    my $md5 = md5_hex($text);
    my $revid = $1;
    my @fields = split(':',$2);
    my $cloneSet = $fields[0];
    my $fname = $fields[1];
    my $token = $fields[2];
    $fname =~ s/,/\//g;
    $fname =~ s/^\.\///;
    
    my $sth = $dbh->prepare("insert into clonesets(revid, cloneset, filename, md5,tokenBegin) values (?,?,?,?,?);");
    my $rc = $sth->execute($revid, $cloneSet, $fname, $md5, $token);

}

$dbh->disconnect;
exit 0;
