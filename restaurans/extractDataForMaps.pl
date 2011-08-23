#!/usr/bin/perl
#perl ~/bin/myjoin.pl  restaurants.txt type.txt |  perl extractDataForMaps.pl > /tmp/rip.rip


my $i = 1;
while (<>) {
    chomp;
    my @f = split(/;/);
    next if $f[4] eq "UNKNOWN";
    $f[6] =~ s/'//g; #'
    print "   ['$f[6]', $f[4],'$f[8]',$i],\n";
    $i++;
}
