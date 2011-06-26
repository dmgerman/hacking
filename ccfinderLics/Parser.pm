#!/usr/bin/perl

package Parser;

use strict;

use fields 'filename',
    'currentByte',
    'currentLine',
    'currentCol',
    'nextChar',
    ;

my $separators = " \t";

sub new {
    my($class, $f) = @_;        # 
    my $self = { filename => $f };  # Anonymous hash reference holds instance attributes
    bless($self, $class);          # Say: $self is a $class
    open(IN, $f) or die "Unable top open input file [$f]";
    read (IN, $nextChar, 1);
    $self->{currentByte} = 0;
    $self->{currentLine} = 1;
    $self->{currentCol} = 1;
    return $self;
}

sub next_token {
    if ($nextChar =~ /\A/) {
        
    }

    my $c = '';
    my $t = '';
    do {
        $t .= "$c";
        return $t unless read (IN, $c, 1);
    } until $c =~ /[$separators]/;
    return $t;
}

1;
