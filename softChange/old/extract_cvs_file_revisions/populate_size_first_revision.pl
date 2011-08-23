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


my $dbh = DBI->connect("dbi:Pg:dbname=$database", $dbUser, '',
		       { RaiseError => 1});

#my $sth = $dbh->prepare("select filename,revisionid from mrsfiles where filename = 'layout/html/style/src/nsCSSFrameConstructor.cpp' and revisionid ~ '1.6[345][0-9.]'");

#my $sth = $dbh->prepare("select filename,revisionid from mrsfiles where mrid in (select mrid
#                        from mrs2)");

my $sth = $dbh->prepare("select revisions.filename
                         from revisions, files 
                            where revisions.filename = files.filename and
                                 revisionid = '1.1' and
                                (extension in ('.h', '.c','.java', '.cpp')) order by filename");


my $rc = $sth->execute;

my @row;

while ( @row = $sth->fetchrow_array ) {
    my ($fileName) = @row;
    $fileName =~ s/\s+$//;

    print "File: [$fileName]\n" if $verbose;

    my $files = $dbh->prepare("select newfile, cleanfile
                         from FileRevisions
                            where filename = ? and revisionid = '1.1'");

    my $rc = $files->execute($fileName);

    if (my ($newfile, $cleanNewFile) = $files->fetchrow_array) {

	print " Length: " . length($newfile);

	my $noLines = ($newfile =~ s/\n//g);
	if ($noLines eq '') {
	    $noLines = 0;
	}
	
	print " Length: " . length($newfile). " Newlines: $noLines \n";
	if  (not $dryRun) {

	    
	    my $insert = $dbh->prepare("UPDATE revisions SET linesAdd = ? where filename = ? and revisionid = '1.1'");
	    
            $insert->execute( $noLines, $fileName);

	}
    } else {
	print "Not FOUND";
    }


    print "... inserted\n" if $verbose;
}

$dbh->disconnect;


__END__

=head1 NAME

populate_size_first_revision.pl - Insert into a given set of revisions into the database

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
