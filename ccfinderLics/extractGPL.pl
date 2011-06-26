#!/usr/bin/perl

use strict;

my $fname = shift @ARGV;

my $save = $/;

open(IN, "<$fname") or die "unable to open $fname";
undef $/;    
my $data = <IN>;
Find_GPL($data);

close IN;
$/ =  $save ;
exit 0;

sub Find_GPL
{
    my ($subData) = @_;
    my $inGPL = 1;

    $subData=~ s/\t+/ /g;
    $subData=~ s/\r\n/\n/g;
    $subData=~ s/\/\*/ /g; #/*
    $subData=~ s/\*\// /g; #*/
    $subData=~ s/^ *\*+//mg; #star at the beginnign of line
    $subData=~ s/^ +//mg; #star at the beginnign of line
    $subData=~ s/^CODE$//mg;
    $subData=~ s/\n\n+/NEWLINEEEEE/g;
    $subData=~ s/\./.NEWLINEEEEE/g;
    $subData=~ s/\n/ /g;   #
    $subData=~ s/ +/ /g;   #
    $subData=~ s/^ +//mg; #star at the beginnign of line
    while ($subData =~ /NEWLINEEEEE/g) {
        my $c = $`;
        $c =~ s/^ +//; 
        print $c . "\n" if Match_GPL($c);
        $subData = $';
    }
    print $subData . "\n" if Match_GPL($subData);

    exit;
}

sub Match_GPL
{
    my ($st) = @_;
    return 1 if ($st =~ /general public license/i);
    return 1 if ($st =~ /GPL/);
#    return 1 if ($st =~ /GNU/);
    return 0;
        
}
