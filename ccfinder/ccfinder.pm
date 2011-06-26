#!/usr/bin/perl


package ccfinder;

require "cctokens.pm";
require "clone.pm";
require "ccparse.pm";

use strict;

sub new
{
    # the prefix is any prefix that needs to be stripped from each filename
    my ($class, $prefix) = @_;
    my $self = {
	_prefix => $prefix,
    };
    bless $self, $class;
#    $self->execute();
#    $self->{ccdata} = ccparse->new($ccFinderFile);
    return $self;
}

# set the list of files to scan (sometimes we use a file with them)
sub set_Files_List
{
    my ($self, $parm) = @_;
    $self->{_files} = $parm;
}

# load the already created ccfinder data file
sub load_File
{
    my ($self, $parm) = @_;
    $self->{ccdata} = ccparse->new($parm, $self->{_prefix});
}

# Do whatever you need on each of the files
sub iterate_Files
{
    my ($self, $parm) = @_;
    my $cc = $self->{ccdata};
    $cc->iterate_Files($parm);
}

# given a list of filenames, return the sets of 
# clones
sub get_Clones_Sets_Selected
{
    my ($self, $filesList) = @_;
    my $cc = $self->{ccdata};
    return $cc->get_Clones_Sets_Selected($filesList);
}

# given a list of setids, do 
sub iterate_Clones_In_Set
{
    my ($self, $set, $parms) = @_;
    my $cc = $self->{ccdata};
    return $cc->iterate_Clones_In_Set($set, $parms);
}

sub print_Clones_Set_Selected
{
    my ($self, $set, $fname) = @_;
    my $cc = $self->{ccdata};
    return $cc->print_Clones_Set_Selected($set, $fname);
}

sub extract_Clones_Set_Selected
{
    my ($self, $set) = @_;
    my $cc = $self->{ccdata};
    return $cc->extract_Clones_Set_Selected($set);
}

sub extract_Clones_Abstract_Set_Selected
{
    my ($self, $set) = @_;
    my $cc = $self->{ccdata};
    return $cc->extract_Clones_Abstract_Set_Selected($set);
}



sub extract_Clones_In_Files
{
    my ($self, $files) = @_;

    my $l = $self->{_files};

    die;
    foreach my $f (@$l) {

    }
}


# Execute ccfinder. If its parameter is empty use
# {_files}, otherwise run it on the filename given
# in the parameter
sub execute
{
    my ($self, $fileWithList, $outFileName) = @_;
    my $runPretty = 0;

    my $tmpDir = "/tmp/";
    my $useTemp = 0;

    my $ccFinder = $self->{_ccFinder} = "/Users/dmg/hacking/ccfinder/ccfx.exe";
    my $ccFinderCommand = $self->{_ccFinderCommand} = "ccfinder D -u- -o %s -s 3 -i %s";
    my $ccFinderPrettyPrint = $self->{_ccPrettyPrint} = "wine $ccFinder P %s";

    my $command;
    my $tempFileList;
    
    my $tempFileOut;

    if ($outFileName eq "") {
	$tempFileOut =  "rip" . $$ . ".ccfxd";
    } else {
	$tempFileOut = $outFileName;
    }

    if ($fileWithList eq "") {
	$tempFileList = $tmpDir . "rip" .  $$ . ".list";
	$useTemp  = 1;
	if (!$self->create_List_Files($tempFileList)) {
	    die "Trying to run ccfinder on an empty list of files";
	}
    } else {
	$tempFileList = $fileWithList;
    }

    $command = sprintf($ccFinderCommand, $tempFileOut, $tempFileList);
    print STDERR "[$command]\n";
    `$command`;
    $self->{ccdata} = ccparse->new($tempFileOut);

    # pretty print, let us save the info just in case...
    if ($runPretty) {
	$command = sprintf($ccFinderPrettyPrint, $tempFileOut);
#    print STDERR "[$command]\n";
	$self->{prettyPrinted} = `$command`;
#    print STDERR $self->{_prettyPrinted};
    }
    if ($useTemp) {
	unlink($tempFileList);
    }

}

sub get_ccdata_raw
{
    my ($self) = @_;

    my $cc = $self->{ccdata};
    
    return $cc->{data};
    
}

#sub get_ccdata_pretty
#{
#    my ($self) = @_;
#
#    return $self->{prettyPrinted};
#    
#}

# create a file with all the filenames
# to be used by ccfinder
sub create_List_Files
{
    my ($self, $filename) = @_;

    my $l = $self->{_files};


    if (!defined(@$l) or (scalar(@$l) == 0)) {
	# empty list, return false
	return 0;
    }
    open (OUT, ">$filename")  or die "Unable to create list file [$filename]\n";
    

    foreach my $f (@$l) {
	my $t;
	if ($self->{_prefix}) {
	    $t = $self->{_prefix} . "/" . $f;
	} else {
	    $t = $f;
	}
	print OUT $t , "\n";
    }
    close OUT;
    return 1;
}

# print the clone data
sub print
{
    my ($self,$fname) = @_;
    my $cc = $self->{ccdata};

    printf "Found %d clones\n", $cc->count_Clones;
    $cc->print($fname);
}

# print the clone data
sub extract_Clones
{
    my ($self) = @_;
    my $cc = $self->{ccdata};

    $cc->extract_Clones;
}


# print only some clones in the files specified
sub print_Clones_Selected
{
    my ($self,$list) = @_;
    my $cc = $self->{ccdata};
    $cc->print_Clones_Selected($list);
}




1;

