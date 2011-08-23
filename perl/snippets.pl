
sub execute
{
    my ($c) = @_;
#    print "\nTo execute [$c]\n";
    `$c`;
    my $status = ($? >> 8);
    die "execution of program [$c] failed: status [$status]" if ($status != 0);
}
