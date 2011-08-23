#!/usr/bin/perl


# format of the output (stdout)

#   filename,   -- the full file name
#   basename,   -- only filename, without extension
#   extension   -- extension
#   directory   -- directory where the file is
#   latest version -- latest cvs version
#   branch version -- branch, if it exists
#   totalrevisions -- total number of revisions
#   selected revisions -- I don't really know what this is
#   inAttic (0 or 1)   -- 0/1 whether the  file is in the attic
#   rcsfilename        -- full path name of the RCS file (no ,v at the end)
#   module      -- first level directory where it appears?


# REVISIONS (to revisions.txt)

#  file  -- full file name (see above)
#  revisionId -- id of the revision
#  date       -- date when it hapend
#  author     -- userid of who made the change
#  state      -- I don't really know what this is
#  linesAdded -- number of lines added
#  linesDeleted -- number of lines deleted
#  rev          -- actual log of the change


# TODO: Make it faster. Concatenation makes it very slow --see uses of $'

# Fix the processing of the revisionlog
# Fix the extension generation: -sh, -types -sh, -h

use strict;
use File::Basename;
use Getopt::Long;
use Pod::Usage;

my $verbose = 0;
my $debug   = 0;
my $noAttic = 0;
my $extractRevisions = 1;

my $dirPrefix = ""; # just in case this we want to remove a prefix to
		    # the filenames

my $revisionsFileName = "cvs.revisions";
my $filesFileName = "cvs.files";
my $man = 0;
my $help = 0;

GetOptions("verbose"		  => \$verbose,
	   "debug"		  => \$debug,
	   "noAttic"		  => \$noAttic,
	   "dirprefix=s"	  => \$dirPrefix,
	   "extractRevisions"	  => \$extractRevisions,
	   "help"                 => \$help,
	   "man"                  => \$man,
	   "revisionsFileName=s" => \$revisionsFileName,
	   "filesFileName=s" => \$filesFileName,
	   ) or pod2usage(2);

pod2usage(1) if $help;
pod2usage(-verbose => 2) if $man;

pod2usage(1) if scalar(@ARGV) ==0 ;

# All these extensions are .XYZ
my $periodExtensions = "(m4|c|h|png|in|sh|am|ics|glade|im|txt|ps|" .
    "xml|xpm|sgml|dat|urls|pl|types|vcf|java|uml|" .
    "gif|jpg|" .
    "html|gnorba|oat|db|y|oafinfo|idl|po|pm|" .
    "log|jpg|msg|galview|cvsignore|list|csv|" .
    "def|ps|l|tab|wav|dia|lyx|TXT|i|schema|1|" .
    "make|gladep|mt|mime|out|omf|oaf|table|e-table)";
# These "extensions" do not have a .
my $otherExtensions = "ChangeLog|TODO|README|mbox|LICENSE|NEWS|AUTHORS|INSTALL|THANKS";

$/ = "=============================================================================\n\nRCS file: ";



# if revisions... prepare file

my $totalBytes = 0;
my $readBytes = 0;


if ($verbose) {
    # Estimate number of bytes to process. This will give us an idea of how
    # much we have to do
    $totalBytes = Estimate_Total_Size(@ARGV);
}


if ($extractRevisions) {
    open(REV, ">$revisionsFileName") or
	die "Unable to create revisions filename $revisionsFileName $!\n";
}

open(FILES, ">$filesFileName") or
	die "Unable to create revisions filename $filesFileName $!\n";


while (my $fileName = shift) {
    Process_Log_File($fileName);
}


if ($extractRevisions) {
    close (REV);
}

close FILES;

exit 0;


