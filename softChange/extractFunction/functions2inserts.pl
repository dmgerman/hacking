#!/usr/bin/perl

# sample line
#./a11y/addressbook/ea-addressbook-view.c::r20183::york::ea_ab_view_class_init::A::0::8


print <<END;
  drop table funcmod;
  create table funcmod(
       filename varchar(140),
       function varchar(100),
       revid integer,
       author   varchar(20),
       typemod  char,
       sizeBefore integer,
       sizeAfter  integer,
       hunks      integer,
       linesadd   integer,
       linesdel   integer
--      primary key (filename, function, revision)
    );

END

while (<>) {
    chomp;
    @fields = split(/::/);
    $fields[0] =~ s@^\./@@;
    $fields[1] =~ s/^r//;

    if ($fields[4] eq 'A') {
	$before = 'NULL'; 
    } else {
	$before = $fields[5];
    }
    if ($fields[4] eq 'D') {
	$after = 'NULL'; 
    } else {
	$after = $fields[6];
    }
    # hunks etc
    my $hunks = 1;
    my $linesadd;
    my $linesdel;
    if ($fields[4] eq 'M') {
	my @f2 = split(';', $fields[7]);
	$hunks = $f2[0];
	$linesdel = $f2[1];
	$linesadd = $f2[2];
    } elsif ($fields[4] eq 'D' ) {
	$linesadd = 0;
	$linesdel = $before;
    }elsif ($fields[4] eq 'A' ) {
	$linesadd = $after;
	$linesdel = 0;
    } else  {
	$linesadd = 0;
	$linesdel = 0;
    }
	

    print "insert into funcmod(filename, function, revid, author,typemod,sizeBefore, sizeAfter, hunks,linesadd,linesdel) values ('$fields[0]', '$fields[3]', $fields[1], '$fields[2]','$fields[4]', $before, $after, $hunks, $linesadd, $linesdel);\n";
}
