#!/usr/bin/perl



open(IN, "nserc2011.csv") or die "nserc";
while (<IN>) {
    chomp;
    /^"([^"]+)"/ or die "no match";
    $_ = $1;
    # remove the suffix
    s/ [A-Z]+$//;
#    print "[$_]", "\n";    
    $who{$_} = $_;
}
close IN;


open(IN, "accel.csv") or die "nserc";
while (<IN>) {
    chomp;
    /^"([^"]+)"/ or die "no match";
    print $_, "\n" if $who{$1} ;    
}
close IN;
