#!/usr/bin/perl -w

 #
 # Copyright (C) - This code is copyright by
 #      Giuliano Antoniol 2009,
 #      antoniol@ieee.org
 #
 # it has been written during a research dinner baking a salmon with
 # Max di Penta and Daniel German at my place in Montreal
 #
 # You may use this code as you wish, as long as these
 # comment-lines are keept intact, in place and you
 # comply with the "Beer license"
 #

#
# simple set  of transformations via regexp
# to extract license information: copyrigt owners,
# years and e-mails
#
#

use strict;
use Carp;
use Getopt::Long;
use bytes;

# DBG > 1 activate some debugging ...

my $DBG=0;
my $verbose = 0;
my $limit = 2;
my $help = ();
GetOptions( "verbose"  => \$verbose,      # --verbose
            "limit"  => \$limit,      # --verbose
            "DBG=i"    => \$DBG,          # --DBG 2 or --DBG=3
            "help+"    => \$help );       # if --help print a message it does not require arguments


my $helpMsg = "\nUsage:
\t [--limit limit author block to at most N lines ]
\t -h  this help\n\n";



unless ($help eq  "") {
    print $helpMsg;
    exit(0);
}


$|=1;

my $line ="";
my $header ="";
while(<STDIN>){
    my $lline =();
    my @array = split ("//");
    foreach my $l(@array){

# purge  cvs Ids

	$l =~ s/\$Id:.*\n//g;
	$l =~ s/\$Id:.*\$//g;
	$l =~ s/\$Id:.*\/\///g;
	$lline .= cleanup($l) . "\n";
    }
    #$lline .= "\n\n";
    $line .= $lline;



}
if ( $line =~ /^\s*$/){
    warn "\tERROR: Wrong data content! This is an empty file!\n" if ($DBG>0);
    exit(1);
}

my ($cref,$gref) = filterContributors($line);
my @contribs = @{$cref};
my @generic = @{$gref};
my ($clean_line,$implicit_license,$aref, $eref) = filterCopyrightOwner($line);
my @authors = @{$aref};
my @emails = @{$eref};
my @years = getYears($line);
my $copy_lines = join("\n", @authors);
my @copy_years = getYears($copy_lines);

if ( $#authors <0 && $implicit_license==1){
        print "#Implicit License Detected: 1\n";
    }elsif( $#authors >= 0){
	
        print "#Implicit License Detected: 0\n";
    }else{
    warn "\tERROR: Wrong data content! This is NOT a license file!\n" if ($DBG>0);
    exit(1);
    }

print "#Year:",join(",",sort(@years)),"\n";
print "#CopyRightYear:",join(",",sort(@copy_years)),"\n";
print "#EmailCopyright: ", join(",",@emails),"\n";
print "#EmailContrib: ", join(",",@contribs),"\n";
print "#EmailGeneric: ", join(",",@generic),"\n";
foreach my $a (@authors){
    print "#Authors: ", $a,"\n";
}

print "\n\n";

