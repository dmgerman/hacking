#!/usr/bin/perl

use strict;


my $testLimit = 0;
my $limit = 10000;

######################################################################


my $filesName = "files.txt";

my %stats ;

my %fileIndex; # indexed by the filaneme, it contains the "index number"
my @fileNameByIndex; # indexed by the number, it contains the filenumber

my @productByFileIndex; # indexed by the number, it contains the product name
my %productByFileName ; #indexed by filename, it contains the product number name

my %productIndexByProductName ; # index of a given product by name of product
my @productNameByProductIndex ; # name of a given product by its index 
my @productIndexByFileIndex;    # index of a given product by the file index

open(FILES, "<$filesName") or die "Unable to open [$filesName]\n";;

my $index=-1;
my $product = -1;

while (<FILES>) {
    chomp;
    my $name = $_;
    # save index to filename, needed to parse data
    $index ++;
    $fileIndex{$name} = $index; 
    $fileNameByIndex[$index] = $name;
    # extract prefix of section, product name  and save it
    my @parts = split('/', $name);
    die "illegal size" unless scalar(@parts) > 2;
    my $product = join('/', @parts[0,1]);
#    my $product = $parts[1];
#    print "$product\n";
    $productByFileName{$name} = $product;
    $productByFileIndex[$index] = $product;
    
    # keep track of how many different products we get to see

    $stats{$product}++;
}
close FILES;

print STDERR "Read ",  $index+1, " records. Total number of products ", scalar(keys %stats), "\n";

# now generate the product indexes... we could have assume the records were sorted, but oh well
# we have the products in stats
for my $k (keys %stats) {
    $product++;
    $productNameByProductIndex[$product] = $k;
    $productIndexByProductName{$k} = $product;
}


#for my $i (0..scalar(@productNameByProductIndex)-1) {
#    print "$i,$productNameByProductIndex[$i]\n";
#}
#
#die;


die "illegal results " unless $product+1 == scalar(keys %stats) and 
    scalar(keys %stats) == scalar(keys %productIndexByProductName) and
    scalar(@productNameByProductIndex) == scalar(keys %productIndexByProductName);

# now do the creation of productIndexByFileIndex

for my $i (0..$index) {
    my $product = $productByFileIndex[$i];
    my $productIndex = $productIndexByProductName{$product};
    $productIndexByFileIndex[$i] = $productIndex;
}
die "illegal creation of productIndexByFileIndex" unless scalar(@productIndexByFileIndex) == $index+ 1;

for my $i (0.. $index ) {
    print "$i:$fileNameByIndex[$i]:$productIndexByFileIndex[$i]:$productByFileIndex[$i]\n";
}
die;

########### start processing the clone data


my $c = 0;
my $found= 0;
print STDERR "Starting to process clone records\n";
while (<>) {
    $c++;
    if ($c  % 10000 == 0) {
        print STDERR "$c...\n";
    }

    last if $testLimit and --$limit < 0; # just to keep not leting run forever... yet
    chomp;
    my $original = $_;

    # split the clones in the clone set
    my @fileSpecs = split('\|', $_);
        
    my @clonesFile;
    my @clonesProduct;

    # process each clone, the idea is to extract the product index
    for my $i (0..scalar(@fileSpecs)-1) {
        my @cloneData = split(' ', $fileSpecs[$i]);
        $clonesFile[$i] = @cloneData[0];
        die if not defined $clonesFile[$i];
        $clonesProduct[$i] = $productIndexByFileIndex[$clonesFile[$i]];
        die if not defined $clonesProduct[$i];
        my $p = $productNameByProductIndex[$clonesProduct[$i]]; 
#        print "$p|";
    }
#    print "\n";
    my @candidates;
    for my $i (0..scalar(@fileSpecs)-1) {
        $candidates[$i] = 0 ; # start with not a candidate
    }
    for my $i (0..scalar(@fileSpecs)-1) {
        for my $j ($i+1..scalar(@fileSpecs)-1) {
            # mark them as a candidate if it is not yet
            if ($clonesProduct[$i] != $clonesProduct[$j]) {
                $candidates[$i] = 1;
                $candidates[$j] = 1;
            }
        }
    }
    my $needLF = 0;
    for my $i (0..scalar(@fileSpecs)-1) {
        if ($candidates[$i]) {
            $needLF = 1;
            print "$clonesProduct[$i] $fileSpecs[$i]:";
        }
    }
    if ($needLF) {
        $found++;
        print "\n";
    }
#    print "$original\n" if $needLF;
}

print STDERR "Finished $c records, found $found candidates\n";
