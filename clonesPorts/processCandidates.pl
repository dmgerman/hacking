#!/usr/bin/perl

my %siblings;
my $maxCloneSetSize = 50;

use strict;

my $c = 0;

while (<>) {
    chomp;
    $c++;
    if ($c  % 1000 == 0) {
        print STDERR "$c...\n";
    }
#    last if ($c == 100) ;

    s/:^//;
    my @r = split(':', $_);
    my @data;
    my $fieldNo = scalar(@r);
    for my $i (0.. $fieldNo -1) {
        my @f = split_record($r[$i]);
        $data[$i] = [@f];
        my $x = $data[$i];
    }
    # now we have the data split, and we can start processing the clones
    if (scalar(@r) > $maxCloneSetSize ) {
#        print STDERR "Skipping cloneset of size ", scalar(@r), "\n";
        next
    }

    for my $i (0.. scalar(@r) -1) {
        for my $j ($i+1.. scalar(@r) -1) {
            # simplifies referencing... blame it on perl
            my $from = $data[$i];
            my $to = $data[$j];
            #using filename
            if ($$from[1] > $$to[1]) {
                # let us make sure we don't process them twice
                my $from = $data[$j];
                my $to = $data[$i];
            }
            # we don't process the same project twice
            next if ($$from[0] == $$to[0]);
#            print "From $$from[1] to $$to[1]\n";
#            print join(':', @$from), ";";
#            print join(':', @$to), ";";
#            print "\n";
            # so now we are ready to start to attach clones to the data
            Attach_Sibling($$from[1],$$to[1], $$from[2], $$from[3]);
            Attach_Sibling($$to[1],$$from[1], $$to[2], $$to[3]);
        }
    }

}

foreach my $k (keys %siblings) {
    my $k2 = $siblings{$k};
    foreach my $k3 (keys %$k2) {
        my $data = Get_Siblings_Data_Linearized($k,$k3);
        print "$k,$k3,", $data, "\n";
    }
}

sub Get_Siblings_Data_Linearized
{
    my ($from, $to) = @_;

    my $result ="";
    my $data = $siblings{$from}{$to};
    my $totalTokens = 0;
    my $tokenSt = "";
    if (!defined $data) {
        return "";
    } else {
        foreach my $i (0..scalar(@$data)-1) {
            my $entry = $$data[$i];
            $totalTokens += 1+ $$entry[1] - $$entry[0];
            $tokenSt .= join(":", @$entry) . ";";
        }
        $result = scalar(@$data).  ",";
        $result .=  "$totalTokens,";
        $result .= $tokenSt;
    }

    return $result;

}


sub Attach_Sibling
{
    my ($from, $to, $tokenStart, $tokenEnd) = @_;
    
    my $i = 0;
    my $regions = Regions_In_Sibling($from, $to);
    my ($regionBegin, $regionEnd);

    $i = 0;
    while ($i < $regions) {
#        print "Regions $regions [$i] [$from][$to]\n";

        ($regionBegin, $regionEnd) = Get_Region_Siblings($from, $to, $i);
#        print "$tokenStart, $tokenEnd... searching $regionBegin, $regionEnd\n";

        # it is there already don't add
        if ($regionBegin == $tokenStart and $regionEnd == $tokenEnd) {
            return;
        }
        if ($regionBegin < $tokenStart) { # we have passed where it goes
#            print "Found a region to insert $i ($regionBegin < $tokenStart)\n";
#            last;
        }        
        $i++;
    }
#    print "TOINSERT: $regions, $i, From: $from, To: $to, Start: $tokenStart, End: $tokenEnd ($regionBegin,$regionEnd)\n";

    Insert_Before_Region_To_Sibling($from, $to, $tokenStart, $tokenEnd, $i);
}

sub Insert_Before_Region_To_Sibling
{
    my ($from, $to, $tokenStart, $tokenEnd, $where) = @_;
    my $data = $siblings{$from}{$to};
    if (!defined $data) {
        $siblings{$from}{$to} = [];
        $data = $siblings{$from}{$to};
    }
    my $noEntries = Regions_In_Sibling($from, $to);

    die "illegal parameter where [$where][$noEntries][$from][$to]" unless $where <= $noEntries and $where >=0;

    # get where to point to a more meaninful place

    if ($noEntries == 0) {
        # nothing, just push
#        print "TOINSERT1: $from, $to, $tokenStart, $tokenEnd\n";
        push(@$data,  [$tokenStart, $tokenEnd]);
    } elsif ($where == $noEntries) {

        #add at the end
#        push(@$data,  [$tokenStart, $tokenEnd]);
#        return;

        my ($lastBegin, $lastEnd) = Get_Region_Siblings($from, $to, $where-1);
        # the one to add starts inside last
        if ($tokenStart -1 <= $lastEnd) {
            if ($tokenEnd > $lastEnd) { 
            #we extend current token
                $$data[$where-1] = [$lastBegin, $tokenEnd];
            } else {
                #it is already part of the previous one
                # begins inside the previous and ends inside the previous
            }
        } else {
            # just append
            push(@$data,  [$tokenStart, $tokenEnd]);
        }
    } else{
        
#        splice(@$data, $where+1, 0, [$tokenStart, $tokenEnd]);
#        return;

        # Get previous sibling
        my ($prevBeg, $prevEnd) = Get_Region_Siblings($from,$to,$where);
#        print "ELSE $where,$prevBeg,$prevEnd\n";
        # the one to add starts inside last
        if ($tokenStart <= $prevEnd) {
            #we extend previous token
            if ($tokenEnd > $prevEnd) { 
                $$data[$where] = [$prevBeg, $tokenEnd];
            } else {
                #it is already part of the previous one
                # begins inside the previous and ends inside the previous
            }
        } else {
#            print "SPLICING\n";
            splice(@$data, $where+1, 0, [$tokenStart, $tokenEnd]);
        }
    }

#    
}


sub Get_Region_Siblings
{
    my ($from, $to, $index) = @_;
    my $data = $siblings{$from}{$to};
    die if $index < 0;
    if (!defined $data) {
        die "illegal request get regin siblings [$index]";
        return undef;
    } else {
        die "illegal idnex to sibling $index" if $index >= scalar(@$data);
        my $entry = $$data[$index];
        die "illegal idnex to sibling $index " ,$$entry[0], ":",$$entry[1], "\n" if $$entry[0] < 0 || $$entry[1] < 0;
        return @$entry;
    }
    
    
}

sub Regions_In_Sibling
{
    my ($from, $to) = @_;
    my $data = $siblings{$from}{$to};
    return 0 if (!defined $data) ;
    return scalar (@$data);
}

sub split_record
{
    my ($f) = @_;

#    die unless $f=~ /^(\d+) (\d+)/;
    die unless $f=~ /^(\d+) (\d+) (\d+),(\d+),(\d+) (\d+),(\d+),(\d+)$/;

# if tokens
    return ($1, $2,$5,$8);
# if lines
#    return ($1, $2,$3,$6);
}
