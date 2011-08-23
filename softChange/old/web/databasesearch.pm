#!/usr/bin/perl -w

package databasesearch;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getSearch'
);

=head1 databaseAccess class : C<databasesearch.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getSearch () => results : [more : bool, rows : [rownum : int, mrid : string, author : string, date : string, time : string, log : string]]

Get the details of the MRs whose logs contain the words specified in the CGI parameters.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, mrid, author, date, time, and log of each matching MR

=back

=cut
sub getSearch {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQuerySearchDefaultSort,
		-sortValues => [hardcode->cgiQuerySearchSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};

			# The AND words to search for
			my $withAll = $parms{-searchWithAll};
			if ($withAll) {
				$withAll =~ s/(\S+)/log ~* '$1'/g;
				$withAll =~ s/\s+/ /g;
				$withAll =~ s/' l/' AND l/g;
			} else {
				$withAll = 'TRUE';
			}

			# The exact phrase to search for
			my $withExact = $parms{-searchWithExact};
			if ($withExact) {
				$withExact = "log ~ '".$withExact."'";
			} else {
				$withExact = 'TRUE';
			}

			# The OR words to search for
			my $withAny = $parms{-searchWithAtLeast};
			if ($withAny) {
				$withAny =~ s/(\S+)/log ~* '$1'/g;
				$withAny =~ s/\s+/ /g;
				$withAny =~ s/' l/' OR l/g;
			} else {
				$withAny = 'TRUE';
			}

			# The WITHOUT words to not search for
			my $withoutAny = $parms{-searchWithout};
			if ($withoutAny) {
				$withoutAny =~ s/(\S+)/log !~* '$1'/g;
				$withoutAny =~ s/\s+/ /g;
				$withoutAny =~ s/' l'/' AND l/g;
			} else {
				$withoutAny = 'TRUE';
			}

			# The overall criteria to search for
			my $wordCriteria = "
				$withAll AND $withExact AND ($withAny) AND $withoutAny
			";
			
			return "
			SELECT
				mrid, author, daterev, timerev, log
			FROM
				mrs2
			WHERE
				$wordCriteria
			ORDER BY
				$sort $sortDir
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQuerySearchDebug,
		-queryDebugMsg => 'get search',
	);
}

1;
