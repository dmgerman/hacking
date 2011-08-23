#!/usr/bin/perl -w

package databasebybugzilla;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getBugzilla'
);

=head1 databaseAccess class : C<databasebybugzilla.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getBugzilla () => results : [more : bool, rows : [rownum : int, mrid : string, bug : [int], daterev : date, log : string]]

Get the list of bugzilla fixes.

The list of bug numbers comes from a secondary query that runs off each row
of the main query results. When sorting by the bug list, sorting, offsets, and
limits are all performed manually within Perl; sorting is done by ordering the
bug lists according to the first item of each bug list.

Bug lists are always sorted in ascending order, unless the sorting is performed
on the bug lists, and the current sort order is descending.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum mrid, bug list, date and log for each potential bugzilla bugfix

=back

=cut
sub getBugzilla {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryBugzillaDefaultSort,
		-sortValues => [hardcode->cgiQueryBugzillaSortBy],
		-getSortField => sub {
			my $sort = shift;
			
			# Don't do any SQL sorting if sorting by bug numbers
			return
				$sort ne (hardcode->cgiQueryBugzillaSortBy)[2] ?
				$sort :
				"";
		},
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			
			# If the sort field is the bug numbers, don't sort
			my $sortCriteria = 
				$sort ?
				"ORDER BY $sort $sortDir" :
				"";
				
			return "
			SELECT
				mrid, daterev, log
			FROM
				mrs2
			WHERE
				(log ~ '#[0-9][0-9]+' or log ~ '[Bb][Uu][Gg][ ][0-9][0-9]+')
				AND $dev AND $dates
			$sortCriteria
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQueryByBugzillaDebug,
		-queryDebugMsg => 'get bugzilla',
		-getRow => sub {
			my %parms = @_;
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $row = $parms{-row};
			
			# $row refers to a row of [mrid, daterev, log]
			
			# Get the list of bugs being fixed
			my $log = $row->[2];
			
			my @bugs;
			map {
				push @bugs, $_ if $_ =~ /^\d\d+$/;
			} split /(bug\s+|\#)(\d\d+)/i, $log;
			
			# The sort order for the bug lists is ascending,
			# unless we're sorting by bug numbers and the
			# sort order is descending.
			my $bugSortDir = 
				$sort ?
				hardcode->cgiQuerySortDirAsc :
				$sortDir;

			# Sort the bug number list
			if ($bugSortDir eq hardcode->cgiQuerySortDirAsc) {
				@bugs = sort {$a <=> $b} @bugs;
			} else {
				@bugs = sort {$b <=> $a} @bugs;
			}

			return [
				$row->[0], 
				[@bugs], 
				$row->[1], 
				$row->[2]
			];
		},
		-getSortedResults => sub {
			my %parms = @_;
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $results = $parms{-results};
			
			# If the data is to be sorted by bug numbers, do that now,
			# otherwise do nothing, it is already sorted by SQL.
			if (! $sort) {
				if ($sortDir eq hardcode->cgiQuerySortDirAsc) {
					@{$results} = sort {$a->[1]->[0] <=> $b->[1]->[0]} @{$results};
				} else {
					@{$results} = sort {$b->[1]->[0] <=> $a->[1]->[0]} @{$results};
				}
			}
			
			# Return the sorted data
			return $results;
		},
		-getManualLimitFlag => sub {
			my %parms = @_;
			my $sort = $parms{-sort};
			
			# If sorting by bug numbers, do manual limit and offset,
			# otherwise let SQL do it.
			return $sort ? 0 : 1;
		}
	);
}

# Return true
1;