sub Process_Log_File
{
    my ($fileName) = @_;
    my ($countFiles, $revisions);

    open (IN, $fileName) || die "Unable to open input file $fileName\n";

    while (<IN>) {


	# If it is the last record in the file, that means that it has a 
	#=============================================================================
	#at the end, then remove it
	if ($_ =~ s/\n=============================================================================\n$/\n/so) {
	    print STDERR "Removed last line\n";
	}

	if ($verbose && $countFiles % 10 == 0) {
	    Display_Progress();
	}

	my $inAttic = 0;

	chomp;

	my $record =$_;

	die "Illegal file record $_,v\n" unless /^([^\n]+),v\nWorking file: ([^\n]+)\n/m;
	my $fileName = $2;
	my $rcsFile = $1;

# We really don't want to look at the attic, do we?
# ok, give the user the choice. and mark it in the output

	if (m@Attic@) {
	    next if $noAttic;
	    $inAttic = 1;
	}

# extract some other data

	my ($thisFileRevisions,$selectedRevisions) = Extract_Revisions_Count($record);

	if ($thisFileRevisions > 0) {
	    
	    # Some files have no revisions
	    
	    $revisions+=$thisFileRevisions;
	    
	    
	    my ($head, $branch) = Extract_Latest_Version($record);
	    
	    
	    # remove prefix
	    $fileName =~ s/^$dirPrefix//;
	    
	    $countFiles++;
	    my ($base, $dir, $ext) = fileparse($fileName, "(\\.$periodExtensions|$otherExtensions)");
	    
	    my $module = $dir;
	    
	    if ($module =~ m@/@) {
		
		$module =~ s@/.*@@;
	    }
	    
#output the information
	    
	    print FILES  "$fileName;$base;$ext;$dir;$head;$branch;" .
		"$thisFileRevisions;$selectedRevisions;$inAttic;$rcsFile;$module\n";
	    
	    print STDERR "$fileName; $head; $branch: Ext $ext\n" if $debug;
	    
	    # do we need revisions?
	    if ($extractRevisions) {
		Extract_Revisions($record, $fileName, $thisFileRevisions);
	    }
	    
	}
    }
    Update_Progress();
    print STDERR "Processed $countFiles files in $fileName\n" if $verbose;
    close IN;

    return ($countFiles, $revisions);
}


sub Extract_Latest_Version
{
    my ($record) =@_;

    if (!/\nhead: ([^\n]+)\nbranch: *([^\n]*)\n/mo) {
	# This record looks illegal..
	die "Illegal record [$record]. It has no version information\n";
    }
    return ($1, $2);
}


sub Extract_Revisions_Count
{
    my ($record) =@_;

    if (not ($record=~ /\ntotal revisions: ([0-9]+);[ \t]+selected revisions: ([0-9]+)/o)) {
	# This record looks illegal..
	die "Illegal record [$record]. It has no revisions information\n";
    }
    return ($1, $2);
}


sub Extract_Revisions
{
    my ($record,$fileId, $totalRevisions) =@_;

    #find beginning of revisions
    if (not $record =~ /\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\n(revision [0-9\.]+)/mo) {
	die "invalid record. NO revisions [$record]\n";
    }
    $record = $1 . $'; #'
#    $record = "revision $1" . $2; #'
#    print STDERR "REvision [$record]\n" if $debug;
    Process_Revisions($record, $fileId, $totalRevisions);
}

