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

GetOptions(
           "debug"        => \$debug,
           "database=s"   => \$database,
           "filename=s"   => \$filename,
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

#first set the length of those which have a successor

my $sth = $dbh->prepare("
        select trim(filename) from revisions where revisionid = '1.1' and linesadd = 0  order by filename
");
			
my $update = $dbh->prepare("UPDATE revisions set linesadd = ?, linesrm = ? where filename = ? and revisionid = '1.1'");

my $file = $dbh->prepare("select newfile from filerevisions where filename = ? and revisionid = '1.1'");

my $rc = $sth->execute;

#THen set the last

my @row;

my $i=0;
while ( @row = $sth->fetchrow_array ) {

    my $rc = $file->execute($row[0]);
    my @row2;
    if (@row2  = $file->fetchrow_array) {
	my $filename = $row[0];
	print "$filename\n";
	my $contents = $row2[0];
	print " length " , length($contents) , "\n";
	my $lines  = Lines($contents);
	print " lines $lines\n";

	if (not $update->execute($lines, 0, $filename)) {
	    print "UNABLE to update \n";
	}

	$i++;
	print " Count $i\n";
	
    }
}

$dbh->disconnect;

sub Lines
{
    my ($lines) = @_;
    my @a;
    if ($lines !~ /\n$/s) {
	$lines  .= "\n";
    }

    @a = ($lines =~ /\n/sg);

    return scalar(@a);
}




__END__

=head1 NAME

add-linesadded-to-first-revision.pl - update the linesadded, linesremoved to first revision of a file.

CVS does not add this information (for some strange reason)

=head1 SYNOPSIS

$0 [options] cvsLogFile...

 Options:
   --help                  Brief help message
   --man                   Full documentation
   --debug                 Display debugging messages
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
