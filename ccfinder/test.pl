#!/usr/bin/perl

require softChange;

foreach $a (()) {
    print "Done\n";
}

print "yes\n";
die;


$db = softChange->new("lcms");


@files = $db->Get_MRs_FuncMod();



foreach $a (@files) {
    print "$a\n";
}

$db->Close();
