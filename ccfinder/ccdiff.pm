#!/usr/bin/perl

package ccdiff;

use strict;
my $debug = 0;

sub new 
{
    my ($class, $old, $new) = @_;
    my $self = {};
    bless $self, $class;
    $self->{old} = $old;
    $self->{new} = $new;
    $self->doDiff;
    return $self;
}

sub doDiff
{

    my $self=shift;
    my $diffCmd = "diff -d -U0 ";

    my $cmd = sprintf($diffCmd . " '%s' '%s'",
		      $self->{old},$self->{new});
    
    $self->{diff} = `$cmd`;
#    print $self->{diff}, "\n\n";
    $self->Hunk_Locations_Extract;
#    $self->Hunk_Locations_Print ;
#    $self->Hunk_Locations_Compute;
}


sub save
{
    my ($self, $fname) = @_;
    open (OUT, ">$fname")  or die "Unable to create diff file [$fname]\n";
    print OUT $self->{diff};
    close OUT;
}

sub Hunk_Locations_Print 
{
    my $self=shift;

    my $i = 0;

    my $h = $self->{hunks};
    my $save = 1;
    foreach $a (@$h) {
	die "illegal regions " unless $save == $a ->region_Before();
	printf("Index %6d, %s\n", $i,  $a->print());
	$save = $a ->end_Before();
	$i++;
    }
}

#sub Hunk_Locations_Compute
#{
#    my $self=shift;
#
#    my ($diff) = $self->{diff};
#
#    my @hunks = grep(/^@@/, split('\n', $diff));
#    
##print join (":\n", @hunks);
#    
#    my @hunkLocs = ();
#    
#    my $lineBefore = 0;
#    my $lineAfter = 0;
#    foreach my $hunk (@hunks) {
#	chomp $hunk;
##    /^@@ [+-]([0-9]+),([0-9]+) [+-]([0-9]+),([0-9]+)/;
#	my $sizeBefore;
#	my $sizeAfter;
#	my $deltaLoc;
#	my $deltaLoc2;
#	if ($hunk =~ s/^@@ [+-]([0-9]+),?([0-9]+)?//) {
#	    $deltaLoc = $1 - ($lineBefore +1);
#	    if ($2 ne "") {
#		$sizeBefore = $2;
#	    } else {
#		$sizeBefore = 1;
#	    }
#	} else {
#	    die "Illegal hunk part one $hunk";
#	}
#	if ($hunk =~ s/ [+-]([0-9]+),?([0-9]+)?//) {
#	    $deltaLoc2 = $1 - ($lineAfter +1);
#	    if ($2 ne "") {
#		$sizeAfter = $2;
#	    } else {
#		$sizeAfter = 1;
#	    }
#	} else {
#	    die "Illegal hunk part two $hunk";
#	}
#
#	print "LineBefore: $lineBefore; Deltaloc: $deltaLoc; LineAfter: $lineAfter SizeBefore: $sizeBefore, sizeAfter $sizeAfter\n";
##	die "assertion $deltaLoc: $deltaLoc2" unless $deltaLoc == $deltaLoc2;
#
#	
#	push @hunkLocs, {"lineBefore" => $lineBefore,
#			 "lineAfter"  => $lineAfter,
#			 "sizeBefore" => $sizeBefore,
#			 "sizeAfter"  => $sizeAfter,
#			 "delta"      => $deltaLoc};
#	
#	$lineBefore += $deltaLoc + $sizeBefore;
#	$lineAfter  += $deltaLoc + $sizeAfter;
#	
#    }
#    $self->{hunks} = [@hunkLocs];
#}
##print $diff;
#
sub Hunk_Locations_Extract
{
    my $self=shift;

    my ($diff) = $self->{diff};

    my @hunks = grep(/^@@/, split('\n', $diff));
    
#print join (":\n", @hunks);
    
    my @hunkLocs = ();
    
    # verify that we are doing ok
    my $offset =0;
    my $prevLineEndBefore = 1;
    my $prevLineEndAfter = 1;
    foreach my $hunk (@hunks) {
	my $delta;

	chomp $hunk;
#    /^@@ [+-]([0-9]+),([0-9]+) [+-]([0-9]+),([0-9]+)/;
	my $lineBefore;
	my $lineAfter;
	 # if they are not specified, they are 1
	my $sizeBefore=1;
	my $sizeAfter=1;
	# before hunk spec
	($lineBefore, $sizeBefore, $hunk) = $self->extract_Hunk_Location($hunk);
	($lineAfter, $sizeAfter, $hunk) = $self->extract_Hunk_Location($hunk);
	my $endBefore = $lineBefore + $sizeBefore;
	my $endAfter = $lineAfter + $sizeAfter;

	die "Invalid offset [$offset] in diff hunk [$lineBefore::$sizeBefore] [$lineAfter:$sizeAfter]\n" 
	    if ($lineBefore + $offset != $lineAfter);
	
	$offset += $sizeAfter - $sizeBefore;
	$delta = $lineBefore - $prevLineEndBefore;

	print "Hunk Before [$lineBefore:$sizeBefore] [$lineAfter:$sizeAfter][$offset] Delta [$delta]\n" if $debug;
	
	die "Illegal delta [$delta][", $lineAfter - $prevLineEndAfter, "]"  if $delta != ($lineAfter - $prevLineEndAfter);

	push @hunkLocs, hunk->new($lineBefore, $lineAfter, $sizeBefore, $sizeAfter, $delta);
	
	$prevLineEndBefore = $endBefore;
	$prevLineEndAfter = $endAfter;
	
    }
    $self->{hunks} = [@hunkLocs];
}
#print $diff;

