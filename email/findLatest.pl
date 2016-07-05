#!/usr/bin/perl

my %times;
open(IN, "/tmp/me.times") || die "unable to readl times";
while (<IN>) {
    chomp;
    my @f = split(/;/);
    $times{$f[0]} = $f[1];
    die "[$_][$f[1]]" unless $f[1] =~ /^[0-9]+$/;
}
close IN;

open(IN, "/tmp/me.sha.txt") || die "unable to readl times";

my $prev;
my @current;
while (<IN>) {
    chomp;
    my ($sha, $file) = split(/;/);
    if ($sha ne $prev) {
        # flush current
        if (scalar(@current) > 1) {
            do_Current(@current);
        }
        @current = ();
    } 
    push @current, $file;
    $prev = $sha;
}


sub do_Current
{
    my @files = @_;

    my $i = 0;
    my $min;
    my $minDate;
    @files = sort {$times{$a} cmp $times{$b}} @files ;

    foreach my $f (@files) {
        print "$i;$times{$f};$f\n";
        $i++;
    }
}
