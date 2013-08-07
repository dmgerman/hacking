#!/usr/bin/perl

while (<>) {
    chomp;
    if (/^ /) {
        $term = substr($_, 4, 6);
        $course = substr($_, 11, 12);
        $sections = substr($_, 26, 7);
        $students = substr($_, 34, 7);
        if ($students =~ m@^(\S+)\s*/?(\S+)?\s*$@) {
            ($u, $g)= ($1, $2); 
        } else {
            die $_;
        }
        $total = $u + $g;
        print "$name;$term;$course;$sections;$u;$g;$total;$_";
        print "\n";
            
    } else {
        $name = $_;
        $name =~ s/:$//;
    }
}
