#!/usr/bin/perl

use strict;
require "cctoken.pm";

package cctokens;

my $debug = 0;

sub new 
{
    my ($class, $file) = @_;
    my $self = {};

    bless $self, $class;
    $self->load_Token_File($file);
    return $self;
}

sub parse_Token_Location
{
    my ($self, $loc)  = @_;

    die "illegal token location [$loc]" unless $loc=~/^([0-9a-f]+)\.([0-9a-f]+)\.([0-9a-f]+)(.*)$/; 
    # save the rest to return it

    return (oct("0x". $1),oct("0x". $2),oct("0x". $3), $4);

}

sub parse_Token_Len
{
    my ($self, $len, $currentByteLoc)  = @_;

    # remove trailing spaces

    $len =~ s/^[ \t]+//;
    if ($len =~ /^\+([0-9a-f]+)(.*)$/) {
	# starts with plus, it is just a length
	die "can't handle token [$len]" if $2 eq "";
	return (oct("0x". $1), $2);
    }
    my ($line, $column,$byte, $trail) = $self->parse_Token_Location($len);

    die "unable to parse [$len]" if ($trail eq "");

    return ($byte-$currentByteLoc, $trail);

}


sub load_Token_File
{
    my ($self, $fileName)  = @_;

    my @tokens;
#    my $lang = $self->{preprocess};
    print STDERR "Loading $fileName...\n" if $debug;
#    $fileName .= ".${lang}.ccfxprep";
    my $saveEOL = $/;
    $/ = "\n";
    if (!open(IN, $fileName)) {
	printf STDERR "Unable to open tokens file $fileName\n";
	return;
    }
    while (<IN>) {
#	print $_;
	chomp;

	my %token;
	my $len;
	my $original = $_;
	($token{line}, $token{column}, $token{byte}, $_) = $self->parse_Token_Location($_);

	# the len can be absolute (prefix +) or relative (just before another token)
	# we need to process such at the end
	($len, $_) = $self->parse_Token_Len($_,$token{byte});
	die "illegal token. We could not parse original [$original] token[$_]" if ($_ eq "");

	# the remainder is the actual token
	# but first remove trailing spaces
	s/^[ \t]+//;

	$token{content} = $_; 
	printf "%d %d %d (%s)\n",  $token{line}, $token{column}, $token{byte}, $token{content} if $debug;
	
	my $t = cctoken->new($token{line}, $token{column}, $token{byte}, $token{content});

	push @tokens, $t;
    }
    close IN;
    $self->{tokens} = [@tokens];
    printf STDERR "Loaded %d tokens\n ", scalar(@tokens) if $debug;
}


sub token_Translate
{
    my ($self, $tokenNo) = @_;

    if ($self->{tokens} == 0) {
	return (-6666,-6666);
    }

    my $tokens = $self->{tokens};
    # assert parameter


    die "illegal request to translate [$tokenNo] when size is " . scalar($$tokens)
	if ($tokenNo >= scalar(@$tokens));

    return ($$tokens[$tokenNo]->get_Line(),
	    $$tokens[$tokenNo]->get_Column(),
	    $$tokens[$tokenNo]->get_Byte()
	);
}


sub token_Sequence
{
    my ($self, $tokenFrom, $tokenTo) = @_;
    $tokenTo--;
    my $tokens = $self->{tokens};
    # assert parameter
    die "illegal request to token sequence [$tokenFrom][$tokenTo] when size is " . scalar($$tokens)
	if $tokenFrom >= scalar(@$tokens) or $tokenTo >= scalar(@$tokens) or $tokenTo < $tokenFrom;

    my $result;

    while ($tokenFrom <= $tokenTo) {
	$result .= $$tokens[$tokenFrom]->get_Content() . ":";
	$tokenFrom++;
    }
    return substr($result, 0,-1);
}


sub token_Sequence_Abstract
{
    my ($self, $tokenFrom, $tokenTo) = @_;
    $tokenTo--;
    my $tokens = $self->{tokens};
    # assert parameter
    die "illegal request to token sequence abstract [$tokenFrom][$tokenTo] when size is " . scalar($$tokens)
	if $tokenFrom >= scalar(@$tokens) or $tokenTo >= scalar(@$tokens) or $tokenTo < $tokenFrom;

    my $result;

    while ($tokenFrom <= $tokenTo) {
	$result .= $$tokens[$tokenFrom]->get_Type() . ":";
	$tokenFrom++;
    }
    return substr($result, 0,-1);
}


sub extract_Declarations
{
    my ($self) = @_;
    
    my $tokens = $self->{tokens};

    my $depth = 0;
    my $notFoundYet = 0;
    my $foundDeclaration = 0;
    my $index = 0;
    foreach $index (0.. scalar(@$tokens)-1) {
	$a = $$tokens[$index];
	my $type = $a->get_Type();

	if (
	    (($type eq "(def_block") and ($depth++,1)) or
	    (($type eq ")def_block") and ($depth--,1))
	    ) {
#	    print $depth, ":::", $a->print, "\n";
#	    print "********************inside one another [$depth]" if $depth > 1;
	    $notFoundYet = 1;
	    next;
	}

	if ($depth > 0 && $notFoundYet) {
	    if ($type eq "id") {
		$notFoundYet = 0;
		if ($$tokens[$index+1]->get_Type() eq "c_func") {
		    print "Declaration ", $a->get_Value(),"\n";
		}
		next;
	    }
	}
    }

    
}



sub find_Declaration
{
    my ($self, $decl) = @_;
    
    my $tokens = $self->{tokens};

    my $depth = 0;
    foreach $a (@$tokens) {
	if (($a->get_Type eq "(def_block" and ($depth++,1)) ||
	    ($a->get_Type eq ")def_block" and ($depth--,1))
	    ) {
	    print $depth, ":::", $a->print, "\n";
	}
    }

    
}


1;


