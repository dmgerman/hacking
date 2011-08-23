#!/usr/bin/perl

#format of output

#input revisions.txt (sorted by developer, date)
# FOrmat of output

# id
# filename
# CVS Revision number
# userid
# date
# autohr
# index in revision (1..no of files in revision)
# CVS log entry

use strict;
use Time::Local;
use Getopt::Long;
use Pod::Usage;


my $windowSeconds=600;
my $debug = 0;
my $verbose = 0;
my $timeOffset = 45;
my $man = 0;
my $help = 0;
my $fileName = "cvs.mrs";
my $dontSort = 0;

GetOptions("window=i"      	       => \$windowSeconds,
	   "debug"     	   	       => \$debug,
	   "secondsBetweenRevisions=i"                 => \$timeOffset,
	   "verbose"                   => \$verbose,
           "help"                 => \$help,
	   "dontSort"             => \$dontSort,
           "man"                  => \$man,
 	   "mrFileName=s"             => \$fileName,
	   );

pod2usage(1) if $help or $windowSeconds<=0;
pod2usage(-verbose => 2) if $man;

pod2usage(1) if scalar(@ARGV) ==0 ;

# first, let us sort the file. We use sort to do that. We expec the following input:

#  file  -- full file name (see above)
#  revisionId -- id of the revision
#  date       -- date when it hapend
#  author     -- userid of who made the change
#  state      -- I don't really know what this is
#  linesAdded -- number of lines added
#  linesDeleted -- number of lines deleted
#  rev          -- actual log of the change 

# And we need it sort them by author, date

my $tempFileName = "$fileName.sorted.temp.$$";

$SIG{INT}  = \&Got_Signal_Quit;
$SIG{QUIT}  = \&Got_Signal_Quit;
    
my $command = "";
my $createdTemporal = 0;
if (scalar (@ARGV) > 1 || !$dontSort) {
    $createdTemporal = 1;
    if (! $dontSort) {
	$command  = "sort -t ';' -k 4,4 -k 8,8 -k 3,3  @ARGV > $tempFileName";
    } else {
	$command  = "cat @ARGV > $tempFileName";
    }
    print STDERR "About to execute external sort [$command]\n" if $verbose;
    
    system($command) == 0 or die "sort [$command] failed: $?\n";
} else {
    $tempFileName = $ARGV[0];
}

my %usedKeys;
# count lines
my $totalLines=0;

if ($verbose) {
    $totalLines = `wc -l $tempFileName`;

    chomp $totalLines;

    print STDERR "Starting to process the file ($totalLines total lines)\n";
}

open (IN, "<$tempFileName") or die "Unable to open temporal file $!\n";
open (OUT, ">$fileName") or die "unable to create output file $!\n";

my $FILE = 0;
my $REVID = 1;
my $DATE = 2;
my $DEVELOPER = 3;
my $LOGENTRY = 7;

my $previousDeveloper = "";
my $timeFirstRevisioninMR = 0;
my $MR=0;
my $count = 0;
my $previousLogEntry = 0;
my $previousTime =0;
my $key = "";
my %files;

