#!/usr/bin/perl

use strict;

sub Do_CCFinder
{
    my ($rev, $filesInMR) = @_;

#    `ccfinder D -i allfiles.txt 2> /dev/null`;
#    `ccfinder P a.ccfxd > a.txt 2> /dev/null`;

    my $ccFinder;
    
    $ccFinder = ccfinder->new("");
    $ccFinder->execute("allfiles.txt","a.ccfxd");

    my @setsClones = $ccFinder->get_Clones_Sets_Selected($filesInMR);
    
    print STDERR "Clone set", join(":", @setsClones), "\n";
    
    if (scalar(@setsClones) > 0) {
	$ccFinder->print("clonesStats.txt");
	$ccFinder->print_Clones_Set_Selected(\@setsClones, "clonesInMR.txt");
	$ccFinder->extract_Clones_Set_Selected(\@setsClones);
	$ccFinder->extract_Clones_Abstract_Set_Selected(\@setsClones);
    } else {
	print STDERR "No clones in this MR\n";
    }
    


}

sub Copy_CCFinder_Files
{
    my ($dest, $rev, $files,$prefix, $saveDir, $suffix, $doCCfinder) = @_;

    # while files were modified in the revision?
    mkdir ("$dest/$rev");
    open (LIST, ">$dest/$rev/filesChanged.txt") or die  "unable to create filesChanged.txt file";

    foreach my $file (@$files) {

#    print "$row[0]\n";
	Copy_File($dest, $file, $rev,$prefix, $saveDir,$doCCfinder);
	print LIST "$file\n";
    }
    close LIST;
    # copy ccfinder file
    `mv -f a.ccfxd clonesStats.txt  clonesInMR.txt allfiles.txt  callgraph.txt $dest/$rev/`;
    # copy clones
    `mv -f *.clone*  $saveDir/$rev/`;
}


sub Copy_File
{
    my ($dest, $fname,$rev, $repoPrefix2, $saveDir, $suffix, $doCCfinder) = @_;

#    die "illegal filename [$fname]" if ($fname !~ /^$repoPrefix/);
    die "illegal filename 2 [$fname]" if ($fname !~ m@/([^/]+)$@);

    my $fullName = $repoPrefix2 . $fname;

    # the file is not there, so we return
    if (!-f $fullName) {
	print "File [$fullName] prefix [$repoPrefix2] no longer exists. probably erased\n";
	if (-f "${fullName}" . $suffix) {
	    unlink "${fullName}$suffix";
	}
	return ;
    }

    print "Directory [$`] [$1]\n"; #
    my $dir = "$`";  # 
    my $base = $1;

    `mkdir -p '$saveDir/$rev/$dir'`;
    `cp -f "$fullName" "$saveDir/$rev/$dir/"`;
    if ($doCCfinder) {
        die "ccfinder file not found [${fullName}$suffix]" if !-f "${fullName}$suffix";
        `cp -f "${fullName}$suffix" "$saveDir/$rev/$dir/"`;
    }
}



1;

