#!/usr/bin/perl

use Digest::SHA qw(sha1_hex);

use strict;


while (<>)  {
    chomp;
    next if $_ eq "";
    my $file = $_;
    if (not -f $file) {
	print STDERR "File [$file] does not exist.. skipping\n";
	next;
    }
    my $id = Get_Id($file);
    if ($id ne "") {
	print "$file;$id\n";
    }
}


sub Get_Id
{
    # cherry pick
    #Message-ID: <CA+ON040ew8=AreOGVWRSU5Nxh0i-82w3SJo-VHvvVsnTiPE38g@mail.gmail.com>
    #

    my ($file) = @_;
    if (not open(IN, $file)) {
	print STDERR "Unable to open [$file].. skipping\n";
	return "";
    }
    # read header until first empty line
    my $content = "";
    while (<IN>) {
	last if $_ eq "";
	if (/^Message-ID/i) {
	    $content = $_;
	}
    }
    chomp;
    if ($content eq "") {
	print STDERR "file [$file] has no message id... skipping\n";
	return "";
    }
    while (<IN>) {
	$content .= $_;
    }
    return sha1_hex($content);
}
