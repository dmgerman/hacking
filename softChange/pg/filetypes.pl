#!/usr/bin/perl

# receive just filenames



while(<>) {
    chomp;
    if (m@([^/]+)$@) {
        $basename  = $1;
        $ext = Extension($basename);
        $source = Is_Source($ext);
        print "$_;$basename;$ext;$source\n";
    } else {
        die "[$_] basename "
    }
}


sub Extension
{
    my ($f) = @_;
    if ($f =~ /\.([^.]*$)/) {
        return $1;
    } else {
        return "";
    }
}


sub Is_Source
{
    my ($ext) = @_;

    return 1 if $ext eq "c" or 
        $ext eq "h" or
        $ext eq "cc" or
        $ext eq "java" or
        $ext eq "pl" 
        ;
    return 0;
}


