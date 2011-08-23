#!/usr/bin/perl

my $svndiff = 'svn diff --diff-cmd /Users/dmg/bin/funcDiff ' ;
my $myDiff = '/Users/dmg/bin/funcDiff' ;

my $empty= '/tmp/empty.txt';

`echo "" > $empty`;


sub Process
{
    my ($file, $curr, $prev, $developer) = @_;
    
#    print STDERR "****************", $file, "\n";

    open (DIFF, "$svndiff -r$prev:$curr $file|") or die "Unable to get diff\n";
    
    while (<DIFF>) {
#	print $_;
#	print STDERR "****************", $file, "\n";
	chomp ;
	if (/^::/) {
	    print "${file}::r${curr}::${developer}$_\n";
	}
    }
    
    close (DIFF);
    
}

sub Process_First
{
    my ($file, $curr, $developer) = @_;
    
    #extract revision
    
    open (DIFF, "$myDiff $empty $file|") or die "Unable to run mydiff\n";

    while (<DIFF>) {
#	print $_;
	chomp ;
	if (/^::/) {
	    print "${file}::r${curr}::${developer}$_\n";
	}
    }
    
    close (DIFF);
    
}

sub Process_Last
{
    my ($file, $curr, $developer,$revLabel) = @_;
    
    #extract revision
    print STDERR   `$svnupdate -r$curr $file`;
    
    open (DIFF, "$myDiff $file $empty |") or die "Unable to run mydiff\n";

    while (<DIFF>) {
#	print $_;
	chomp ;
	if (/^::/) {
	    print "${file}::r${revLabel}::${developer}$_\n";
	}
    }
    
    close (DIFF);
    
}



sub Extract_Revision
{
    my ($revs) = @_;
    
    if ($revs =~ /^r([0-9]+)$/) {
	return $1;
    } else {
	die "Unable to extract revision from $revs\n";
    }
    
}

1;
