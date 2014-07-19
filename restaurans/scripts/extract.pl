#!/usr/bin/perl -w

use strict;

package HTMLStrip;
use base "HTML::Parser";

sub text {
    my ($self, $text) = @_;
    print $text;
}

sub start {
     my ($self, $tag, $attr, $attrseq, $origtext) = @_;
     # print out original text
     
     print "\n" if $tag eq "tr";
#     print "$origtext" if $tag eq "a";
     print  "http://www.healthspace.ca" , $attr->{href} . ";"  if $tag eq "a";

#     print $origtext;
 }
 
 sub end {
     my ($self, $tag, $origtext) = @_;
     # print out original text
     
     print ";" if $tag eq "td";
#     print $origtext;


}


my $p = new HTMLStrip;
# parse line-by-line, rather than the whole 			file at once

while(<>) {
  last if /<\!\-\- content \-\->/;
}

while (<>) {
  last if /<\/table>/;
    $p->parse($_);
}
# flush and parse remaining unparsed HTML
$p->eof;

