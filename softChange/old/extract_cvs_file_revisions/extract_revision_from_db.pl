#!/usr/bin/perl


use DBI;
use strict;
use Getopt::Long;
use Pod::Usage;

my $database = '';

my $prefix  = '';

my $debug = 0;
my $dbUser = 'dmg';
my $dbPassword = '';
my $filename = '';

# do we want to insert into the database?
my $dryRun = 0;

my $verbose = 1;
my $help = 0;
my $man = 0;
my $notClean = 0;

GetOptions(
           "debug"        => \$debug,
           "database=s"   => \$database,
           "filename=s"   => \$filename,
           "verbose"      => \$verbose,
           "help"         => \$help,
           "man"          => \$man,
           "notclean"       => \$notClean,
           "dbUser=s"     => \$dbUser,
           "dbPassword=s" => \$dbPassword,
           );

pod2usage(1) if $help;
pod2usage(-verbose => 2) if $man;

pod2usage(1) if scalar(@ARGV) != 2 ;

my $filename = $ARGV[0];
my $revisionId = $ARGV[1];


my $dbh = DBI->connect("dbi:Pg:dbname=$database", $dbUser, '');

my $sth;
if ($notClean) {
    $sth = $dbh->prepare("select cleanfile from filerevisions
                         where filename = ? and revisionid = ?
                        ");
} else {
    $sth = $dbh->prepare("select newfile from filerevisions
                         where filename = ? and revisionid = ?
                        ");
}

my $rc = $sth->execute($filename, $revisionId);


if ( my @row = $sth->fetchrow_array ) {
    
    print $row[0];
#    die if $count > 5;

} else {
    print STDERR "Revision [$revisionId] for file [$filename]  does not exist\n";
}

$sth->finish();

$dbh->disconnect;


__END__

=head1 NAME

$0 - Extract a given revision from the database

=head1 SYNOPSIS

$0 [options] filename revisionid

 Options:
   --help                  Brief help message
   --man                   Full documentation
   --debug                 Display debugging messages
   --verbose               Display some useful progress information
   --database=<dbName>     Name of the database 
   --dbUser=<dbUser>       Username
   --dbPassword=<password> Password   
   --notclean              Extract file with comments and empty lines

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
