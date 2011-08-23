#!/usr/bin/perl -w

package databasebyauthor;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRByAuthor'
);

=head1 databaseAccess class : C<databasebyauthor.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRByAuthor () => results : [more : bool, rows : [rownum : int, name : string, count : int, first : date, last : date]]

Get the list of MR authors for the database. First and last represent the earliest
and latest dates of MRs by the author.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, name, count, first , and last of each author

=back

=cut
sub getMRByAuthor {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryAuthorDefaultSort,
		-sortValues => [hardcode->cgiQueryAuthorSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			
			return "
			SELECT
				author, count(*) as count,
				min(daterev) as first, max(daterev) as last
			FROM
				mrs2 
			WHERE
				$dev AND $dates
			GROUP BY
				author
			ORDER BY
				$sort $sortDir
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQueryByAuthorDebug,
		-queryDebugMsg => 'get mrs by author',
	);
}

# Return true
1;
