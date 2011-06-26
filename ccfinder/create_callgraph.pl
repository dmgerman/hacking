#!/usr/bin/perl

print "To scan\n";

`find . -name "*.c" > allCfiles.txt`;

print "Created allCfiles.txt... running cc finder\n";


print `~/bin/ccfinder D -i allCfiles.txt`;

print "CCfinder done.. callgraph\n";

`find . -name "*.ccfxprep" | xargs -n  1  ~/w/hacking/ccfinder/callgraph.pl > callgraph.txt`;

print "Done\n";