sub extract_Hunk_Location
{
    my ($self, $line) =@_;
    my $hunk = $line;
    # remove header @@
    $line =~ s/^@@//;
    if ($line =~ s/^ [+-]([0-9]+),?([0-9]+)?//) {
	my ($beg, $len) = ($1,$2);
	# if no len is specified, then assume it is 1
	if (!defined($len)) {
	    $len = 1;
	}
	# Do not trust locations for sizes == 0
	if ($len == 0) {
	    $beg ++;
	}
	return ($beg, $len, $line);
    } else {
	# hunks of size 0 have an under
	die "Illegal hunk part $hunk";
    }
}


sub region_Changed_Before
{

    my ($self, $begin,$end) = @_;
    my $h = $self->{hunks};
    my $i=0;

    die "illegal parameter [$begin][$end], must be > 0" if ($begin <= 0) or ($end <=0);
    die "illegal parameter [$begin] > [$end]" if ($begin > $end);
    if (scalar(@$h) == 0) {
	# files were identical
	return 0;
    }

    $i = scalar(@$h) - 1;

    # check if region after last change
    if ($begin >= $$h[$i]->end_Before) {
	return 0;
    }
    # from the end of file, search for the last hunk with a "region"
    # line bigger than the current line. IT is guaranteed to exist

    while ($i >= 0 and $begin < $$h[$i]->region_Before()) {
	$i--;
    }

    # find the previous beginning of hunk to the line we are concerned
    my $hunk = $$h[$i];
    my $offset = $begin - $hunk->region_Before();
    if ($offset < $hunk->delta()) {
	# within the unchanged area
	# now we need to make sure that the end is also in this region
	if (($end - $hunk->region_Before()) < 
	    $hunk->delta()) {
	    return 0;
	} else {
	    return 1;
	}
    } 
    # we are in the changed region...
    return 1;

}

sub region_Changed_Type_After
{
    my ($self, $begin,$end) = @_;

    my ($self, $begin,$end) = @_;
    my $h = $self->{hunks};
    my $i=0;

    die "illegal parameter [$begin][$end], must be > 0" if ($begin <= 0) or ($end <=0);
    die "illegal parameter [$begin] > [$end]" if ($begin > $end);
    if (scalar(@$h) == 0) {
	# files were identical
	return 0;
    }

    $i = scalar(@$h) - 1;

    # check if region after last change
    if ($begin >= $$h[$i]->end_After) {
	return 0;
    }
    # from the end of file, search for the last hunk with a "region"
    # line bigger than the current line. IT is guaranteed to exist

    while ($i >= 0 and $begin < $$h[$i]->region_After()) {
	$i--;
    }

    # find the previous beginning of hunk to the line we are concerned
    my $hunk = $$h[$i];
    my $offset = $begin - $hunk->region_After();
    my $offsetEnd = $end - $hunk->region_After();
    if ($offset < $hunk->delta()) {
	# within the unchanged area
	# now we need to make sure that the end is also in this region
	if ($offsetEnd < 
	    $hunk->delta() ) {
	    return 'None';
	} else {
	    return 'PartialAtEnd';
	}
    } 
    # at at this point we know that the change starts within the hunk
    # but where does it end?
    if ($end < $hunk->end_After) {
	# it ends before the end of the hunk
	return "PartialAtBeginning";
    }
    # we are in the changed region...
    return "Complete";

}


sub region_Changed_After
{

    my ($self, $begin,$end) = @_;
    my $h = $self->{hunks};
    my $i=0;

    die "illegal parameter [$begin][$end], must be > 0" if ($begin <= 0) or ($end <=0);
    die "illegal parameter [$begin] > [$end]" if ($begin > $end);
    if (scalar(@$h) == 0) {
	# files were identical
	return 0;
    }

    $i = scalar(@$h) - 1;

    # check if region after last change
    if ($begin >= $$h[$i]->end_After) {
	return 0;
    }
    # from the end of file, search for the last hunk with a "region"
    # line bigger than the current line. IT is guaranteed to exist

    while ($i >= 0 and $begin < $$h[$i]->region_After()) {
	$i--;
    }

    # find the previous beginning of hunk to the line we are concerned
    my $hunk = $$h[$i];
    my $offset = $begin - $hunk->region_After();
    if ($offset < $hunk->delta()) {
	# within the unchanged area
	# now we need to make sure that the end is also in this region
	if (($end - $hunk->region_After()) < 
	    $hunk->delta()) {
	    return 0;
	} else {
	    return 1;
	}
    } 
    # we are in the changed region...
    return 1;

}

