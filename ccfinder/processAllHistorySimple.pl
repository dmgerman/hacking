#!/usr/bin/perl

$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;


use DBI;
use strict;
#require "ccfinder.pm";

#my $coDir = "/tmp/apache";
#my $repo  = "file:///Users/dmg/mirror/svn.apache/mirror/apache/";
#my $findFiles = '*.c';
my $saveDir = "/tmp/save";
my $coDir = "/tmp/org.eclipse.mylyn";
my $repo = 'file:///Users/dmg/mirror/svn.mylyn/trunk/org.eclipse.mylyn';
#my $findFiles = '*.c';
my $repoPrefix = "";
my $suffix = '.cpp.ccfxprep';
my $callgraphBin = "$dir/create_callgraph.pl";

my $dryRun = 0; # do not compute diffs
my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $userName = 'dmg';
my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});

my $sth = $dbh->prepare("select distinct revid from revisions order by revid asc ;");

my $rc = $sth->execute;

my @row;
my @revs;
while ( @row = $sth->fetchrow_array ) {
#    print "$row[0]\n";
    push @revs, $row[0];
}



# check out after first functions changed
my $first = $revs[0];

while (@revs) {
    my $r = shift @revs;
    print "Checking out revision $r\n";
    print STDERR "Checking out revision $r\n";
    chdir "/tmp" or die "unable to change to /tmp";
#    `rm -rf $coDir`;
#    `mkdir $coDir`;
#    print `pwd`;
    print `svn co -r $r $repo`;
    chdir $coDir or die "unable to change to directory $coDir";

    my @filesInMR = Get_Files_In_MR($r);
    `find . -name '*' > allfiles.txt`;
    print "Copying the files\n";    
    Copy_Files($r, \@filesInMR);
    
}
# for apache, the very first version added all the C files...


$dbh->disconnect;
exit 0;

sub Get_Files_In_MR
{
    my ($rev) = @_;
    my $sth = $dbh->prepare("select distinct filename from revisions natural join files where revid = ? and extension ='.java';");
    my $rc = $sth->execute($rev);
    my @row;
    my @result;
    while ( @row = $sth->fetchrow_array ) {
	print"File in MR: $row[0]\n";
	push @result, $row[0];
    }
    return @result;
}

sub Copy_Files
{
    my ($rev, $files) = @_;

    # while files were modified in the revision?
    mkdir ("$saveDir/$rev");
    open (LIST, ">$saveDir/$rev/filesChanged.txt") or die  "unable to create filesChanged.txt file";

    foreach my $file (@$files) {

#    print "$row[0]\n";
	Copy_File($saveDir, $file, $rev);
	print LIST "$file\n";
    }
    close LIST;
    # copy ccfinder file
    `mv -f allfiles.txt  $saveDir/$rev/`;
    # copy clones
#    `mv -f *.clone*  $saveDir/$rev/`;
}


sub Copy_File
{
    my ($dest, $fname,$rev) = @_;

#    die "illegal filename [$fname]" if ($fname !~ /^$repoPrefix/);
    die "illegal filename 2 [$fname]" if ($fname !~ m@/([^/]+)$@);

    my $fullName = $repoPrefix . $fname;

    # the file is not there, so we return
    if (!-f $fullName) {
	print "File $fullName no longer exists. probably erased\n";
	return ;
    }

    print "Directory [$`] [$1]\n"; #
    my $dir = "$`";  # 
    my $base = $1;

#    print "Creating directory [$saveDir/$rev/$dir]\n";
    `mkdir -p '$saveDir/$rev/$dir'`;

    `cp -f "$fullName" "$saveDir/$rev/$dir/"`;
}


