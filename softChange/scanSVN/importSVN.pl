#!/usr/bin/perl


use strict;

my $dryRun =0;
my $createLOG =1;
my $createDB =1;
my $processLOG =1;

my $curDir = `pwd`;

chomp $curDir;

$0 =~ m@/([^/]+)$@;
my $binDir = $`; #'

push @INC, $binDir ;

my $DB = shift;
my $prefix = shift;

die "Usage <DB> <prefixToRemoveFromFiles> \n" if $DB eq "" or $prefix eq "";


print "Creating log\n";
if ((!$dryRun) and $createLOG) {
    print `svn log --xml --verbose > ${DB}.log`;
}

print "Now process data\n";
if ((!$dryRun) and $processLOG) {
    print `$binDir/processSVNxmlLog.pl $prefix ${DB}.log`;
}




if (!$dryRun) {
    
    print "Creating database\n";
    if ($createDB) {
	print `dropdb -q $DB`;
	print `createdb -E latin1 $DB`;
    }
    chdir("$binDir/schema");
    print `psql $DB < schema.sql`;
    chdir($curDir) or die "Unable to move back to directory\n";

    `psql $DB < cvsNORM.files > /dev/null`;
    `psql $DB < cvsNORM.revisions > /dev/null`;
    `psql $DB < cvsNORM.mrs > /dev/null`;
    `psql $DB < cvsNORM.filesmrs > /dev/null`;
}

open (TEST , "|psql $DB " ) or die "unable to connect to database\n";

print "Vacuuming DB\n";

print TEST "vacuum full analize;\n";

print "Size of files, revisions, mrs, filesmrs \n";
print TEST "select count(*) as files from files;\n";
print TEST "select count(*) as revisions from revisions;\n";
print TEST "select count(*) as mrs from mrs;\n";
print TEST "select count(*) as revsinmr from revsinmr\n";

close TEST;

print "Done\n";

