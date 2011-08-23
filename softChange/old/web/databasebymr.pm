#!/usr/bin/perl -w

package databasebymr;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRDetail'
);

=head1 databaseAccess class : C<databasebymr.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRDetail () => results[more : bool, rows : [rownum : int, mrid : string, author : string, count : int, date : string, time : string, log : string])

Get the details of the MRs of the selected month or the selected mrid.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, mrid, author, number of files modified, date, time, and log for each mr by author or by date

=back

=cut
sub getMRDetail {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryMRDefaultSort,
		-sortValues => [hardcode->cgiQueryMRSortBy],
		-getSortField => sub {
			my $sort = shift;
			
			# Don't sort in SQL if sorting by the number of files
			return
				$sort ne (hardcode->cgiQueryMRSortBy)[3] ?
				$sort :
				"";
		},
		-getQuery => sub {
			my %parms = @_;
			my $query = $parms{-query};
			my $detail = $parms{-detail};
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $oneDay = $parms{-selectedDay};
			my $oneAuthor = $parms{-selectedAuthor};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			my $mrselect = $parms{-mrselect};
			my $mridselect = $parms{-mridselect};
			
			# If the sort field is the number of files, don't sort
			my $sortCriteria = 
				$sort ?
				"ORDER BY $sort $sortDir" :
				"";
			
			# Choose the select field and value acc to whether
			# it is by month or by author
			my $selCriteria;
			my $select;
			if ($detail eq hardcode->cgiQueryDetailByMR) {
				# Selecting a set of mrs by month or author
				if ($query eq hardcode->cgiQueryMonth) {
					$selCriteria = "date(date_trunc('month', daterev))";
					$select = $mrselect;
				} else {
					$selCriteria = "author";
					$select = $mrselect;
				}
			} else {
				# Selecting an mrid
				$selCriteria = 'mrid';
				$select = $mridselect;
			}
			
			# Also select a particular day or author if necessary
			$oneDay = $oneDay ? "daterev = '$oneDay'" : 'TRUE';
			$oneAuthor = $oneAuthor ? "author = '$oneAuthor'" : 'TRUE';
			
			# The offset and limit shd not be used for
			# the mrid page.
			if ($detail eq hardcode->cgiQueryDetailByMRID) {
				$offset = 0;
				$limit = 'ALL';
			}
			
			return "
			SELECT
				mrid, author, daterev, timerev, log
			FROM
				mrs2
        		WHERE
				$dev AND $dates AND
				$selCriteria = '$select' AND
				$oneDay AND $oneAuthor
			$sortCriteria
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQueryByAuthorDebug,
		-queryDebugMsg => 'get mrs by month/author',
		-getRow => sub {
			my %parms = @_;
			my $row = $parms{-row};
			
			# Perform a subquery to get the number of files
			my $count = $this->databaseQuery(
				-getQuery => sub {
					return "
					SELECT
						count(*)
					FROM
						mrsfiles
					WHERE
						mrid = '".$row->[0]."'
					GROUP BY
						mrid
					;";
				},
				-queryDebugFlag => hardcode->dbQueryByAuthorDebug,
				-queryDebugMsg => 'get number of files'
			);
			
			# Remember when returning the number of files that
			# count is [more : bool, [rownum : int, count : int]],
			# so we want the 2nd element of the 2nd element.
			return [
				$row->[0], 
				$row->[1], 
				$count->[1]->[1], 
				$row->[2], 
				$row->[3], 
				$row->[4]
			];
		},
		-getSortedResults => sub {
			my %parms = @_;
			my $detail = $parms{-detail};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $results = $parms{-results};
			
			# If the data is to be sorted by bug numbers, do that now.
			# Unlike the sorting of the actual list of bug numbers, this
			# sort is always performed acc to the specified direction.
			if ($detail eq hardcode->cgiQueryDetailByMR && ! $sort) {
				if ($sortDir eq hardcode->cgiQuerySortDirAsc) {
					@{$results} = sort {$a->[2] <=> $b->[2]} @{$results};
				} else {
					@{$results} = sort {$b->[2] <=> $a->[2]} @{$results};
				}
			}
			
			# Return the sorted data
			return $results;
		},
		-getManualLimitFlag => sub {
			my %parms = @_;
			my $sort = $parms{-sort};
			
			# If sorting by bug numbers, then do manual limit and offset,
			# otherwise let SQL do it.
			return $sort ? 0 : 1;
		}
	);
}

1;
