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


# first, clean the table

my $sth = $dbh->prepare(" delete from functions");

my $rc = $sth->execute;


# procedure

# we need to scan each filename revision,
#   extract functions for that revision
#   find previous revision.
#   previous revision should indicate which is the latest modified revision
#   if previous modified revision is NULL, 
#          then this is the first time the function is seen
#              ADD function, no need for diff
#   else 
#          compare this version with the last version
#          if DIFF is empty
#              then this have no modification
#                UPDATE function, with last version equal to whatever we compared against
#              else
#                ADD function, this is the last modification, but link to the latest
#                    modification
#

# it is too slow to make the join here, it would be nice to be able to
# start getting rows fast, though, and then let it take its course


# return value
#$filename, $revisionid, $basename, $extension, $datetime, $prevfilename, $prevrevisionid

my $sth = $dbh->prepare("select trim(r.filename), trim(r.revisionid), 
                          trim(basename), trim(extension),
                          to_timestamp(daterev || ' ' || timerev, 'YYYY-MM-DD HH24:MI:SS') as datetime,
                          trim(prevfilename), trim(prevrevisionid)
                          from revisiondiffs as r, files, revisions r2
                          where files.filename = r.filename and
                               trim(r.revisionid) ~ '^[0-9]+\\.[0-9]+\$' and
                               files.filename = r2.filename and r.revisionid = r2.revisionid
                          order by  r.filename, datetime");

my $clean = $dbh->prepare("select cleanfile
                              from filerevisions 
                              where filename = ? and revisionid = ?");


my $functions = $dbh->prepare("select definition, index, typedef from
                              from revdefs
                              where filename = ? and revisionid = ? and
                                 typedef in ('function', 'method')
                               ");

#?,?,?,?,?,??
#filename, revisionid, datetime, defintion, index, body, typedef
my $insert = $dbh->prepare("insert into functions(filename, revisionid, 
                                                  datetime, definition, index, 
                                                  body, typedef)
                                         values (?, ?, ?, ?, ?, ?, ?)");


#?,?,?,?,?,?,?,?,?
#filename, revisionid, datetime, defintion, index, body, typedef, prevfilename,prevrev
my $insertAll = $dbh->prepare("insert into functions(filename, revisionid, 
                                                  datetime, definition, index, 
                                                  body, typedef,
                                                  prevChangedFileName,
                                                  prevChangedRevisionId
                                              )
                                         values (?, ?, ?, ?, ?, ?, ?, ?, ?)");



# ?,?,?,?, ?,?,?,?
# filename, defintion, index, datetime, filename, definition, index
# returns
#  filename, revisionid, body
my $latest = $dbh->prepare("
                              select filename, revisionid, body from functions 
                                  where filename = ? and definition = ?  and
                                     index = ? and
                                     body IS NOT NULL and
                                     datetime = (select max (datetime) from functions where
                                      datetime < ? and filename = ? and definition = ? and index = ?
                                    )
                                 ");

my $rc = $sth->execute();


my $count;

while ( my @row = $sth->fetchrow_array ) {
    
    my ($filename, $revisionid, $basename, $extension, $datetime) = @row;
    my @row2;

    my $rc2 = $clean->execute($filename, $revisionid);
    

    
    if (not (@row2 = $clean->fetchrow())) {
        print STDERR "Unable to get clean file for revision [$filename][$revisionid]\n";
        $clean->finish();
        next;
    }
    my $cleanFile = $row2[0];

    printf "$row[0] [%d]\n", length($clean);

    # Start extracting functions

    my $TMP_FILE = "/tmp/${basename}${extension}";

    # create revision  file
    open(OUT, ">$TMP_FILE") or die "Unable to create temporary file\n";
    print OUT $cleanFile;
    close OUT;

    # now start extracting the functions

    my $saveEOR = $/;
    $/ = "--EOF--\n";


    open(PROC, "extract_functions.pl $TMP_FILE |") or 
        die "Unable to run extract_functions.pl $TMP_FILE\n";
        
    my %functions;
    while (<PROC>) {
        if (/^function: (.+)/) {
            my $functionName = $1;
	    my $index = 0;
            my $body = $'; #' ;
	    
            print $1 . " length " . length($body) .  "\n";
	    
	    
	    if (defined ($functions{$functionName})) {
		$index = ++$functions{$functionName};
	    } else  {
		$functions{$functionName} = 0;
		$index = 0;
	    }
	    
	    # find the latest revision that has changes
	    my $rc3 = $latest->execute($filename,
				       $functionName, $index,
				       $datetime, $filename,
				       $functionName, $index
				      );
	    
	    my ($previousFileName, $previousRevision, $previousBody) = ('','','');

	    print STDERR "$filename, $revisionid, $datetime, $functionName, $index\n";

	    if (@row = $latest->fetchrow_array()) {
		# we found a candidate previous

		($previousFileName, $previousRevision, $previousBody) = @row;

		# so now we compare

		if ($previousBody eq $body ) {
		    # they  are the same, we don't insert
		    print STDERR "There is a previous version of this function and it is identical! \n";
		} else {
		    # ok, we need to insert the new one
		    my $rc4 = $insertAll->execute($filename, $revisionid, $datetime, $functionName, 
					       $index, $body, 'function', 
					       $previousFileName, $previousRevision);
		    
		    if (not $rc4) {
			die "It did not insert the record into the database\n";
		    }
		}

		

	    } else {
		# there is no candidate, this is the first time we see this function

		my $rc4 = $insert->execute($filename, $revisionid, $datetime, $functionName, 
					   $index, $body, 'function');

		if (not $rc4) {
		    die "It did not insert the record into the database\n";
		}
	    }
        } else {
            die "This looks like an invalid record\n";
        }
    }
    close PROC;
    $/ = $saveEOR;

    unlink $TMP_FILE;

    $clean->finish();

    $count++;
    

#    die if $count > 5;


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
