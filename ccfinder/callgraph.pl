#!/usr/bin/perl

use strict;

# extract all the function calls inside a C file.
# Takes as input the filename to scan

my $fname = @ARGV[0];

$fname =~ s/\.cpp\.ccfxprep//;


my $inFunc = 0;
my $inside = 0;
my $inDef = 0;
my $prev = "";
my $id;
while (<>) {
    chomp;
    my ($line, $column, $byte);
    ($line, $column, $byte, $_) = parse_Token_Location($_);
    my ($len, $content) = parse_Token_Len($_,$byte);
    $content =~ s/^\t//;

    if ($content eq "(def_block") {
#	print STDERR "Begin of function\n";
	$inDef = 1;
    }  elsif ($inDef && $content =~ /id\|/) {
	$inside = $'; #';
    }  elsif ($inDef ==0 && $content =~ /id\|/) {
	$id = $'; #';
    } elsif ($content eq "(paren"){
	$inDef = 0;
    } elsif ($inside && $inDef ==0 && $content eq "c_func") {
	print "$fname;$inside;$id\n";
    } elsif ($inDef && $content eq "c_func") {
#	print "Defining: $inside\n";
    } elsif ($content eq ")def_block") {
	$inside = 0;
    }
    $prev = $content;

}

sub parse_Token_Location
{
    my ($loc)  = @_;

    die "illegal token location [$loc]" unless $loc=~/^([0-9a-f]+)\.([0-9a-f]+)\.([0-9a-f]+)(.*)$/; 
    # save the rest to return it

    return (oct("0x". $1),oct("0x". $2),oct("0x". $3), $4);

}

sub parse_Token_Len
{
    my ($len, $currentByteLoc)  = @_;

    # remove trailing spaces

    $len =~ s/^[ \t]+//;
    if ($len =~ /^\+([0-9a-f]+)(.*)$/) {
	# starts with plus, it is just a length
	return (oct("0x". $1), $2);
    }
    my ($line, $column,$byte) = parse_Token_Location($len);

    return ($byte-$currentByteLoc);

}

