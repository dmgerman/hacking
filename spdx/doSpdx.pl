#!/usr/bin/perl

# assume files are in files.txt

use strict;
use POSIX 'strftime';
use Digest::SHA1  qw(sha1 sha1_hex sha1_base64);

my $SHA_FILES = "shaFiles.txt";
my $SHA_LICS = "shaGoodSent.txt";
my $SHA_UNIQUES = "uniqueLics.txt";
my $LICS = "lics.txt";
my $SPDX_LICS = "spdx_equiv_licenses.txt";

my $filesFile = shift @ARGV;
my $header = shift @ARGV;
my $baseDir ;


die "usage $0 <files> <header>" unless $filesFile ne "" and $header ne "";


if ($0 =~ m@^(.+)/[^/]+$@){
    print "Prefix [$1]\n";
    $baseDir = $1 . "/";
} else {
    $baseDir = "";
}


my %spdxEquivalence = Read_Hash_Simple_Equal("$baseDir$SPDX_LICS");

my %files = Read_Hash($SHA_FILES, "", sub {return Sha_File(@_[0])});
my %shaLics = Read_Hash($SHA_LICS, ".goodsent", sub {return Sha_File(@_[0])});;
my %shaLicsInv ;



if (not -f $SHA_UNIQUES) {
    foreach my $k (sort keys %shaLics) {
        my $sha = $shaLics{$k};
        $shaLicsInv{$sha} = $k if (not defined $shaLicsInv{$sha}) ;
    }
}

Read_Hash_Or_Write($SHA_UNIQUES, \%shaLicsInv);
my %ninkaLics = Read_Hash($LICS, ".license", \&Read_File);;

# now create a unique identifier for every license statement
XXXXXXXXXXXXXXXXXXXXXX
I want to be able to say, this file has the following license statement.
This license statement is the following license.



#foreach my $f (sort keys %ninkaLics) {
#    if ($ninkaLics{$f} eq "") {
#        $ninkaLics{$f} = "UNKNOWN";
#    }
#}
#
#
my %licenses;


foreach my $f (sort keys %ninkaLics) {
    die unless defined $files{$f};
    my$lic = $ninkaLics{$f};
    if (defined  $licenses{$lic}) {
       $licenses{$lic}++;
    } else {
        $licenses{$lic} = 1;
    }
}


foreach my $l (sort {$licenses{$b} <=> $licenses{$a}} keys %licenses) {
    my $p = SPDX_Name{$l};
    print "   $p: $licenses{$l}\n";
}


open(OUT, ">files.spdx");
foreach my $file (sort keys %files) {
    my $lic = $lics{$file}
    print OUT "Filename: $file\n";
    print OUT "FileType: SOURCE\n";
    print OUT "FileCheckSum: $files{$file}\n";
    print OUT "LicenseConcluded: NOASSERTION\n";
    print OUT "CopyrightText: NOASSERTION\n";
    print OUT "LicenseInfoInFile: ", SPDX_Name{$lic}\n";

    
}
close OUT;

exit;
# first output license names




#open(OUT, ">files.spdx");
#
#foreach my $file (sort keys %files) {
#    
#
#    print OUT "Filename: $file\n";
#    print OUT "FileType: SOURCE\n";
#    print OUT "FileCheckSum: $filesSha{$file}\n";
#    print OUT "LicenseConcluded: NOASSERTION\n";
#    print OUT "CopyrightText: NOASSERTION\n";
#
#    if (defined( $spdx{$lic})) {
##        print OUT "spdx;$file;$spdx{$lic}\n";
#        print OUT "LicenseInfoInFile: $spdx{$lic}\n";
#        $uniqueNo{$f[0]} = "";
#        $counts{$spdx{$lic}}++;
#    } else {
#        # we need to add it to the list of licenses
#        # what is itslicnese number?
#        
#        my $thisSha = $licSha{$f[0]};
#        if (defined ($uniqueNo{$thisSha})) {
#        } else {
#            # find the sha of the file.
#            $uniqueNo{$thisSha} = $licCount;
#            $noUnique{$licCount} = $licSha{$file};
#            $licCount++;
#        }
#        my $licRef = $uniqueNo{$thisSha};
#        $counts{"UnknownLicense-". $licRef}++;
##        print OUT "noSpdx;$file;$licSha{$file};$licRef\n";
#        print OUT "LicenseInfoInFile: UnknownLicense-$licRef\n";
#    }
#}
#close OUT;
#close F;
#
#

