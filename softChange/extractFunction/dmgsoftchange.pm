#!/usr/bin/perl


sub Get_Author_Of_MR
{
    my ($dbh, $mrid) = @_;
    my $author;
    my $sth = $dbh->prepare("select author from mrs where mrid = ?");
    my $rc = $sth->execute($mrid);
    
    if (($author)  = $sth->fetchrow_array) {
	return $author;
    } else {
	return undef;
    }
}

1;
