#!/usr/bin/perl

use File::Slurp;
use strict;
use Digest::MD5 qw(md5_hex);



while (<>) {
    chomp;
    my $text = read_file( $_) ;
    my $digest = md5_hex($text);
    print $digest,":", $_, "\n";

}


