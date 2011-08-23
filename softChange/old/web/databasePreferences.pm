#!/usr/bin/perl -w

package databasePreferences;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getDeveloperList',
	'getDateRanges'
);

=head1 databaseAccess class : C<databasePreferences.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getDeveloperList () => results : [more : bool, rows : [rownum : int, author : string]]

Get the list of developers

Parameters:

=over

=item* none

=back

Returns: 

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum and name of each author

=back

=head4 Note: A database must be opened before calling this method

=cut
sub getDeveloperList {
	my $this = shift;
	
	return $this->databaseQuery(
		-getQuery => sub {
			return "
			SELECT
				DISTINCT author 
        		FROM
				mrs2 
        		ORDER BY
				author
			;"
		},
		-queryDebugFlag => hardcode->dbQueryDevListDebug,
		-queryDebugMsg => 'list all developers',
	);
}

=head3 getDateRanges () => results : [more : bool, rows : [minMonth : int, maxMonth : int, minDay : int, maxDay : int, minYear : int, maxYear : int]]

Get the minimum and maximum ranges for month, day, and year

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* minMonth, minDay, minYear => the month, day, and year of the earliest date

=item* maxMonth, maxDay, maxYear => the month, day, and year of the latest date

=back

=head4 Note: A database must be opened before calling this method

=cut
sub getDateRanges {
	my $this = shift;
	
	return $this->databaseQuery(
		-getQuery => sub {
			return "
			SELECT
				extract (month from min(daterev)),
				extract (month from max(daterev)),
				extract (day from min(daterev)),
				extract (day from max(daterev)),
				extract (year from min(daterev)),
				extract (year from max(daterev))
			FROM
				mrs2
			;"
		},
		-queryDebugFlag => hardcode->dbQueryDateRangesDebug,
		-queryDebugMsg => 'get date ranges',
	);
}

1;
