#!/usr/bin/perl

open (OUT, ">cvsNORM.files") || die "uanble to create normalized file\n";

# Input format:
# filaname; basename; extension; directory; lastestversion; branchversion; totalrevisons; selectedrevisions;inattic;rcsfilename;module;
#sys/alpha/alpha/alpha-gdbstub.c;alpha-gdbstub;.c;sys/alpha/alpha/;1.16;;17;17;1;/home/ncvs/src/sys/alpha/alpha/Attic/alpha-gdbstub.c;sys


while (<>) {
    my $inAttic;
    chomp;
    @fields = split(/;/);

    if ($fields[8] eq '1') {
	$inAttic = 'TRUE';
    } else {
	$inAttic = 'FALSE';
    }

    for ($i = 0; $i< 4 ; $i++ ) {
	$fields[$i] = Escape_SQL($fields[$i]);
    }
    print OUT "INSERT INTO files(filename, basename, extension, directory, inattic) Values ('$fields[0]','$fields[1]','$fields[2]','$fields[3]',$inAttic);\n";
}

close OUT;



sub Escape_SQL
{
    my ($var) = @_;

    $var =~ s/\'/\'\'/g; #'

    return $var;
}