#open(OUT, ">lics.spdx");
#
#print STDERR "Count: $licCount\n";
#foreach my $i (0..$licCount--) {
#    my $licSha = $noUnique{$i};
#    my $fileName = $uniqueSha{$licSha};
#    next if $fileName eq "";
##    print STDERR "$fileName\n";
#    print OUT "LicenseID: UnknownLicense-$i\n";
#    print OUT "ExtractedText: <text>\n";
#    print OUT `cat '$fileName'`;
#    print OUT "</text>\n";        
#    print OUT "LicenseComments: <text>\n";
#    print OUT "Ninka identified the file as: \n";
#    $fileName =~ s/\.goodsent/.license/;
#    print OUT `cat '$fileName'`;
#    print OUT $uniqueSha{$licSha}, "\n";
#    print OUT "</text>\n";
#}
#close OUT;
#





exit;

sub Sha_File 
{
    my ($fileN) = @_;
    my $line;
    my $content  = "";

    open(IN, "<$fileN") or die "Unable to open [$fileN]";
    my $content  = "";
    while ($line = <IN>) {
        $content .= $line;
    }
    
    my $sha = sha1_hex($content);
    close(IN);
    return $sha;
}

sub Read_Hash_Simple_Equal
{
    my ($f) = @_;
    my %hash;
    open(F, "<$f") or die "unable to open $f";
    while (<F>) {
        chomp;
        my @f = split(';');
        if ($f[1] eq "") {
            $f[1] = $f[0];
        }
        $hash{$f[0]} = $f[1];
    }
    close(F);
    return %hash;
}

sub Read_Hash
{
    my ($filename, $suffix, $func) = @_;
    my %files;
    if (-f $filename) {
        open(FILES, $filename) or "unable to open files file [$filename]";
        while (<FILES>) {
            chomp;
            my @f = split(';');
            $files{$f[0]} = $f[1];
        }
        close FILES;
    } else {
        open(FILES, $filesFile) or "unable to open files file [$filesFile]";
        while (<FILES>) {
            chomp;
            s@^\./@@;
            my $f = $_;
            die "file not found [$_$suffix]" unless -f $f . $suffix;
            $files{$f} = $func->($f . $suffix);
            chomp $files{$f};
        }
        open(OUT, ">$filename") or die "Unable to write [$filename]";
        foreach my $k (sort keys %files) {
            print OUT "$k;$files{$k}\n";
        }
        close OUT;
    }
    return %files;
}


sub Read_Hash_Or_Write
{
    my ($filename, $hash) = @_;

    if (-f $filename) {
        open(FILES, $filename) or "unable to open files file [$filename]";
        while (<FILES>) {
            chomp;
            my @f = split(';');
            $$hash{$f[0]} = $f[1];
        }
        close FILES;
    } else {
        open(OUT, ">$filename") or die "Unable to write [$filename]";
        foreach my $k (sort keys %$hash) {
            print OUT "$k;$$hash{$k}\n";
        }
        close OUT;
    }
}

sub Read_File
{
    my ($f) = @_;

    my $lines ;
    open (IN, "<$f") or die "unable to open [$f]";
    while (<IN>) {
        $lines .= $_;
    }
    close IN;


    return $lines;
}

sub SPDX_Name
{
    my ($lic) = @_;
    my $p = $spdxEquivalence{$lic};
    if (not defined $p) {
        return $lic;
    } else {
        return $p;
    }
}
