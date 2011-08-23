#!/usr/bin/perl

use strict;

while (<>) {
    chomp;
    my @f = split(/;/);
    my $address = $f[2];
    my $name  = $f[1];
    $name  =~ s/^ +//;
    $name  =~ s/\/.*//;
    $address=~ s/ /+/g;
    $address .= ",+Victoria,+BC,+Canada";

    my $latLong = Get_LatLon($address);
    my $file = "data/${name}.TXT";
    die "not found [$file]" unless -f "$file";
    my $type = `grep 'Facility Type' "$file"`;
    chomp $type;
    die "type not found [$file][$type]" unless $type =~ /Facility Type:/;
    $type = $'; #$';
    $type =~ s/^ +//;
    $type =~ s/ +$//;
    my $realName = `head -1 "$file"`;
    chomp $realName;
    print join(';', @f,$name,$address,$latLong,$type,$realName), "\n";
}

sub Get_LatLon
{

    my ($address) = @_;
    my $ret;
    $ret = `lynx -dump 'http://maps.google.com/maps/api/geocode/json?address=$address&sensor=false'`;
    $ret =~ s/\s+/ /g;
    $ret =~ /\"location\": { \"lat\": ([0-9\.]+), \"lng\": ([0-9\.-]+) }/;

#    print "[$1][$2]\n";
    my ($lat, $lon) = ($1, $2);
    return "UNKNOWN" unless $lat =~ '^48';
    return "UNKNOWN" unless $lon =~ '^\-123';

    return "$lat,$lon";

}
