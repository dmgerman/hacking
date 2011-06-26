#!/usr/bin/perl


use strict;

package cctoken;


sub new 
{
    my ($class, $line, $column, $byte, $content) = @_;
    my $self = {};

    bless $self, $class;
    $self->{line} = $line;
    $self->{column} = $column;
    $self->{byte} = $byte;
    $self->{content} = $content;

    # split content into type, value
    die "Illegal content. It can't be empty line [$line] column [$column] content [$content]" if $content eq "";

    if ($content =~ /\|/) {
	$self->{type} = $`;
	$self->{value} = $'; #';
    } else {
	$self->{type} = $content;
    }
    
    return $self;
}

sub get_Line
{
    my $self = shift;
    return $self->{line};
}


sub get_Column
{
    my $self = shift;
    return $self->{column};
}


sub get_Content
{
    my $self = shift;
    return $self->{content};
}

sub get_Value
{
    my $self = shift;
    return $self->{value};
}

sub get_Type
{
    my $self = shift;
    return $self->{type};
}

sub get_Byte
{
    my $self = shift;
    return $self->{byte};
}

sub print
{

    my $self = shift;

    return sprintf("%d %d %d %s", $self->get_Line(), $self->get_Column, 
		   $self->get_Byte(), $self->get_Type());

}


1;
