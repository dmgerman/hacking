#!/usr/bin/perl



while (<>) {
    chomp;
    # preprocess %
    s/\\%/____PERCENT_____/g;
    if (/%/) {
        $_ = $`;
    }
    s/____PERCENT_____/\\%/g;
    print "$_\n";
}
