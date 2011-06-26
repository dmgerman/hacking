#/usr/bin/perl

use URI::Escape;
#$safe = uri_escape("10% is enough\n");
#$verysafe = uri_escape("foo", "\0-\377");
#$str  = uri_unescape($safe);


$i = 0;

while (<>) {
    if (/\] *(.+) *\(/) {
        $i++;
        $movie = $1;
        $index = sprintf("movie%03d", $i);
        next if -f "$index.txt";
        print "to do $index\n";
#        next unless $i == 178;
#        print "$movie\n"; next;
        $movie =~ s/ +$//;
        $movie = uri_escape($movie);
        $movie =~ s/\%20/+/g; #';
        $index = sprintf("movie%03d", $i);
        print $index, ":", $movie, "\n";
        `lynx --accept-all-cookies -dump \"http://www.netflix.ca/Search?v1=$movie\" > $index.txt`;
    }
}
