#!/usr/bin/perl

use DBI;
use strict;
use Getopt::Long;
use IPC::Open2;
use Symbol;

my $database = '';
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
           "dbUser=s"     => \$dbUser,
 	   "dbPassword=s" => \$dbPassword,
	   );

pod2usage(1) if $help;
pod2usage(-verbose => 2) if $man;

my $TMP_FILE = "/tmp/add-cleanlocs-$$-temp";

my $dbh = DBI->connect("dbi:Pg:dbname=$database", $dbUser, $dbPassword,
		       { RaiseError => 0});



my $sth = $dbh->prepare(" select filename, revisionid, cleanfile from filerevisions where cleanfile is not null 
;");

my $rc = $sth->execute;

my @row;

my $WTR = gensym();  # get a reference to a typeglob
my $RDR = gensym();  # and another one


my $TMP_FILE = "/tmp/cleansed-$$-temp";

while ( @row = $sth->fetchrow_array ) {


    my ($filename, $revision, $file) = @row;

    $filename =~ s/\s+$//;
    $revision =~ s/\s+$//;

    open (FILTER, "| cleanse.pl > ${TMP_FILE}") || die "Unable to start indent and create output file $TMP_FILE\n"; 

    print FILTER $file;

    close FILTER;

    open (CLEAN, "< ${TMP_FILE}") || die "Unable to start indent and create output file $TMP_FILE\n"; 

    undef $/;
    
    my $cleansed = <CLEAN>;

    close(CLEAN);

    printf( "Filename: [$filename] Revision: [$revision] Original [%d] Lenght [%d]\n",  length($file), length($cleansed));

    if (not $dryRun){

	my $insert = $dbh->prepare("INSERT into cleansed(filename, revisionid, cleansed) values (?,?,?)");

	$insert->execute( $filename, $revision, $cleansed);
    }


}

$dbh->disconnect;

unlink $TMP_FILE;


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
