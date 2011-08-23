#!/usr/bin/perl


use DBI;
use strict;
use Getopt::Long;
use Pod::Usage;

my $TMP_FILE = "/tmp/populate_diffs-$$-temp";	
my $filenew = $TMP_FILE . '.new';
my $fileold = $TMP_FILE . '.old';

my $diffCmd      = 'diff -d -U 0  --suppress-common-lines ';
my $diffCmdClean = 'diff -B -b -d -U 0  --suppress-common-lines ';

my $database = '';

my $prefix  = '';

my $debug = 0;
my $dbUser = 'dmg';
my $dbPassword = '';

# do we want to insert into the database?

my $delay = 0;

my $dryRun = 0;

my $verbose = 1;
my $help = 0;
my $man = 0;

GetOptions(
	   "debug"     	  => \$debug,
	   "database=s"   => \$database,
	   "verbose"      => \$verbose,
           "help"         => \$help,
	   "man"          => \$man,
           "dryRun"       => \$dryRun,
	   "moduleDir=s"    => \$prefix,
           "dbUser=s"     => \$dbUser,
 	   "dbPassword=s" => \$dbPassword,
	   );

pod2usage(1) if $help;
pod2usage(-verbose => 2) if $man;

pod2usage(1) if scalar(@ARGV) > 0 ;


my $dbh = DBI->connect("dbi:Pg:dbname=$database", $dbUser, '');


# first, clean the table

my $sth = $dbh->prepare(" delete from revisiondiffs");

my $rc = $sth->execute;

# then add the revisions, date

my $sth = $dbh->prepare("
insert into revisiondiffs(filename,revisionid,datetime) SELECT filename, revid, daterev as datetime from revisions
 ;
");

#where filename ~ '\\\\.c'

my $rc = $sth->execute;


my $sth = $dbh->prepare("
select trim(r.filename),trim(r.revisionid),r.datetime,newfile,cleanfile from revisiondiffs as r,filerevisions as f
where 
   f.filename = r.filename and 
   r.revisionid = f.revisionid and 
   cleanfile is not null  and
   not (r.revisionid ~ '\\\\.[0-9]+\\\\.')
   order by r.filename,r.datetime;
");



my $rc = $sth->execute;

#select files.filename, mrsfiles.revisionid
#                          from mrsfiles, files 
#                            where mrsfiles.filename = files.filename and
#                                (extension in ('.h', '.c','.java', '.cpp'))");
#
#
#
#
my @row;
#
my ($prevFileName, $prevRevision, $prevDatetime, $prevFile, $prevCleanFile) = $sth->fetchrow_array;
$prevFileName =~ s/\s+$//;


open (TEMP, ">/tmp/rip.rip") or die "Unable to create tmp";

while ( @row = $sth->fetchrow_array ) {
    my ($fileName, $revision, $datetime, $file, $cleanFile) = @row;
    $fileName =~ s/\s+$//;
    if ($fileName eq $prevFileName) {

	print "   $fileName, $prevRevision, $revision";


	open(FOLD, ">$fileold") or die "Unable to create temp file [$fileold]\n";
	print FOLD "$prevFile";
	close FOLD;
	open(FOLD, ">$filenew") or die "Unable to create temp file [$fileold]\n";
	print FOLD "$file";
	close FOLD;
	

	my $diff = `$diffCmd $fileold $filenew`;
	
	unlink $fileold;
	unlink $filenew;

	#/* Remove empty ends of lines, let us hope that that does not mess up the source code */
	$prevCleanFile =~ s/[ \t]+$//mg;
	$cleanFile =~ s/[ \t]+$//mg;

	open(FOLD, ">$fileold") or die "Unable to create temp file [$fileold]\n";
	print FOLD "$prevCleanFile";
	close FOLD;
	open(FOLD, ">$filenew") or die "Unable to create temp file [$fileold]\n";
	print FOLD "$cleanFile";
	close FOLD;

	my $cleanDiff = `$diffCmdClean -b -B $fileold $filenew`;

	unlink $fileold;
	unlink $filenew;
	

	print TEMP $cleanDiff;

	printf " lenght diffs [%d][%d] " , length($cleanDiff), length($diff);
	
	if  (not $dryRun) {
	
	    print "   to update\n";

	    my $insert = $dbh->prepare("UPDATE revisiondiffs set prevfilename = ?, prevrevisionid = ?, diff=?, diffClean=? where
                                        filename = ? and revisionid = ?");

	    my $x = $insert->execute( $prevFileName, $prevRevision, $diff, $cleanDiff, $fileName, $revision);

	    if ($x == 0) {
		die "Unable to update record for [$fileName, $revision]\n";
	    }

	    print " inserted [$x]";

	}
	print "\n";

	sleep($delay);

    }
    ($prevFileName, $prevRevision, $prevDatetime, $prevFile, $prevCleanFile) = 
	($fileName, $revision, $datetime, $file, $cleanFile);

#
#    print "${prefix}/$file, $revision," if $verbose;
#
#    my $rev =  `extract_revisions.pl ${prefix}/$file $revision`;
#
#    print "... lenght ...", length($rev) ;
#
#    print "... inserted\n" if $verbose;
}

$dbh->disconnect;
close TEMP;


__END__

=head1 NAME

populate_revisions.pl - Insert into a given set of revisions into the database

=head1 SYNOPSIS

$0 [options] cvsLogFile...

 Options:
   --help                  Brief help message
   --man                   Full documentation
   --debug  	   	   Display debugging messages
   --verbose               Display some useful progress information
   --database=<dbName>     Name of the database 
   --dbUser=<dbUser>       Username
   --dbPassword=<password> Password   
   --moduleDir=<dir>       Directory where the working copy is

=head1 OPTIONS

=over 8

=item B<--help>

Print a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=item B<--verbose>

Show messages showing progress

=item B<--window=seconds>

Maximum number of seconds that a MR is allowed to last.

=back

=head1 DESCRIPTION

  Long description here...


=cut
