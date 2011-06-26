#/usr/bin/perl

use URI::Escape;
#$safe = uri_escape("10% is enough\n");
#$verysafe = uri_escape("foo", "\0-\377");
#$str  = uri_unescape($safe);


$i = 0;

while (<>) {
    if (/\] *(.+) *\(/) {
        chomp;
        s/\).+$/\)/;
        s/\[.+\]//;
        s/^ +//;
        $o = $_;
        $i++;
        $movie = $1;
        $movie =~ s/ +$//;
        $name = sprintf("movie%03d.txt", $i);
        print "$o\n\n";
        $data = Read_Movie($name);
        if (not ($data =~ /is not available/m)) {
            print "AVAILABLE\n";
        }
        print $data;
        print "\n\n";
    }
}


sub Read_Movie 
{
    local ($file) = @_;
    $data = "";

    open (IN, "<$file") or die "unable to open [$file]\n";
    
    $read = 0;
    while (<IN>) {
        if (/^Results for: /) {
            $read = 1;
        }
        if (/^    2\./)  {
            last;
        }
        if ($read == 1) {
            $data .= $_;
        }
    }

    close IN;
    return $data;
}
