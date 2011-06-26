#!/usr/bin/perl

#version: ccfx 10.1.13
#format: pair_diploid
#option: -b 50 // minimumCloneLength
#option: -s 2 // shapingLevel
#option: -u 1 // useParameterUnification
#option: -t 12 // minimumTokenSetSize
#preprocess_script: cpp
#source_files {
#1       mail-mt.c       4085
#2       mail-vfolder.c  5833
#}
#
#format -> pa:d
#magicNumber -> ccfxraw0
#minLength -> 50
#preprocess -> cpp
#shapingLevel -> 2
#subVersion -> 1
#subsubVersion -> 13
#tokenSetSize -> 12
#unknown1 -> 4
#useParmUnif -> 1
#version -> 10
#

use strict;


# add current directory to path
$0 =~ m@/([^/]+)$@;
my $dir = $`; #'

push @INC, $dir ;

require "ccdiff.pm";

undef($/);
my $lang = "java";

my $cc = <>;

my $magicNumber;

my %fields;



#my ($a) = unpack('I', $cc);
($fields{magicNumber}, $fields{version},$fields{subVersion}, $fields{subsubVersion}) = unpack('A8III', $cc);

$cc = substr($cc, 20);
($fields{format}, $fields{unknown1},$fields{minLength},
    $fields{shapingLevel},$fields{useParmUnif},$fields{tokenSetSize})  =  unpack('A4IIIIII', $cc);

$cc = substr($cc, 24);

($fields{preprocess}) = GetString(\$cc);



printf STDERR "To start reading files\n";
my @files;
($cc, @files) = GetFiles($cc);
printf STDERR "Done reading files\n";

printf STDERR "To start reading clones\n";


my @clones;
($cc, @clones) = GetClones($cc);

printf STDERR "Done reading clones\n";


#PrintFields(\%fields);

PrintOptions(%fields);
PrintFiles(@files);


die "left with some data [$cc]\n" unless $cc eq "";

#PrintOptions(%fields);
#PrintFiles(@files);
PrintClones(@clones);

#exit;

my @tokens = Load_Tokens(\@files);

#Print_Tokens(\@tokens);


# renumber f_0 to f_1 (old to new lines)
my @hunkLocations ;
{

    my $diffCmd = "diff -d -U0 '" .  $files[0]{name} . "' '".  $files[1]{name} . "'";
#print $diff;

    my $d = ccdiff->new($files[0]{name}, $files[1]{name});

#    $d->Hunk_Locations_Print ;
}

#@transLines = Hunk_Translation_Table(\@h);

#foreach my $l (240.. 270) {
#    Hunk_Translate_Line($l, \@h);
#}

PrintClonesPretty(\@clones, \@tokens,\@hunkLocations, 1 , 2);



exit 0;

sub Print_Tokens
{
    my ($tokens) = @_;
    foreach my $t (@$tokens) {
	printf "Size of this tokens %d\n", scalar(@$t);
	foreach my $l (@$t) {
	    printf "   Line %d\n", $l->{line};
	}
    }
}


sub Load_Tokens
{
    my ($files) = @_;
    my @result;
    foreach my $f (@$files) {
	my @newTokens = Load_Token_File($f ->{name});
	push @result, [@newTokens];
    }
    return @result;
}

sub Load_Token_File
{
    my ($fileName) = @_;
    my @tokens;
    print STDERR "Loading $fileName...\n";
    $fileName .= ".${lang}.ccfxprep";
    my $saveEOL = $/;
    $/ = "\n";
    open(IN, $fileName) or die "Unable to open $fileName";
    while (<IN>) {
#	print $_;
	/^([0-9a-f]+)\.([0-9a-f]+)\.([0-9a-f]+)\s+([+-][0-9a-f]+)/; #\s+([0-][0-9a-f]+)
	my %token;
	($token{line}, $token{column}, $token{byte}) = (oct("0x". $1),oct("0x". $2),oct("0x". $3),oct("0x". $4));
#	printf "%d %d %d\n",  $token{line}, $token{column}, $token{byte};
	push @tokens, {%token};
    }
    close IN;
    printf STDERR "Loaded %d tokens\n ", scalar(@tokens);
    return @tokens;
}

sub PrintOptions
{
    my (%fields) = @_;
    
    printf("version: %s %d.%d.%d\n", substr($fields{magicNumber},0,4),
	   $fields{version},$fields{subVersion}, $fields{subsubVersion});
    
    if ($fields{format} eq "pa:d") {
	print "format: pair_diploid\n";
    } else {
	die "Unknown format\n";
    }
    printf (<<END
option: -b %d // minimumCloneLength
option: -s %d // shapingLevel
option: -u %d // useParameterUnification
option: -t %d // minimumTokenSetSize
preprocess_script: %s
END
, $fields{minLength},$fields{shapingLevel},$fields{useParamUnif},$fields{tokenSetSize},$fields{preprocess});
    
}

sub PrintFiles
{
    my (@files) = @_;

    print "source_files {\n";
    foreach my $file (@files) {

	printf("%d\t%s\t%d\n", $file->{index}, $file->{name}, $file->{size});
    }
    print "}\n";
}



sub PrintClones
{
    my (@clones) = @_;

    print "clone_pairs {\n";
    foreach my $clone (@clones) {
	last if $clone->{fromFile} == 0;

	printf("%d\t%d.%d-%d\t%d.%d-%d\n", $clone->{cloneSetId},
	       $clone->{fromFile},$clone->{fromBeginToken},$clone->{fromEndToken},
	       $clone->{toFile},$clone->{toBeginToken},$clone->{toEndToken});
    }
    print "}\n";
}

sub PrintClonesPretty
{
    my ($clones,$tokens, $hunks) = @_;

    print "clone_pairs_lines {\n";
    foreach my $clone (@$clones) {
	last if $clone->{fromFile} == 0;

	# they come always in twos
	next if $clone->{fromFile} > $clone->{toFile};

	# if the files are the same, then process the one with the
	# smallest line number and skip the other
	
	next if ($clone->{fromFile} == $clone->{toFile}) and
	    $clone->{fromBeginToken} > $clone->{toBeginToken};

#	printf("%d\t%d.%d-%d\t%d.%d-%d\n", $clone->{cloneSetId},
#	       $clone->{fromFile},$clone->{fromBeginToken},$clone->{fromEndToken},
#	       $clone->{toFile},$clone->{toBeginToken},$clone->{toEndToken});

	# skip if they are the "same" file and clone
	my @from1 = Translate_Token($clone->{fromBeginToken}, $tokens, $clone->{fromFile});
	my @to1 = Translate_Token($clone->{fromEndToken}, $tokens, $clone->{fromFile});

	my @from2 = Translate_Token($clone->{toBeginToken}, $tokens, $clone->{toFile});
	my @to2 = Translate_Token($clone->{toEndToken}, $tokens, $clone->{toFile});

        my $f1 = $files[$clone->{fromFile}-1];
        my $f2 = $files[$clone->{toFile}-1];
        die unless $f1->{index} == $clone->{fromFile};
        die unless $f2->{index} == $clone->{toFile};
	printf("%d\t%s\t%d.%d:%d-%d:%d\t%s\t%d.%d:%d-%d:%d\n", $clone->{cloneSetId},
               $f1->{name},
	       $clone->{fromFile},
	       @from1,
	       @to1,
               $f2->{name},
	       $clone->{toFile},
	       @from2,
	       @to2
	    );
	      # $clone->{toBeginToken},$clone->{toEndToken});
    }
    print "}\n";
}

sub FilterClones
{
    my ($clones,$tokens, $hunks, $filesToWatch) = @_;

    print "clone_pairs {\n";
    foreach my $clone (@$clones) {
	last if $clone->{fromFile} == 0;

	# they come always in twos
	next if $clone->{fromFile} > $clone->{toFile};

	# print only clones that matter
	
#	next unless $clone->{fromFile} == $old or $clone->{fromFile} == $new;
	    
	# get from data

#	printf("%d\t%d.%d-%d\t%d.%d-%d\n", $clone->{cloneSetId},
#	       $clone->{fromFile},$clone->{fromBeginToken},$clone->{fromEndToken},
#	       $clone->{toFile},$clone->{toBeginToken},$clone->{toEndToken});

	# skip if they are the "same" file and clone
	my @from1 = Translate_Token($clone->{fromBeginToken}, $tokens, $clone->{fromFile});
	my @to1 = Translate_Token($clone->{fromEndToken}, $tokens, $clone->{fromFile});

	my @from2 = Translate_Token($clone->{toBeginToken}, $tokens, $clone->{toFile});
	my @to2 = Translate_Token($clone->{toEndToken}, $tokens, $clone->{toFile});

	if ($clone->{fromFile} == 1  &&
	    $clone->{toFile} == 2  &&
	    $from1[0] == $from2[0] && 
	    $from1[1] == $from2[1] && 
	    $to1[0] == $to2[0] && 
	    $to1[1] == $to2[1]) {
	    next;
	}

	printf("%d\t%d.%d:%d-%d:%d\t%d.%d:%d-%d:%d\n", $clone->{cloneSetId},
	       $clone->{fromFile},
	       @from1,
	       @to1,
	       $clone->{toFile},
	       @from2,
	       @to2
	    );

	if ($clone->{fromFile} == 1) {
	    $from1[0] = Hunk_Translate_Line($from1[0], $hunks);
	    $to1[0] = Hunk_Translate_Line($to1[0], $hunks);
	}
	if ($clone->{toFile} == 1) {
	    $from2[0] = Hunk_Translate_Line($from2[0], $hunks);
	    $to2[0] = Hunk_Translate_Line($to2[0], $hunks);
	}
	
	
	printf("T:%d\t%d.%d(%d):%d(%d)\t%d.%d(%d):%d(%d)\n", $clone->{cloneSetId},
	       $clone->{fromFile},
	       @from1,
	       @to1,
	       $clone->{toFile},
	       @from2,
	       @to2
	    );


	print "----------\n";
#	printf("%d\t%d.%d:%d-%d\t%d.%d-%d:%d\n", $clone->{cloneSetId},
#	       $clone->{fromFile},
#	       Translate_Token_Line($clone->{fromBeginToken}, $tokens, $clone->{fromFile}),
#	       Translate_Token_Line($clone->{fromEndToken}, $tokens, $clone->{fromFile}),
#	       $clone->{toFile},
#	       Translate_Token_Line($clone->{toBeginToken}, $tokens, $clone->{toFile}),
#	       Translate_Token_Line($clone->{toEndToken}, $tokens, $clone->{toFile})
#	    );
#
#


	      # $clone->{toBeginToken},$clone->{toEndToken});
    }
    print "}\n";
}

sub Translate_Token
{
    my ($tokenNo, $tokens, $fileIdx) = @_;
    $fileIdx --;
    die unless $fileIdx >= 0;
   
#    printf ">>>>>token %d file %d\n", $tokenNo, $fileIdx;
    
    my $thisTok = $$tokens[$fileIdx];

#    printf "Size %d\n",  scalar(@$thisTok);

    return ($$thisTok[$tokenNo]->{line},
	    $$thisTok[$tokenNo]->{column});
}

sub Translate_Token_Line
{
    my ($tokenNo, $tokens, $fileIdx) = @_;
    $fileIdx = 0;
    die unless $fileIdx >= 0;
   
#    printf ">>>>>token %d file %d\n", $tokenNo, $fileIdx;
    
    my $thisTok = @$tokens[$fileIdx];
#    printf "Size %d\n",  scalar(@$thisTok);
    
    return @$thisTok[$tokenNo]->{line};
}


sub GetClones
{
    # foreach file 
    #   name
    #   index
    #   size in tokens
    my ($cc) = @_;
    my @result;
    my %clone;
    my $count = 0;
    printf STEDERR "Getting clones\n";

    while ($cc ne "") {
#	   and ($cc !~ /^\x0a/)) {
	%clone = ();
	(
	 $clone{fromFile},$clone{fromBeginToken},$clone{fromEndToken},
	 $clone{toFile},$clone{toBeginToken},$clone{toEndToken},
	 $clone{cloneSetId},$clone{unknown}
	) = unpack('IIIIIIII',$cc);
	push @result, {%clone};
	$cc = substr($cc, 8*4);
        $count++;
        if ($count % 100 == 0) {
            printf STDERR ".";
        }
    } 
    printf STDERR "\nFinished reading clones\n";

    #eat marker
    return ($cc, @result);
}




sub GetFiles
{
    # foreach file 
    #   name
    #   index
    #   size in tokens
    my ($cc) = @_;
    my @files;
    my $name;
    my $index;
    my $size;
    printf STEDERR "Getting filenames\n";
    my $count = 0;
    while ($cc !~ /^\x0a/) {
	($name) = GetString(\$cc);
	($index,$size) = unpack('II',$cc);
#	print STDERR "Name $name, $index, $size\n";
        die "no ccfxd file for [$name]\n" unless -f $name . ".${lang}.ccfxprep";
	push @files, {'name' => $name, 
		      'index' => $index, 
		      'size' => $size};
	$cc = substr($cc, 8);
        $count ++;
        if ($count % 100 == 0) {
            printf STDERR ".";
        }
    } 
    printf STDERR "\nFinished reading filesnames\n";
    #eat marker
    $cc = substr($cc, 1);
    return ($cc, @files);
}

#,$fields{format}, $fields{unknown1},$fields{minLength},
#    $fields{shapingLevel},$fields{useParmUnif},$fields{tokenSetSize})  =  unpack('IIIA4IIIIII', $cc);





sub GetString
{
    my ($st) = @_;
#    print "Len: ", length($st) , "\n"; #';    
    if ($$st =~ /\x0a/) {
#	print "Len:before ", length($`) , "\n"; #';
#	print "Len:in     ", length($&) , "\n"; #';
#	print "Len:after  ", length($') , "\n"; #';
        $$st = $';
	return ($`); #'
    } else {
        my $save = $$st;
        $$st = '';
	return ($save);
	die;
    }
}

sub PrintFields
{
    my ($fields)  = @_;
    foreach my $a (sort keys %$fields) {
	print "$a -> $fields{$a}\n";
    }
}




######################################################################


sub Hunk_Translate_Line
{
    my ($line, $h) = @_;
    my $i=0;

    while ($i < scalar(@$h) and $line > $$h[$i]->{lineBefore}) {
	$i++;
    }
    if ($i == scalar(@$h)) {
	# went beyond the end of the other
	$i--;
	my $d = $line - ($$h[$i]->{lineBefore} + $$h[$i]->{delta} + $$h[$i]->{sizeBefore});
	my $y = $$h[$i]->{lineAfter} + $$h[$i]->{delta} + $$h[$i]->{sizeAfter} + $d - 1;
	return $y;
    }
	

    $i--;
    # $i points to the last hunk section where this line might be
    if ($line >  $$h[$i]->{lineBefore} +  $$h[$i]->{delta}) {
	#this is an undefined line
	#print "$line: Undefined in new\n";
	return 666666666666;
    } else {
	my $newLine = $$h[$i]->{lineAfter} + $line - $$h[$i]->{lineBefore};
	#print "$line:$newLine\n";
	return $newLine;
    }
}




