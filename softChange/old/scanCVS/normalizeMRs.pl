#!/usr/bin/perl

open (OUT, ">cvsNORM.mrs.tmp") || die "uanble to create normalized file\n";
open (OUTFiles, ">cvsNORM.filesmrs.tmp") || die "uanble to create normalized file\n";


while (<>) {
    chomp;
    @fields = split(/;/);
    ($author, $date, $min, $sec) = split(/:/, $fields[0]);
    ($day, $time) = split(/ /, $date);
    $sec =~ s/_.*//g;

    foreach $i (0,1,2,3,6) {
	$fields[$i] = Escape_SQL($fields[$i]);
    }


    print OUT "INSERT INTO mrs(mrid, datemr, author, log) ";
    print OUT "VALUES ('$fields[0]', '$day $time:$min:$sec','$author','$fields[6]');\n";

    print OUTFiles "INSERT INTO revsInMr(mrid, filename, revid) VALUES";
    print OUTFiles "('$fields[0]','$fields[1]','$fields[2]');\n";
}

close OUT;
close OUTFiles;

print `sort -u cvsNORM.mrs.tmp> cvsNORM.mrs`;
print `sort -u cvsNORM.filesmrs.tmp> cvsNORM.filesmrs`;

`rm -f cvsNORM.mrs.tmp`;
`rm -f cvsNORM.filesmrs.tmp`;



sub Escape_SQL
{
    my ($var) = @_;

    $var =~ s/\'/\'\'/g; #'

    return $var;
}
