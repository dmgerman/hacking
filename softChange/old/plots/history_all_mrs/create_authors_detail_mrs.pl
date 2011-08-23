#!/usr/bin/perl

use DBI;
use strict;

my $dbName = $ARGV[0];
my $outputFile = $ARGV[1];
my $outputFileProp = $ARGV[2];
my $minPercent = $ARGV[3];


if ($dbName eq "") {
    die "$0 <dbName> <outputFile>\n";
}

if ($outputFile eq "") {
    die "$0 <dbName> <outputFile>\n";
}


my $TMP_FILE = "/tmp/create_authors_detail$$.data";

my $TMP_FILE_PLOT = "/tmp/create_authors_detail$$.gplot";


my $plotData = <<END;
reset
set output "$outputFile"
#set terminal postscript eps monochrome 22  

set terminal postscript eps color 22  

#load "../terminal.inc"

set terminal postscript  12
set size 1.0,0.35

set format x "%y/%m"
set timefmt "%m/%d/%y %H:%M"
set timefmt "%Y/%m/%d"
set xdata time
set key left
set xlabel "Date"
set ylabel "MRs"
#set y2label "LOCS added in release"
#set arrow from "1998/01/01",0 to "2003/05/01",0  nohead lt 5 
#show arrow
#plot '$TMP_FILE' using 1:2  title "Authors for $dbName" with lines
END

    ;
my $plotDataPart2 = <<END;


reset
set output "$outputFileProp"
#set terminal postscript eps monochrome 22  

set terminal postscript eps color 22  

#load "../terminal.inc"

set terminal postscript  12
set size 1.0,0.35

set format x "%y/%m"
set timefmt "%m/%d/%y %H:%M"
set timefmt "%Y/%m/%d"
set xdata time
set key left
set xlabel "Date"
set ylabel "MRs"
#set y2label "LOCS added in release"
#set arrow from "1998/01/01",0 to "2003/05/01",0  nohead lt 5 
#show arrow
#plot '$TMP_FILE' using 1:2  title "Authors for $dbName" with lines
END

    ;

my $useIndent = 0;

my $userName = 'dmg';

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});



my $authors = $dbh->prepare(" 
       select author, c *1.0 /total as p from  
           (select author, count(*) as c from mrs2 group by author) as rip, 
           (select count(*) as total from mrs2) as rip2 
        where c *1.0 /total > ?
        order by p desc;
                        ");


my $rc = $authors->execute($minPercent);

my @authors;
my %authorIndex;
my $authorsCount = 0;
while (my @row = $authors->fetchrow_array) {
    push (@authors, $row[0]);
    $authorIndex{$row[0]} = $authorsCount++;
}

my $sth = $dbh->prepare("
                        select date_trunc('month', daterev) as d, count(*) from mrs2 
                         group by d
                        ");

my $rc = $sth->execute;

my @row;

my %totals;

while ( @row = $sth->fetchrow_array ) {
    my ($date, $freq) = @row;

    $date =~ s/ .*//;
    $date =~ s@\-@\/@g;

    $totals{$date} = $freq;

}


my $sth = $dbh->prepare("
                        select date_trunc('month', daterev) as d, author, count(*) from mrs2 
                        where author in ('" . join("','", @authors) . "')
                         group by d, author
                        ");


my $rc = $sth->execute;

my @row;

open (DATA, ">$TMP_FILE") or die "unable to create temporal file\n";

# we don't have too much data, so let us keep it in an array

my %table;

while ( @row = $sth->fetchrow_array ) {
    my ($date, $author,$freq) = @row;


    $date =~ s/ .*//;
    $date =~ s@\-@\/@g;

    $table{$date}[$authorIndex{$author}] = $freq;

#    print DATA "$date $author $freq\n";

}




foreach my $a (sort keys %table) {
    print DATA "$a ";
    print DATA "$totals{$a} ";
    foreach my $b (0..$authorsCount-1) {
	if (defined $table{$a}[$b]) {
	    my $prop = 0;
	    if ($totals{$a} > 0) {
		$prop = $table{$a}[$b] * 1.0 /$totals{$a} ;
	    }
	    print DATA "$table{$a}[$b] $prop ";
	} else {
	    print DATA  "0 0.0 ";
	}
    }
    print DATA "\n";
}

close DATA;


open (PLOT, ">$TMP_FILE_PLOT") or die "Unable to create plot\n";
print PLOT $plotData;

print PLOT "plot  '$TMP_FILE'     using  1:2  title \"All\" with lines, \\\n";

my $i=1;
my $comma = ",";
my $index = 0;
foreach my $a (@authors) {

    print "$i " . scalar(@authors) . "\n";


    if ($i == @authors) {
	$comma = "";
    }

    $a =~ s/ +$//;
    $index = $i * 2+1;

    print PLOT  " '$TMP_FILE'     using  1:$index  title \"$a\" with lines${comma}\\\n";
    $i++;

}

print PLOT  $plotDataPart2;

print PLOT "plot   \\\n";

my $i=1;
my $comma = ",";
my $index = 0;
foreach my $a (@authors) {

    print "$i " . scalar(@authors) . "\n";


    if ($i == @authors) {
	$comma = "";
    }

    $a =~ s/ +$//;
    $index = $i * 2+2;

    print PLOT  " '$TMP_FILE'     using  1:$index  title \"$a\" with lines${comma}\\\n";
    $i++;

}

print PLOT "\n";

close PLOT;

`gnuplot $TMP_FILE_PLOT`;


unlink $TMP_FILE;

unlink $TMP_FILE_PLOT;
