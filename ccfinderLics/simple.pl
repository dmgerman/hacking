#!/usr/bin/perl -w

use IO::Handle;
use Parse::RecDescent;
use strict;
use IO::Handle;

my $outFile = '';

if (@ARGV == 2) {
    # second argument is output file
    $outFile = pop @ARGV;
}


#$Parse::RecDescent::skip = '[ \t]+';		# skip tabs and spaces
$Parse::RecDescent::skip = '';		# skip nothing

my $lexer = new Parse::RecDescent q
{
 { my $niw = 0; my $i_seen = 0; } # set NIW , i_seen at start
 
 license: token(s) | eof
 token: marker | licwords | number | ident  |url |  ident | word |  punct |  realeoline | space |  other 

marker: 'COMMENT DELIM' {print "CODE [$item[1]]\n"}

punct: sentenceEnd | period | star | slash | quotes | otherpunc |leftbrace | rightbrace   | paraend 

  url: /http:\/\/[\w\.\/_0-9?=-]+/ {print "URL [$item[1]]\n"}

 sentenceEnd: /\./ ... /[ \n\r\t]/ {print "SentenceEnd [<.>]\n"}

 paraend: eoline eoline(s) {print "ParEnd [<PARAEND>]\n"}

 period: '.' {print "Period [$item[1]]\n"}
 otherpunc: /[\?<>="',;:\(\)\{\}@!_-]+/ {print "otherpunc [$item[1]]\n"}
 star: /[*]+/ {print "star [$item[1]]\n"}
 slash: /[\/]+/ {print "slash [$item[1]]\n"}
 leftbrace: '[' {print "otherpunc [<lbracket>]\n"}
 rightbrace: ']' {print "otherpunc [<rbracket>]\n"}
 quotes:     /(''|\`\`|'|\`|")/ {print "quotes [<quotes>]\n"}


licwords: gnu | copysymbol |  corp 

  corp: 'Corp.' {print "word [$item[1]]\n"}

<<<<<<< .mine
 # allrights: /All Rights Reserved/i {print "allRightsReserved [$item[1]]\n"}

  id: /[\w]+(\.[\w]+)+/ {print "id [$item[1]]\n"}
=======
  ident: /[\w]+(\.[\w]+)+/ {print "ident [$item[1]]\n"}
>>>>>>> .r955

 copysymbol: /\([Cc]\)/ {print "Copysymbol [$item[1]]\n"}
 copysymbol: '©'  {print "Copysymbol [$item[1]]\n"}
 gnu: /GNU/i {print "GNU [$item[1]]\n"}
# gpl: 'General Public License' {print "GPL [$item[1]]\n"}
# gpl: 'general public license' {print "GPL [$item[1]]\n"}
# gpl: 'Lesser General Public License' {print "leGPL [$item[1]]\n"}
# gpl: 'Library General Public License' {print "liGPL [$item[1]]\n"}
# fsf: 'FSF' {print "FSF [$item[1]]\n"}
# fsf: 'Free Software Foundation' {print "FSF [$item[1]]\n"}
# copyright: /copyright/i {print "Copyright [$item[1]]\n"}
# author: /author/i {print "Author [$item[1]]\n"}

 number: real | integer 

 real: /[0-9]+\.[0-9]+/ {print "real [$item[1]]\n"}

 integer: /[0-9]+/ {print "integer [$item[1]]\n"}

 word: /[a-z]+/i  {print "word [$item[1]]\n"}

 ident: /[a-z_]([0-9]+[a-z_]*)+/i  {print "word [$item[1]]\n"}

 other: /[^\w]/ {print "OTHER [$item[1]]\n"}
 
 space: /[ \t]+/ # {print "here [$item[1]] [line] $thisline [column] $thiscolumn prev[$prevline] [$prevcolumn] [$thisoffset]\n" }

 realeoline: eoline1 | eoline2

 eoline1: /\n([ \t\*\/]*)/ ... /[^A-Z]/ { print "fakeendofline $thiscolumn\n"}

 eoline2: eoline { print "endofline\n"}

 eoline: /\n([ \t\*\/]*)/ 

 eof: /^\Z/ {print "ENDOFINPUT\n"}


} or die "bad grammar!";


if ($outFile ne "") {
    open OUTPUT, ">$outFile" or die $!;
    STDOUT->fdopen( \*OUTPUT, 'w' ) or die $!;
}

my $fname = shift @ARGV;
die "Usage $0 <File name>" unless $fname ne "";

open(IN, "<$fname") or die "Unable to open input file [$fname]";


undef($/);

$_ = <IN>;
close IN;

open(OUTPUT, ">$fname" . ".parsed") or die "Unable to open output file [${fname}.parsed]";
STDOUT->fdopen( \*OUTPUT, 'w' ) or die $!;


$_ =~ s/\r\n/\n/g;
$_ =~ s/\r/\n/g;

$lexer->license(\$_) or die "Incapable of parsing";


if ($outFile ne "") {
    close OUTPUT;
}