exit(0);
sub cleanup{
    my $str = shift;
    $_ = $str;
    
#    s/\-/ /g; do not remove is used in year ranges
   # s/\_/ /g;

    s/\+/ /g;
    s/\=/ /g;



    s/\*/ /g;
    s/\#/ /g;
    s/\%/ /g;
    s/\&/ /g;

    s/\$/ /g;
    s/\~/ /g;
    s/\|/ /g;
    #s/\\/ /g;mess up dates

   # s/\// /g; mess up dates
    s/\'/ /g;
    s/\"/ /g;
    s/\`/ /g;
    s/\?/ /g;
    s/\!/ /g;


    s/\[/ /g;
    s/\]/ /g;

    s/\{/ /g;
    s/\}/ /g;

    return $_;
}
sub filterCopyrightOwner{
    my $str = shift;
    my @authors = ();
    my @copyright_emails = ();
    my @emails = ();
    my $cntr = 0; 

    my $line = ();
    my $mail = ();
    my $implicit_license =0;
    
    $str =~ s/\///g;

    my @lines  = split (/\n/, $str);
    my $l = 0;
    while ($l <= $#lines){ 

	if ($lines[$l] =~ /(Copyright\s+(\((c|C)\)|©)\s+.+)/ ||
	    $lines[$l] =~ /(Copyright\s+[0-9]+.+)/ ||
	    $lines[$l] =~ /(Copyright\s+)/){
	    #print  "$l == Got: >>", $lines[$l],">>$1<<\n";
	    
	    $authors[$#authors+1] = $1;
	    my @ret_emails = getEmail($lines[$l]);
	    push @copyright_emails, @ret_emails if ($#ret_emails>=0);
	    my $body_length = 1;
	    if (getKeywords($lines[$l])==1){
		$implicit_license = 1;
	    }
	    $l++;
	    while (defined($lines[$l]) &&
		   $lines[$l] !~ /^\s*$/  
		   &&  $l <=$#lines
		   && $lines[$l] !~ /Copyright\s+/){
		#print  "\t $l attach: >>", $lines[$l],"<<\n";
		if ($body_length <= $limit){
		    $authors[$#authors] .= $lines[$l];
		}
		$body_length++;
		@ret_emails = getEmail($lines[$l]);
		push @copyright_emails, @ret_emails if ($#ret_emails>=0);
		if (getKeywords($lines[$l])==1){
		    $implicit_license = 1;
		}
		$l++
	    }
	    #print "$l  Next line: >>", $lines[$l],"<<\n";
	}else{
	    if (getKeywords($lines[$l])==1){
		$implicit_license = 1;
	    }
	    $line .= $lines[$l];
	    $l++;
	}

    }
    return ($line,$implicit_license,\@authors, \@copyright_emails);
}


sub filterContributors{
    my $str = shift;
    my @contrib_emails = ();
    my @generic_emails = ();
    my @lines  = split (/\n/, $str);
    my $line = ();
    my @ret_emails = ();
    my $l = 0;
    while ($l <= $#lines){ 
	if ($lines[$l] =~ /(Copyright\s+(\((c|C)\)|©)\s+.+)/ ||
	    $lines[$l] =~ /(Copyright\s+[0-9]+.+)/ ||
	    $lines[$l] =~ /(Copyright\s+)/){ # skip this block!
	    $l++;
	    while (defined($lines[$l]) &&
		   $lines[$l] !~ /^\s*$/  
		   &&  $l <=$#lines
		   && $lines[$l] !~ /Copyright\s+(\((c|C)\)|©)/){
		$l++;
	    }
	}elsif ($lines[$l] =~ /(C|c)ontributor(s)?/){
	    while (defined($lines[$l]) &&
		   $lines[$l] !~ /^\s*$/  
		   &&  $l <=$#lines
		   && $lines[$l] !~ /Copyright\s+(\((c|C)\)|©)/){

		@ret_emails = getEmail($lines[$l]);
		push @contrib_emails, @ret_emails if ($#ret_emails>=0);
		$l++;
	    }
	}else{
	    my @ret_emails = getEmail($lines[$l]);
	    push @generic_emails, @ret_emails if ($#ret_emails>=0);
	    $l++;
	}
    }
    return (\@contrib_emails,\@generic_emails);
}

sub getEmail{
    my $line = shift;
    my $email=();
    my $left = $line;
    my @collected = ();

    while ($left =~ /([^\s\@]+\@[^\s\@]+)/){
	$left = $';
	$email = $1;
	$email =~ s/[\>\<\(\)\,]//g;
	$collected[$#collected+1] = $email;
    }
    
    return @collected;
}


sub getKeywords{
    my $line = shift;

    if ($line =~ /redistribute|modify|distributed|(L|l)icense/){
	return 1;
    }
    return 0;
}


sub getYears{
    my $line = shift;

    #
    # get rid of dates, time and revisions
    #

    $line =~ s/([0-9]{1,4}\/[0-9]{1,2}\/[0-9]{1,4})/DATE/g; 
    $line =~ s/([0-9]{1,2}\:[0-9]{1,2}\:[0-9]{1,2})/TIME/g; 
    $line =~ s/([0-9]+(\.[0-9]+)+)/REV/g; 
    #print ">>$line<<";
    my $left = $line;
    my $year = ();
    my $range_init = ();
    my $range_end = ();
    my $pattern = ();
    my @collected = ();


#    while ($left =~ /(((19|20)[0-9]{2,2}|[0-9]{2,2})\s*\-\s*((19|20)[0-9]{2,2}|[0-9]{2,2}))/){

    while ($left =~ /(([0-9]{4,4}|[0-9]{2,2})\s*\-\s*([0-9]{4,4}|[0-9]{2,2}))/){
	$range_init = checkAndNormalizeYear($2);
	$range_end = checkAndNormalizeYear($3);
	$pattern = $1;
	$left = $';

	if (!defined($range_init) || !defined($range_end)){
	    warn "ERROR: RangeMissMatch Pattern >>",$pattern,"<<\n" if ($DBG>1);
	    next;
	}
	$line =~ s/$pattern/ /g;
	my $counter = $range_init;
	while ($counter <= $range_end){
	    $collected[$#collected+1] = $counter;
	    $counter++
	}

    }

    $left = $line;

    while ($left =~ /\b([0-9]{4,4}|[0-9]{2,2})\b/){
	$left = $';
	$year = checkAndNormalizeYear($1);
	#print "Match >>$1<<\n";
	if (defined($year)){
	    $collected[$#collected+1] = $year;
	}

    }
    
    return @collected;
}
sub checkAndNormalizeYear{
    my $year = shift;

    if ( length($year) == 2 && $year =~ /^(8|9)/){
	$year = "19".$year;
	return $year;
    }elsif ( length($year) == 2 && $year =~ /^(0)/){
	$year = "20".$year;
	return $year;
    }elsif (length($year) == 4 && $year =~ /^(19|20)/){
	return $year;
    }
    return ();
}
