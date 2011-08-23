#!/usr/bin/perl -w

package databasebymonth;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRByMonth'
);

=head1 databaseAccess class : C<databasebymonth.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRByMonth () => results : [more : bool, rows : [rownum : int, month : date, count : int]]

Get the sorted list of months for the MRs.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, month, and count of the MRs by month

=back

=cut
sub getMRByMonth {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryMonthDefaultSort,
		-sortValues => [hardcode->cgiQueryMonthSortBy],
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
				date(date_trunc('month', daterev)) as month, count(*) as count
			FROM
				mrs2
        		WHERE
				$dev AND $dates
        		GROUP BY
				month
			ORDER BY
				$sort $sortDir
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQueryByMonthDebug,
		-queryDebugMsg => 'get mrs by month',
	);
}

1;
