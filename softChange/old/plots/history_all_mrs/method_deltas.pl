#!/usr/bin/perl

use DBI;
use strict;

my $dbName = $ARGV[0];
my $outputFile = $ARGV[1];

if ($dbName eq "") {
    die "$0 <dbName> <outputFile>\n";
}

if ($outputFile eq "") {
    die "$0 <dbName> <outputFile>\n";
}


my $TMP_FILE = "/tmp/history_authors$$.data";

my $TMP_FILE_PLOT = "/tmp/history_authors$$.gplot";


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
set ylabel "Methods"
#set y2label "LOCS added in release"
#set arrow from "1998/01/01",0 to "2003/05/01",0  nohead lt 5 
#show arrow
plot '$TMP_FILE' using 1:2  title "Net new methods $dbName" with lines
END

    ;
open (PLOT, ">$TMP_FILE_PLOT") or die "Unable to create plot\n";
print(PLOT $plotData);
close PLOT;

my $useIndent = 0;

my $userName = 'dmg';

my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});



my $sth = $dbh->prepare(" 
                       select date_trunc('month', datetime) as d, sum(methodsadded - methodsdeleted) from methoddeltas group by d order by d;
                        ");

my $rc = $sth->execute;

my @row;

open (DATA, ">$TMP_FILE") or die "unable to create temporal file\n";

while ( @row = $sth->fetchrow_array ) {
    my ($date, $freq) = @row;
    
    $date =~ s/ .*//;
    $date =~ s@\-@\/@g;
    print DATA "$date $freq\n";

}


close DATA;

`gnuplot $TMP_FILE_PLOT`;

unlink $TMP_FILE;

unlink $TMP_FILE_PLOT;
