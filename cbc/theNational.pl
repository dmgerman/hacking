#!/usr/bin/perl

while (<>) {
    chomp;
    if (m@href="([^\?]+)\?@) {
#	print "Url to get $1\n";
	$url = $1;
	last;
    }
}

$save = `wget -q -O - $url`;

if ($save =~ m/HREF="([^"]+)"/)  {
    print "$1\n";
    `vlc  '$1' --sout national.wmv`;
}
#print $save;
