#!/usr/bin/perl

#select filename,revisionid from mrsfiles where mrid in (select mrid
#from mrs2 where daterev >= '2002-04-01' and daterev <= '2002-04-02');

#parameters

use DBI;
use strict;
use Getopt::Long;
use Pod::Usage;


my $database = '';

my $prefix  = '';

my $delay = 10;

my $debug = 0;
my $dbUser = 'dmg';
my $dbPassword = '';

# do we want to insert into the database?
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

#pod2usage(1) if scalar(@ARGV) ==0 ;

my $extractCommand = "extract_revision_svn.pl";
#my $extractCommand = "extract_revisions.pl";


my $dbh = DBI->connect("dbi:Pg:dbname=$database", $dbUser, '');

my $sth = $dbh->prepare("select filename,revid from revisions where filename = 'ChangeLog'  and daterev > '2005-06-01'
                        EXCEPT
                        select filename, revisionid from filerevisions
;");

#my $sth = $dbh->prepare(" select files.filename, revisions.revid
#                          from files  inner join revisions on files.filename = revisions.filename
#                            where (extension in ('.h', '.c','.java', '.cpp'))");


my $rc = $sth->execute;

my @row;

while ( @row = $sth->fetchrow_array ) {
    my ($file, $revision) = @row;
    $file =~ s/\s+$//;

    print "$file, $revision," if $verbose;

    my $rev =  `$extractCommand $file $revision`;

    print "... lenght ...", length($rev) ;

    if  (not $dryRun) {
	

	my $exitCode = $? >> 8;

	print "$exitCode" if $verbose;

	my $insert = $dbh->prepare("INSERT INTO FileRevisions(filename,revisionid,state,newfile) VALUES (?,?,?,?)");

	$insert->execute( $file, $revision, $exitCode, $rev );

    }
    print "... inserted\n" if $verbose and !$dryRun;
    sleep($delay);
}

$dbh->disconnect;


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
