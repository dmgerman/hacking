#!/usr/bin/perl

# this file computes the proportion of clones from

# join -j 1 -t ';' files.txt fileclones.txt

#4090;./Azureus/Azureus_v2.5.0.0/src/com/aelitis/net/udp/uc/impl/PRUDPPacketHandlerStatsImpl.java;201;59;102:160
#4095;./Azureus/Azureus_v2.5.0.0/src/com/aelitis/net/udp/uc/PRUDPPacketRequest.java;297;103;5:56:195:245


while (<>) {
    chomp;
    my @f = split(/;/);
    my $prop = $f[4] * 1.0/$f[2];
    if ($prop > 0.75) {
        print join(';', @f[0..1], $prop, @f[2..6]);
        print "\n";
    }
}
