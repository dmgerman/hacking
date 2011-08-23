#!/usr/bin/perl
#print $0;
$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;


use DBI;
use strict;

my $dryRun = 0; # do not compute diffs
my $dbName = $ARGV[0];

if ($dbName eq "") {
    die "$0 <dbName>\n";
}

my $userName = 'dmg';

my $TMP_FILE = "/tmp/$$-temp.c";

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});


my $sth = $dbh->prepare("select mrid from mrfuncstats   where add > 0 and del > 0  and mrid <> 3626 order by mrid ;");
my $rc = $sth->execute;

while ( my @row = $sth->fetchrow_array ) {
    Do_MR($row[0]);
}


$dbh->disconnect;

unlink $TMP_FILE;

exit 0;



sub Do_MR
{
    my ($mrid) = @_;
    print STDERR "Doing MR [$mrid]\n";
    
#    my $sth = $dbh->prepare("select filename, function, sizebefore from funcmod where revid = ? and typemod = 'D' order by filename, function;");
#    my $rc = $sth->execute($mr);
#
#    my @deleted;
#    while ( my @row = $sth->fetchrow_array ) {
##	print "$row[0],$row[1],$row[2]\n";
#	push @deleted, [@row];
#    }
#
##    die;
#    print "-----------------------\n";

    my @deleted = Get_Functions($mrid, 'D', "linesdel");

    my @added = Get_Functions($mrid, 'A', "linesadd");

    my @done;
    my $index = 0;
    my @what;
    my @todo;
    my @todoAfter;

    foreach my $b (@added) {
	$todoAfter[$index] = 1;
	$index ++;
    }
    $index = 0;

    foreach my $b (@deleted) {
	$todo[$index] = 1;
#	print STDERR join(":",@$b);
#	print STDERR "\n";

	my $j = 0;
	my $matched = 0;
	foreach my $a (@added) {
	    # first check that they are the in the same file
	    if ($$a[0] eq $$b[0]) {
		if ($$a[1] eq $$b[1] ||
		    Is_Renamed($mrid, $$a[1], $$b[1])
		    ) {
		    $what[$index] = ['moved', $$a[1]];
		    print "$mrid:MovedSame:",  $$b[1], ":", $$b[0],":", $$b[2],":", $$a[1], ":", $$a[0],":", $$a[2];
		    if ($$b[2] != $$a[2]) {
			print ":Warning\n";
		    }
		    print "\n";
		    $todo[$index] = 0;
		    $todoAfter[$j] = 0;
		    #we are done for this function
		    $matched = 1;
		    last;
		}
	    }
	    $j++;
	}
	if (! $matched) {
	    $j = 0;
	    foreach my $a (@added) {
		#if not then check in another file
		if ($$a[1] eq $$b[1] ||
		    Is_Renamed($mrid, $$a[1], $$b[1])
		    ) {
		    $what[$index] = ['moved', $$a[1]];
		    print "$mrid:MovedDiff:",  $$b[1], ":", $$b[0],":", $$b[2],":", $$a[1], ":", $$a[0],":", $$a[2];
		    if ($$b[2] != $$a[2]) {
			print ":Warning\n";
		    }
		    print "\n";
		    $todo[$index] = 0;
		    $todoAfter[$j] = 0;
		    last;
		}
		$j++;
	    }
	}
	$index ++;

    }
    
    $index = 0;
    foreach my $b (@deleted) {
	if ($todo[$index]) {
	    print "$mrid:Before:", join(":", @$b), "\n";
	}
	$index ++;
    }
    $index = 0;
    foreach my $b (@added) {
	if ($todoAfter[$index]) {
	    print "$mrid:After:", join(":", @$b), "\n";
	}
	$index ++;
    }

 #   print STDERR  "---------------------------\n";


}

sub Is_Renamed
{
    my ($mr, $af, $bef) = @_;

    if ($mr == 3626) {
	if ($bef eq "log_error") {
	    if ($af eq "ap_log_error_old") {
		return 1;
	    }
	    else {
		return 0;
	    }
	}
	if ($bef eq "aplog_error") {
	    return $af eq "ap_log_error";
	}
	# some of them replace ^os with ap
	$bef =~ s/^os_/ap_/ or 	$bef =~ s/^apapi_/ap_/;

	if ($bef eq $af) {
	    return 1;
	}


	if ($af eq "ap_" . $bef) {
	    return 1;
	}
	    
    } else {
	if ($af eq "ap_" . $bef) {
	    return 1;
	}
    }
    return 0;
}




sub Get_Functions
{
    my ($mr, $type, $field) = @_;

    my %added ;
    my $sth = $dbh->prepare("select filename, function, $field from funcmod where revid = ? and typemod = ? order by filename, function;");
    my $rc = $sth->execute($mr, $type);

    my @added;

    while ( my @row = $sth->fetchrow_array ) {
	push @added, [ ($row[0], $row[1], $row[2]) ] ; #[$row[0], $row[1],$row[2]];
    }
    return @added;

}