sub Process_Revisions
{
    my ($revisions,$fileId, $totalRevisions) =@_;
    my $revisionsCounter = 0;
    my $previousRevId = "";

    print STDERR "->revision entry [$revisions]\n" if $debug;

    while ($revisions ne "") {
	my $rev;
	my $linesAdded = "";
	my $linesDeleted = "";
	my $date;
	my $state;
	my $revisionId;
	my $author;

#	if ($revisions =~ /revision ([0-9\.]+)\ndate ([^;]+); +author: ([^;]+) +state: ([^;]+)/o) {
	if ($revisions =~ /^revision ([0-9\.]+)\ndate: ([^;]+); +author: ([^;]+); +state: ([^;]+);(.*)$/os) {
	    ($revisionId, $date, $author, $state) = ($1, $2, $3, $4);
#	    $revisions =$'; #'
	    $revisions = $5;
#	    print STDERR "->revision [$1]\n" if $verbose > 1;
	} elsif ($revisions =~ /^revision ([0-9\.]+)[ \t]*locked by: [^;]+;\ndate: ([^;]+); +author: ([^;]+); +state: ([^;]+);(.*)$/os) {
	    ($revisionId, $date, $author, $state) = ($1, $2, $3, $4);
	    $revisions =$'; #'
	    $revisions = $5;
	    print STDERR "->revision [$1]\n" if $verbose > 1;
	} else  {
	    die "Looks like an invalid revision header [" . substr($revisions, 0, 100) . "]\n";
	}
	# Increase counter

	$revisionsCounter++;

	if ($revisions =~ /^ +lines: ([0-9+-]+) ([0-9+-]+)\;?\n(.*)$/os) {
	    # sometimes the records contain no lines
	    $linesAdded = $1;
	    $linesDeleted = $2;
	    $revisions = $3; #'
	} else {
#	    print STDERR "NO LINES: ->revision [$revisions]\n";
	}

	# We try to find the marker terminating the revision
	if ($revisions =~ /\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\n(revision .*)$/os) {
	    $revisions = $1;
	    $rev = $`;
	} else {
	    # this is the last revision
	    $rev = $revisions;
	    $revisions = "";
	}

	$rev =~ s/\r//g;  #eliminate \r's in case they exists

	$rev =~ s/^\n?branches: .*/\n/;

	# remove multiple heading EOL
	$rev =~ s/^\n+//go;
	# remove multiple trailing EOL
	$rev =~ s/\n+$/\n/go;
#
	# Replace problematic characters
	$rev =~ s/\n/NEWLINE/go;
	$rev =~ s/;/SEMICOLON/go;
	$rev =~ s/\\/BACKSLASH/go;

	if ($revisionId eq $previousRevId) {
	    print STDERR "$fileId;$revisionId is duplicated! Skipping\n";
	} else {
	    print REV "$fileId;$revisionId;$date;$author;" ;
	    print REV $state;
	    printf REV ";%d;%d;",  $linesAdded,$linesDeleted;
	    print REV "$rev\n";
	}
	$previousRevId = $revisionId;

    }
    print STDERR "Found $revisionsCounter revisions out of $totalRevisions\n" if $debug;

    print STDERR "Mmmm Total revisions differ from the number of revisions we are extracting [$fileId] [$totalRevisions][$revisionsCounter]\n" if $totalRevisions != $revisionsCounter;

#\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\n

}

sub Estimate_Total_Size
{
    my @fileList = @_;
    my $total = 0;

    foreach my $fileName (@fileList) {

	my ( $dev, $ino, $mode, $nlink,
	     $uid, $gid, $rdev, $size,
	     $atime, $mtime, $ctime,
	     $blksize, $blocks ) = stat($fileName)
	or die "file $fileName cannot be open: $!";
	$total += $size;
    }
    return $total;
}


sub Update_Progress
{
    $readBytes += tell(IN);
}


sub Display_Progress
{
    my $thisFileBytes = tell(IN);
    my $currentBytes = $readBytes + $thisFileBytes;

    printf("Progress: %5.2f\n" , ($currentBytes * 100.0) / ($totalBytes * 1.0));
}


__END__

=head1 NAME

sample - Using GetOpt::Long and Pod::Usage

=head1 SYNOPSIS

$0 [options] cvsLogFile...

 Options:
   --help                 Brief help message
   --man                  Full documentation
   --verbose              Display some useful progress messages
   --noAttic              Do not show records in the attic
   --dirprefix=s          Remove the given prefix from the front of each filename
   --revisionsFileName=s  Output filename for revisions

 cvsLogFile               File generated by cvs log

=head1 OPTIONS

=over 8

=item B<--help>

Print a brief help message and exits.

=item B<--man>

Prints the manual page and exits.

=item B<--verbose>

Show messages showing progress

=item B<--noAttic>

Ignore the files in the attic. For each directory, CVS maintains an
area (called the attic) where it moves files as they are "deleted"
from the module. By default, the attic is processed.

=item B<--dirprefix=dirname>

This option will allow you to remove a prefix from full filename.

=item B<--revisionsFileName=filename>

Name of the file with the revisions. Default cvs.revisions. Run $0
--man for an description of the format of this file.

=item B<--filesFileName=filename>

Name of the file with the files. Default cvs.files. Run $0
--man for an description of the format of this file.


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
