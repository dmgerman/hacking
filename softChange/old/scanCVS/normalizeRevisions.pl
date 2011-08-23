#!/usr/bin/perl


# THIS FILE Create the file to import into SQL (see revisions.sql)

open (OUT, ">cvsNORM.revisions.tmp") || die "uanble to create normalized file\n";

while (<>) {
    chomp;
    @fields = split(/;/);
    ($day, $time) = split(/ /, $fields[2]);
#    foreach $a (0,1) , 4, 5, 6)
    print OUT "$fields[0];$fields[1];";
    print OUT "$day;$time;";
    print OUT "$fields[4];$fields[5];$fields[6]\n"
}

close OUT;

print `sort -u cvsNORM.revisions.tmp > cvsNORM.revisions.tmp2`;

open (IN, "<cvsNORM.revisions.tmp2") || die "uanble to open temp file\n";
open (OUT, ">cvsNORM.revisions") || die "uanble to open output revisions file\n";

my $prevFile = "";
my $prevRev = "";
while (<IN>) {
    my $row = $_;
    chomp;
    @fields = split(/;/);
    ($day, $time) = split(/ /, $fields[2]);
#    foreach $a (0,1) , 4, 5, 6)
    if ($prevFile eq $fields[0] and
	$prevRev eq $fields[1]) {
	print STDERR "Duplicated revision $prevFile:$prevRev, skipping\n";
    } else {
	$prevFile = $fields[0];
	$prevRev = $fields[1];

	print OUT "INSERT INTO revisions (filename, revid, daterev, inTrunk, trunkRevId, deleted) VALUES ";

	if ($fields[4] eq 'dead') {
	    $deleted = 'TRUE';
	} else {
	    $deleted = 'FALSE';
	}

	if ($fields[1] =~ /^1\.([0-9]+)$/) {
	    $inTrunk = 'TRUE';
	    $trunkRevId = $1;
	} else {
	    $inTrunk = 'FALSE';
	    $trunkRevId = "NULL";
	}


	print OUT "('$fields[0]', '$fields[1]', '$fields[2] $fields[3]', $inTrunk, $trunkRevId, $deleted);\n";

#	print STDERR "$prevFile:$prevRev\n";
    }
}

close OUT;
close IN;
# we need to verify that there are no duplicated records

`rm -f cvsNORM.revisions.tmp`;
`rm -f cvsNORM.revisions.tmp2`;

