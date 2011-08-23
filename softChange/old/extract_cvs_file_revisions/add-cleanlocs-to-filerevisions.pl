#!/usr/bin/perl

use DBI;
use strict;
use Getopt::Long;
use Pod::Usage;

my $database = '';
my $debug = 0;
my $dbUser = 'dmg';
my $dbPassword = '';

my $useIndent = 1;


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



my $sth = $dbh->prepare(" select files.filename, filerevisions.revisionid, 
                                 filerevisions.state, files.extension,
                                 filerevisions.newfile,
                                 filerevisions.cleanlines
                          from filerevisions, files 
                            where
                                 cleanfile is NULL and 
                                 filerevisions.filename = files.filename and
                                (extension in ('.h', '.c','.java', '.cpp')) 
                         ");

my $rc = $sth->execute;

my @row;

while ( @row = $sth->fetchrow_array ) {

    my ($filename, $revision, $state, $extension,$file, $cleanLines) = @row;
    $filename =~ s/\s+$//;
    $revision =~ s/\s+$//;

    print "Filename: [$filename] Revision: [$revision] State [$state]  $extension CleanLines [$cleanLines] ...";

    my $tmpFile = $TMP_FILE . $extension;


    if ($useIndent) {
	open (FILTER, "|indent -bap -bad -npsl > ${tmpFile}") || die "Unable to start indent and create output file\n"; 
    } else {
	open (FILTER, ">${tmpFile}") || die "Unable to start indent and create output file\n"; 
    }

    print FILTER $file;

    close (FILTER);

    my $clean = `cleanLOCs ${tmpFile}`;
    
    my $count = length($clean);
    
    print "Updated... Line count[$count]...\n";

    if (not $dryRun){

	my $exitCode = $? >> 8;

	print "$exitCode\n" if $verbose;

	my $insert = $dbh->prepare("UPDATE FileRevisions set cleanLines = ?, cleanfile = ?
                                   where filename = ? and revisionid = ?");

	$insert->execute( $count, $clean, $filename, $revision);
    }

}

$dbh->disconnect;

unlink $TMP_FILE;


__END__

=head1 NAME

populate_revisions.pl - Insert into a given set of revisions into the database

=head1 SYNOPSIS

$0 [options] 

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
