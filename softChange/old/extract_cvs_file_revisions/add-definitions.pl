#!/usr/bin/perl

use DBI;
use strict;

my $useIndent = 0;

my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}


my $userName = 'dmg';

my $TMP_FILE = "/tmp/add-definitions-$$-temp.";

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});



my $sth = $dbh->prepare(" select files.filename, filerevisions.revisionid, 
                                 filerevisions.state, files.extension,
                                 filerevisions.newfile, filerevisions.cleanfile
                          from filerevisions, files 
                            where filerevisions.filename = files.filename and
                                 cleanLines > 0 and
                                (extension in ('.cpp', '.java', '.c'))");

#my $lastHandler = $dbh->prepare(" select max(index) from
#                                            from revdefs
#                                         where filename = ? and
#                                               revisionid = ? and
#                                               definition = ? ");
#
#
#

my $rc = $sth->execute;

my @row;

while ( @row = $sth->fetchrow_array ) {
    my ($filename, $revision, $state, $extension,$file, $cleanFile) = @row;
    $filename =~ s/\s+$//;
    $revision =~ s/\s+$//;

    print "$filename, $revision,$state, $extension\n" ;

# Indent

    $TMP_FILE = "/tmp/add-definitions-$$-temp" . $extension;

    my $checkHandler = $dbh->prepare(" select count(*) from revdefs
                                         where filename = ? and
                                               revisionid = ?");

    $checkHandler->execute($filename, $revision);

    if (my @result = $checkHandler->fetchrow_array) {
	if ($result[0] > 0) {
	    print STDERR "This file,rev has been already added: [$filename] [$revision]. There are $result[0] definitions already\n" ;
	    next;
	}
    }

    if ($useIndent) {
	open (OUT, "|indent > $TMP_FILE") ||  die "Unable to create output file [$TMP_FILE]\n";
    } else {
	open (OUT, ">$TMP_FILE") || die "Unable to start indent and create output file\n";
    }

    print OUT $file;

    close (OUT);

# extract tags
# First we do with normal lines

#    print "To execute ectags.. [$TMP_FILE]\n";

    open(TAGS, "ectags -x $TMP_FILE|") || die "Unable to execute ectags on file [$filename] [$TMP_FILE]\n";

    my $last = "";

    while (<TAGS>) {

#	print "  -> $_\n";

# The result has 5 fields...
	my ($name, $type, $line) = Split_ECTags_Result($_, $TMP_FILE);
	my $index = 0;

	if ($type eq "member") {
	    $name = "${last}.${name}";
	} else {
	    $last = $name;
	}

	print "    $name, $type, $line ...";
	
	my $lastHandler = $dbh->prepare(" select max(index)
                                            from revdefs
                                         where filename = ? and
                                               revisionid = ? and
                                               definition = ? ");


        $lastHandler->execute($filename, $revision, $name);
	
	if (my @result = $lastHandler->fetchrow_array) {
	    $index = $result[0]+1;
	}

	my $insert = $dbh->prepare("INSERT INTO revdefs(filename,revisionid,line,definition,index,typedef) VALUES (?,?,?,?,?,?)");

	my $x = $insert->execute( $filename, $revision, $line, $name, $index, $type);

	print "... inserted [$x]\n";


    }
    close TAGS;
# then we remove comments and empty lines
# mangle (remove comments)

# I need to indent first

    my $exitCode;


    open (OUT, ">$TMP_FILE") || die "Unable to create output file [$TMP_FILE] 2\n";
    print OUT $cleanFile;
    close (OUT);

    open(TAGS, "ectags -x $TMP_FILE|") || die "Unable to execute ectags on mangled file [$filename] [$TMP_FILE]\n";
    my $last = "";
    
    while (<TAGS>) {
	
# The result has 5 fields...
	my ($name, $type, $line) = Split_ECTags_Result($_, $TMP_FILE);
	my $index = 0;

	if ($type eq "member") {
	    $name = "${last}.${name}";
	} else {
	    $last = $name;
	}

	print "    $name, $type, $line ...";
	
	#we need to make sure that the record is there (in the normal lines one)
	
	my $lastHandler = $dbh->prepare(" select min(index)
                                            from revdefs
                                         where filename = ? and
                                               revisionid = ? and
                                               definition = ?  and 
                                               typedef = ? and cleanLINE is NULL");
	
	$lastHandler->execute($filename, $revision, $name, $type);
	
	if (my @result = $lastHandler->fetchrow_array) {
	    $index = $result[0];
	} else {
	    die "There is an error. We have one definition in [$filename, $revision, $name, $type] mangled, with no corresponding one in other\n";
	}
	    
	#update the cleaLOCS line
	my $insert = $dbh->prepare("UPDATE revdefs set cleanLine = ? " . 
				   "where filename = ? and revisionid = ? and definition = ? and " . 
				   "index = ? and typedef = ?");
	
	$insert->execute( $line, $filename, $revision, $name, $index, $type);
	
	print "   ... updated\n";
    }

}

$dbh->disconnect;

unlink $TMP_FILE;



sub Split_ECTags_Result
{
    my ($record, $fileName) = @_;
    
    $fileName =~ s/ +$//;
    if (not $record =~ / $fileName/) {
	die "Illegal record in output of ctags [$_][$fileName]\n";
    }
    $record = $`;

    if (not $record =~ /^(.+)\s+([^ ]+)\s+([0-9]+)$/) {
	die "Illegal record (2) in output of ctags [$record]\n";
    }
    my ($id,$type, $line) = ($1, $2, $3);

    $id =~ s/ +$//;

    return ($id,$type, $line);
}
