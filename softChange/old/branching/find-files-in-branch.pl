#!/usr/bin/perl


use DBI;
use strict;
use Getopt::Long;
use Pod::Usage;

my $database = '';

my $debug = 0;
my $dbUser = 'dmg';
my $dbPassword = '';

# do we want to insert into the database?
my $dryRun = 0;

my $verbose = 0;
my $help = 0;
my $man = 0;
my $create = 1;
my $delete = 0;

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

pod2usage(1) if scalar(@ARGV) != 0 ;


my $dbh = DBI->connect("dbi:Pg:dbname=$database", $dbUser, '');


if ($create) {

    my $sth = $dbh->prepare("
     drop table branchesrevisions ;
     ");
    
    my $rc = $sth->execute();
    
    my $sth = $dbh->prepare("
     create table branchesrevisions  (
         mrid char (60),
         filename char(140),
         revisionid char(40),
         branch     integer
     );
     ");
    
    my $rc = $sth->execute();
    
    my $sth = $dbh->prepare("  
      insert into branchesrevisions(mrid, filename, revisionid) 
          SELECT mrid, filename, revisionid from mrsfiles where revisionid ~ '\\\\.[0-9]\\\\.[0-9]\\\\.';
     ");
    
    my $rc = $sth->execute();

    my $sth = $dbh->prepare("  
      create index branches1  on branchesrevisions(mrid);
     ");
    
    my $rc = $sth->execute();

    my $sth = $dbh->prepare("  
      create index branches2  on branchesrevisions(filename, revisionid);
     ");
    
    my $rc = $sth->execute();


}

if ($delete) {

    my $sth = $dbh->prepare("
     delete from branchesrevisions ;
     ");
    
    my $rc = $sth->execute();
    
    my $sth = $dbh->prepare("  
      insert into branchesrevisions(filename, revisionid) 
          SELECT filename, revisionid from revisions where revisionid ~ '\\\\.[0-9]\\\\.[0-9]\\\\.';
     ");
    
    my $rc = $sth->execute();
}



######################################################################


my $loop = 1;
my $branchId = 0;
while ($loop) {

    print "Processing branch $branchId\n";
    $branchId++;
    my $sth = $dbh->prepare("
       select filename, revisionid from branchesrevisions
            where branch is null
    ");
    
    my $rc = $sth->execute();

    if (my ($startFile, $startRevisionId) = $sth->fetchrow_array ) {
	
	
	
	$startFile = Trim($startFile);
	$startRevisionId = Trim($startRevisionId);

	print "Starting branch scanning from [$startFile, $startRevisionId]\n";

	
	my %filesBranch = Find_Branch_From_Revision($dbh, $startFile, $startRevisionId);
	
	
	
######################################################################    
	my $i = 0;
#foreach my $mr (sort keys %mrsInBranch){
#    print "MR [$i] $mr \n";
#    $i++;
#
#}
#$i = 0;
	
	my $j = 0;
	foreach my $file (sort keys %filesBranch){
	    my @revisions = @{$filesBranch{$file}};
	    my ($p, @indices) = Extract_And_Sort_Revision_Indices(@revisions);
	    
	    foreach my $rev (@revisions) {
		
		my $sth = $dbh->prepare("
        update  branchesrevisions set branch = ?
            where filename = ? and revisionid  = ?
    ");
		
		my $rc = $sth->execute($branchId, $file, $rev);
		
		print "   File [$j][$i] $file,$rev\n";
		$i++;
	    }
	    $j++;
	}
    } else {
	$loop = 0;
    }


}



$dbh->disconnect;
exit;

######################################################################

my %MarkFilesDone;





sub Find_Candidate_MR_Forward
{
    my ($dbh, $filesDone, %filesInBranch) = @_;

    foreach my $file (sort keys %filesInBranch) {
	print " Checking File 0 [$file] for candidate\n" if $verbose > 2;
	next if $$filesDone{$file} == 1;
	print " Checking File 1 [$file] for candidate\n" if $verbose > 2;
	my $nextRevision = Find_Next_Revision(@{$filesInBranch{$file}});
	if (my $mr = Find_MRId($dbh, $file, $nextRevision)) {
	    # We got a candidate
	    return $mr;
	}
	print "   Marking [$file] as end of line \n" if $verbose > 2;
	$$filesDone{$file} = 1;
    }
    return undef;
}

sub Revision_Prefix_Suffix
{
    my ($rev) = @_;
    if (not $rev =~ /\.([0-9]+)$/) {
	die "This is not a revision [$rev]\n";
    }
    return ($`, $1);
}


sub Extract_And_Sort_Revision_Indices
{
    my @revisions = @_;

    my @indices ;

    die "No revision received\n" if scalar(@revisions) == 0;
    
    my ($prefix,$not) = Revision_Prefix_Suffix($revisions[0]);

    foreach my $rev (@revisions) {

	my ($thisPrefix, $index) = Revision_Prefix_Suffix($rev);
	if ($prefix ne $thisPrefix) {
	    print "****This is not  a valid revision [$rev] prefix [$prefix]\n";
	}
	push(@indices, $index);
    }
    return ($prefix, sort {$a <=> $b} @indices);
}

sub Compute_Depth_Branch
{
    my ($rev) = @_;
    my $count =0 ;
    while ($rev =~ /\./g) {
	$count++;
    }
    return $count;
}


sub Find_Candidate_Backwards
{
    my (%filesInBranch) = @_;

    foreach my $file (sort keys %filesInBranch) {
	my $prefix;
	my $earliest;
	my @sortedRevisions;
	($prefix, @sortedRevisions) = Extract_And_Sort_Revision_Indices(@{$filesInBranch{$file}});


	my $gap = $sortedRevisions[0] + 1;
	my $first = $sortedRevisions[0];

	my $test = 0;
	foreach my $rev (@sortedRevisions) {
	    die "illegal sort @sortedRevisions, [$rev], [$test]\n"
		if $rev < $test;
	    $test = $rev;
	    if ($rev == $gap) {
		$gap++;
	    }
	}
	
	my $sizeRevisions = scalar(@sortedRevisions);


	if ($gap < $sortedRevisions[$sizeRevisions - 1]) {
	    print "New revions gap: $file: ${prefix}.${gap}\n" if $verbose > 2;
	    return ($file, "${prefix}.${gap}");
	} elsif ($first > 1) {
	    $first--;
	    print "New revision $file: first ${prefix}.${first}\n" if $verbose > 2;
	    return ($file, "${prefix}.$first");
	}
    }
    return ();
}

sub Find_Next_Revision
{
    my @revisions = @_;
    my $oneRev = $revisions[0];
    if (not $oneRev =~ /\.([0-9]+)$/) {
	die "This is not a revision [$oneRev]\n";
    }
    my $latest = $1;
    my $prefix = $`;
    
    foreach my $rev (@revisions) {
	if (not $rev =~ /\.([0-9]+)$/) {
	    die "This is not a revision [$rev]\n";
	}
	my $thisPrefix = $`;
	my $this = $1;
	if ($prefix ne $thisPrefix) {
	    die "Prefix [$prefix] does not match [$thisPrefix]! revisions[@revisions]\n";
	}
	$latest = $this if ($this > $latest) ;
    }
    # Next is one after..
    $latest ++;
    return "${prefix}.${latest}";
}


sub Find_Files_In_MR
{
    my ($dbh, $mr)  = @_;
    my %result = ();

#    print "Searching for files in [$mr]\n" if $verbose;

    my $sth = $dbh->prepare("
     select filename, revisionid from branchesrevisions where mrid = ?");
    my $rc = $sth->execute($mr);
    
    
    while (my @row = $sth->fetchrow_array) {
	my $myFile = Trim($row[0]);
	my $myRev = Trim($row[1]);
#	print "   $myFile, $myRev\n";
	$result{$myFile}  =  $myRev;
    }
    return %result;
}


sub Revision_In_Set
{
    my ($newRevision, @revisions) = @_;
    foreach $a (@revisions) {
	return 1 if $a eq $newRevision;
    }
    return 0;
}

sub Find_MRId
{
    my ($dbh, $startFile, $startRevisionId)  = @_;


#    print "Searching for [$startFile,$startRevisionId]\n";

    my $sth = $dbh->prepare("
     select mrid from branchesrevisions where filename = ? and revisionid = ?;
");
    my $rc = $sth->execute($startFile, $startRevisionId);
    
    if (my @row = $sth->fetchrow_array) {
	my $mrid = $row[0];
	return Trim($row[0]);
    } else  {
	return undef;
    }
}


sub Trim
{
    my ($st) = @_;

    $st =~ s/\s+$//o;
    return $st;
}

sub Find_Branch_From_Revision
{
    my ($dbh, $startFile, $startRevisionId) = @_;

    my $startMRid;
    if (not $startMRid = Find_MRId($dbh, $startFile, $startRevisionId)) {
	$dbh->disconnect;
	die "Unable to find [$startFile, $startRevisionId]\n";
	
    }
    
# so now we have a starting point. Let us get the files in that MR.
# We have a set of filename, revisions in the branch.
    
    my %filesInBranch;
    
    push( @{$filesInBranch{$startFile}}, $startRevisionId);
    
    my %mrFiles = Find_Files_In_MR($dbh, $startMRid);
    
    
    foreach my $file (sort keys %mrFiles) {
	# let us check if the file,revision is already there. It should not!
	if (not Revision_In_Set($mrFiles{$file}, @{$filesInBranch{$file}})) {
	    print "Added file: $file, $mrFiles{$file}\n"
		if $verbose;
	    push( @{$filesInBranch{$file}}, $mrFiles{$file});
	}
    }
    
    my %mrsInBranch = ($startMRid => 1);
    
#foreach my $file (sort keys %filesInBranch) {
#    print "File: $file, @{$filesInBranch{$file}}\n"; 
#}
    
    
    my $notDone = 1;
    
    my $depthBranch = Compute_Depth_Branch($startRevisionId);
    
    while ($notDone) {
	$notDone = 0;
	my $size = scalar(keys %filesInBranch);
	print "Looping $size \n";
	while (my ($fileName,$revisionId) = Find_Candidate_Backwards(%filesInBranch)) {
	    
	    print "[Candidate $fileName, $revisionId] " if $verbose;
	    
	    my $mr;
	    
	    # Scan MrFiles and see if there is one filename for which we don't have
	    # the first revision
	    if (not $mr = Find_MRId($dbh, $fileName, $revisionId)) {
		$dbh->disconnect;
		die "Unable to find [$fileName, $revisionId]\n";
		
	    }
	    
	    $mrsInBranch{$mr} = 1;
	    my %mrFiles = Find_Files_In_MR($dbh, $mr);
	    
	    
	    foreach my $file (sort keys %mrFiles) {
		# let us check if the file,revision is already there. It should not!
		my $rev = $mrFiles{$file};
		if ($depthBranch > Compute_Depth_Branch($rev)) {
		    my $thisDepth = Compute_Depth_Branch($rev);
		    print STDERR "Weird revision [$rev] [$file] [$mr] [$depthBranch][$thisDepth]\n";
		    print "*****Weird revision [$rev] [$file] [$mr] [$depthBranch][$thisDepth] skipping!\n";
		} 
		if (not Revision_In_Set($rev, @{$filesInBranch{$file}})) {
		    print "    Added backward file: $file, $mrFiles{$file}\n"
			if $verbose;
		    $notDone = 1;
		    
		    push( @{$filesInBranch{$file}}, $rev);
		}
	    }
	}
	
	
	print "Processing files for later additions\n" if $verbose;

	while (my $mr = Find_Candidate_MR_Forward($dbh, \%MarkFilesDone, %filesInBranch)) {
	    
	    print "Found a new  mr: [$mr]\n" if $verbose;
	    my %mrFiles = Find_Files_In_MR($dbh, $mr);
	    
	    foreach my $file (sort keys %mrFiles) {
		# let us check if the file,revision is already there. It should not!
		my $rev = $mrFiles{$file};
		
		if ($depthBranch > Compute_Depth_Branch($rev)) {
		    my $thisDepth = Compute_Depth_Branch($rev);
		    print STDERR "Weird (Forward) revision [$rev] [$file] [$mr] [$depthBranch][$thisDepth]\n";
		    print "*****Weird (Forward) revision [$rev] [$file] [$mr] [$depthBranch][$thisDepth] skipping!\n";
		} elsif (not Revision_In_Set($rev, @{$filesInBranch{$file}})) {
		    print "   Added forward file: $file, $mrFiles{$file}\n"
			if $verbose;
		    $notDone = 1;
		    push( @{$filesInBranch{$file}}, $rev);
		}
	    }
	    $mrsInBranch{$mr} = 1;
	    
	}
    }
    return %filesInBranch;

}



__END__

=head1 NAME

find-files-in-branch.pl - Insert into a given set of revisions into the database

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
