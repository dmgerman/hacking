#!/usr/bin/perl

# initialize the parser with references to handler routines
#

#CONSTANTS


use File::Basename;
use XML::Parser;
use strict;

print join (":", @ARGV);

if (scalar(@ARGV) != 2) {
    print "Arguments # " , scalar(@ARGV), "\n";

    die "usage <prefixToRemoveFromFilename> <logFile>\n";
}

my $filePrefix = shift @ARGV;

print "Fileprefix $filePrefix\n";


print "Make sure its input is created using cvs log --verbose --xml\n";

my $periodExtensions = "(m4|c|h|png|in|sh|am|ics|glade|im|txt|ps|" .
    "xml|xpm|sgml|dat|urls|pl|types|vcf|java|uml|" .
    "gif|jpg|" .
    "html|gnorba|oat|db|y|oafinfo|idl|po|pm|" .
    "log|jpg|msg|galview|cvsignore|list|csv|" .
    "def|ps|l|tab|wav|dia|lyx|TXT|i|schema|1|" .
    "make|gladep|mt|mime|out|omf|oaf|table|e-table)";
# These "extensions" do not have a .
my $otherExtensions = "ChangeLog|TODO|README|mbox|LICENSE|NEWS|AUTHORS|INSTALL|THANKS";



my $parser = XML::Parser->new( Handlers => {
    Init =>    \&handle_doc_start,
    Final =>   \&handle_doc_end,
    Start =>   \&handle_elem_start,
    End =>     \&handle_elem_end,
    Char =>    \&handle_char_data,
});

#
# globals
#
my $record;       # points to a hash of element contents
my $context;      # name of current element
my %records;      # set of address entries
my %files;
#
# read in the data and run the parser on it
#
my $file = shift @ARGV;
if( $file ) {
    $parser->parsefile( $file );
} else {
    my $input = "";
    while( <STDIN> ) { $input .= $_; }
    $parser->parse( $input );
}
exit;



###
### Handlers
###

#
# As processing starts, output the beginning of an HTML file.
# 
sub handle_doc_start {
    print "This are the records\n";

    open(MSR, ">cvsNORM.mrs") or die 'unable to create msr file';
    open(REVS, ">cvsNORM.revisions") or die 'unable to create revs file';
    open(FILESMRS, ">cvsNORM.filesmrs") or die 'unable to create filesmrs file';
    open(FILES, "|sort -u >cvsNORM.files") or die 'unable to create files file';

}

#
# save element name and attributes
#
sub handle_elem_start {
    my( $expat, $name, %atts ) = @_;
    $context = $name;
    if ($name eq 'path') {
#	print "$name:[$atts{action}]\n";
	if ($atts{action} eq "D") {
	    $record->{deleted} = 'TRUE';
	} elsif ($atts{action} eq "A" or 
		    $atts{action} eq "M") {
	    $record->{deleted} = 'FALSE';
	} else {
	    die "Unknown code $atts{action}";
	}
    }
    if( $name eq 'logentry' ) {
	$record = {} ;
	$record->{mrid} = $atts{revision};
    }
} 

# collect character data into the recent element's buffer
#
sub handle_char_data {
    my( $expat, $text ) = @_;

    $text =~ s/\n/NEWLINE/mg;
    $text =~ s/\\'/<QUOTE>/g;
    $text =~ s/'/<QUOTE>/g;
    $text =~ s/<QUOTE>/''/g;
    if ($context ne "" ) {
	$record->{ $context } .= $text;
    }
}

#
# if this is an <entry>, collect all the data into a record
#
sub handle_elem_end {
    my( $expat, $name ) = @_;

    $context = "";
    if ($name eq 'date') {
	$record->{date} =~ s/\..*$//m;
	$record->{date} =~ s/T/ /;
	die if $record->{date} =~ /NEWLINE/;
    }

    if ($name eq 'path') {

	Process_File();
	$record->{path} = "";
    }
    
    if ($name eq 'logentry') {
	print MSR <<END;
INSERT INTO mrs(mrid, datemr, author, log) VALUES \('$record->{mrid}','$record->{date}','$record->{author}', '$record->{msg}');
END



    }
}

#
# Output the close of the file at the end of processing.
#
sub handle_doc_end {
    close MSR;
    close REVS;
    close FILESMRS;
    close FILES;
    print "end\n\n";
}


sub Process_File {
    $record->{path} =~ s/^$filePrefix//;


# ok we got a file
    print REVS <<END
INSERT INTO revisions (filename, revid, daterev, inTrunk, trunkRevId, deleted) VALUES ('$record->{path}', '$record->{mrid}', '$record->{date}', TRUE, $record->{mrid}, '$record->{deleted}');

END
    ;
#INSERT INTO revisions (filename, revid, daterev, inTrunk, trunkRevId, deleted) VALUES ('.cvsignore', '1.1', '2007/12/07 19:35:49', TRUE, 1, FALSE);

    print FILESMRS <<END;
INSERT INTO revsInMr(mrid, filename, revid) VALUES('$record->{mrid}','$record->{path}', '$record->{mrid}');
END
    ;
#INSERT INTO revsInMr(mrid, filename, revid) VALUES('dmg:2008/01/25 10:54:32','msr.tex','1.10');

    # we need to determine filename, basename, extension, etc
    my ($base, $dir, $ext) = fileparse($record->{path}, "(\\.$periodExtensions|$otherExtensions)");

    print FILES <<END;
INSERT INTO files(filename, basename, extension, directory) VALUES('$record->{path}','$base', '$ext','$dir');
END
    
#INSERT INTO files(filename, basename, extension, directory, inattic) Values ('.cvsignore','','.cvsignore','./',FALSE);



}