sub line_Translate
{

    my ($self, $line) = @_;
    my $h = $self->{hunks};
    my $i=0;

    die "illegal parameter [$line], must be > 0" if $line <= 0;
    if (scalar(@$h) == 0) {
	# files were identical
	return $line;
    }

    $i = scalar(@$h) - 1;

    # first let us see if the line in after the last hunk...
    if ($line >= $$h[$i]->end_Before) {
	return $line - $$h[$i]->end_Before() + $$h[$i]->end_After();
    }
    # from the end of file, search for the last hunk with a "region"
    # line bigger than the current line. IT is guaranteed to exist

    while ($i >= 0 and $line < $$h[$i]->region_Before()) {
	$i--;
    }

    # find the previous beginning of hunk to the line we are concerned
    my $hunk = $$h[$i];
    my $offset = $line - $hunk->region_Before();
    if ($offset < $hunk->delta()) {
	# within the unchanged area
#	print "Offset $offset\n";
#	print $hunk->print(), "\n";
	return $offset + $hunk->region_After()
    } 
    # we are in the changed region...
    return - 1;

}

sub line_Translate_Inv
{

    my ($self, $line) = @_;
    my $h = $self->{hunks};
    my $i=0;

    die "illegal parameter [$line], must be > 0" if $line <= 0;
    if (scalar(@$h) == 0) {
	# files were identical
	return $line;
    }

    $i = scalar(@$h) - 1;

    # first let us see if the line in after the last hunk...
    if ($line >= $$h[$i]->end_After) {
	return $line - $$h[$i]->end_After() + $$h[$i]->end_Before();
    }
    # from the end of file, search for the last hunk with a "region"
    # line bigger than the current line. IT is guaranteed to exist

    while ($i >= 0 and $line < $$h[$i]->region_After()) {
	$i--;
    }

    # find the previous beginning of hunk to the line we are concerned
    my $hunk = $$h[$i];
    my $offset = $line - $hunk->region_After();
    if ($offset < $hunk->delta()) {
	# within the unchanged area
#	print "Offset $offset\n";
#	print $hunk->print(), "\n";
	return $offset + $hunk->region_Before()
    } 
    # we are in the changed region...
    return - 1;

}

package hunk;

sub new 
{
    my ($class, $lineBefore, $lineAfter, $lenBefore, $lenAfter, $delta) = @_;
    my $self = {};

    bless $self, $class;

    $self->{_lineBefore} = $lineBefore;
    $self->{_lineAfter} = $lineAfter;
    $self->{_lenBefore} = $lenBefore;
    $self->{_lenAfter} = $lenAfter;
    $self->{_delta} = $delta;

    return $self;
}

sub line_Before
{
    my $self = shift;
    return $self->{_lineBefore};
}

sub end_Before
{
    my $self = shift;
    return $self->{_lineBefore} + $self->{_lenBefore};
}

sub end_After
{
    my $self = shift;
    return $self->{_lineAfter} + $self->{_lenAfter};
}

sub region_Before
{
    my $self = shift;
    return $self->{_lineBefore} - $self->{_delta};
}

sub delta
{
    my $self = shift;
    return $self->{_delta};
}

sub region_After
{
    my $self = shift;
    return $self->{_lineAfter} - $self->{_delta};
}

sub print
{
    my $self = shift;
    my $result = sprintf ("locationBefore %6d:%4d locationAfter %6d:%4d Delta %d %d",
			  $self->{_lineBefore}, $self->{_lenBefore}, $self->{_lineAfter}, $self->{_lenAfter}, $self->{_delta},
			  $self->region_Before(),
	);
    return $result;
}



#package main;
package diffTest;

sub test
{
    my $d = ccdiff->new("before.c", "after.c");
    print "Done:", $d->{old}, "\n";
    $d->Hunk_Locations_Print ;
    for (my $i = 1; $i< 300; $i++) {
	my $n = $d->line_Translate($i);
#    print "Line Before [$i][$n]\n";
    }
    for (my $i = 1; $i< 300; $i++) {
	my $n = $d->line_Translate_Inv($i);
#    print "Line after [$n][$i]\n";
    }
    print $d->region_Changed_Before(1,1), "\n";
    print $d->region_Changed_Before(1,2), "\n";
    print $d->region_Changed_Before(1,5), "\n";
    print $d->region_Changed_Before(3,5), "\n";
    print $d->region_Changed_Before(3,76), "\n";
    print $d->region_Changed_Before(3,77), "\n";
    print $d->region_Changed_Before(79,81), "\n";
    print $d->region_Changed_Before(80,81), "\n";
    print "---\n";
    print $d->region_Changed_After(1,1), "\n";
    print $d->region_Changed_After(2,2), "\n";
    print $d->region_Changed_After(70,76), "\n";
    print $d->region_Changed_After(70,77), "\n";
    print $d->region_Changed_After(77,80), "\n";
    print $d->region_Changed_After(204,219), "\n";

    $d->save("abc.rip");
}

1;