while (<IN>) {
    my $saveRecord = $_;


    chomp;
    $count++;
    my @fields = split(/;/);

    # remove newlines at beginning and end
# No longer needed, as I have fixed extractFiles
#    $fields[$LOGENTRY] =~ s/^NEWLINE//;
#    $fields[$LOGENTRY] =~ s/NEWLINE$//;


    if ($verbose && $count % 1000 == 0) {
	printf STDERR ("Processed $count out of $totalLines (%5.2f\%)\r", #%
		       (100.0 *$count )/ $totalLines );
    }

    # Remove "branches: " line.
#    $fields[$LOGENTRY] =~ s/^branches: +[0-9\.]+SEMICOLONNEWLINE//;

#    my $temp = $fields[$LOGENTRY];
#    print STDERR  "LOG:$temp\n"

#    $fields[$LOGENTRY] =~ s/^NEWLINE//;


    my ($yyyy, $mm, $dd, $hr, $min, $secs) = 
	($fields[$DATE] =~ m@(\d+)[/\-](\d+)[/\-](\d+) (\d+):(\d+):(\d+)@);
# calculate epoch seconds at midnight on that day in this timezone
    
#    print "Values for all of them year $yyyy, mm $mm, dd $dd, hr $hr, min $min, sec $secs\n";
    

    my $epochSeconds = timelocal($secs, $min, $hr, $dd, $mm-1, $yyyy-1900);

    my $diff = $epochSeconds - $timeFirstRevisioninMR;

    if ($previousDeveloper ne $fields[$DEVELOPER] ||
	$previousLogEntry ne $fields[$LOGENTRY] ||
	defined($files{$fields[$FILE]}) ||
	$epochSeconds - $previousTime > $timeOffset ||
	$epochSeconds  > $timeFirstRevisioninMR + $windowSeconds) {
	# New transaction
	$MR++;
	undef %files;
	$key = "$fields[$DEVELOPER]:$fields[$DATE]";
	if (defined($usedKeys{$key})) {
	    $key  .= "_" . $usedKeys{$key}++;
	} else {
	    $usedKeys{$key} = 1;
	}
	$files{$fields[$FILE]} = 1;
	$previousLogEntry = $fields[$LOGENTRY] ;
	$previousDeveloper = $fields[$DEVELOPER] ;
	$timeFirstRevisioninMR = $epochSeconds;
    }
    $previousTime = $epochSeconds;

    # split DATE into DATE and TIME
    $fields[$DATE] =~ s/ /;/;


    print OUT "$key" or die "write error $!\n";
    for my $a (0..3,7) {
	print OUT ";$fields[$a]" or die "write error $!\n";
    }
    print OUT "\n";
}
print STDERR "\nMRs: $MR, from $count revisions\n" if $verbose;

close (IN);

close BRANCHES;

if ($createdTemporal) {
    unlink($tempFileName);
}

exit 0;


sub Got_Signal_Quit
{
    print STDERR "Interrupted\n";
    unlink $tempFileName;
    exit (1);
}


__END__

=head1 NAME

sample - Using GetOpt::Long and Pod::Usage

=head1 SYNOPSIS

$0 [options] cvs.revisions

 Options:
   --help                  Brief help message
   --man                   Full documentation
   --debug  	   	   Display debugging messages
   --verbose               Display some useful progress information
   --window=<seconds>      Maximum number of seconds for the total 
                           length of a MR
   --secondsBetweenRevisions=<seconds> Maximum number of seconds
                           between 2 revisions 
   --mrFileName=<filename> Filename for output

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

  B<This program> will take as an input a file generated by running CVS
  log in a module. It creates two filenames as output:

  revisions.txt which contains each of the revisions for each of the
  files. The format of the output is:

  file                  -- full file name (matches filenames.txt)
  revisionId            -- id of the revision
  date                  -- date when it hapend
  author                -- userid of who made the change
  state                 -- I don't really know what this is
  linesAdded            -- number of lines added
  linesDeleted          -- number of lines deleted
  rev                   -- log message given to cvs commit

  the filenames.txt file contains the files in the log:

  filename,             -- the full file name (matches revisions.txt)
  basename,             -- only filename, without path or extension
  extension             -- extension
  directory             -- directory where the file is
  latest version        -- latest cvs version
  branch version        -- branch, if it exists
  totalrevisions        -- total number of revisions
  selected revisions    -- I don't really know what this is
  inAttic (0 or 1)      -- 0/1 whether the  file is in the attic
  rcsfilename           -- full path name of the RCS file 
                           (no ,v at the end)


  Files are ; delimited, one record per line. The character \b is
  replaced with NEWLINE and ; is replaced with SEMICOLON


=cut
