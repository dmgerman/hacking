#!/usr/bin/perl -w

package databasebymrid;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRIDDetail'
);

=head1 databaseAccess class : C<databasebymrid.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRIDDetail () => results : [more : bool, rows : [rownum : int, filename : string, revisionid : string, add : int, remove : int, add + remove : int, state : string]]

=head3 getMRIDDetail () => results : [more : bool, rows : [rownum : int, filename : string, revisionid : string, add : int, remove : int, add + remove : int, state : string, methodsAdded : int, methodsRemoved : int, methodsAfter : int, methodsBefore : int]]

Get the details of the selected MR ID.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, filename, revisionid, lines added, lines removed, total lines, and state for each file in the MR ID. If the methoddeltas table exists, then the methods added, methods removed, methods after, and methodsbefore are added.

=back

=cut
sub getMRIDDetail {
	my $this = shift;
	my $h = $this->{'h'};
			
	# If the methoddeltas table exists, then query it for each file
	# to get the methods added, removed, before, and after.
	my $deltas = $h->supportedTables()->{'methoddeltas'};
			
	# Keep track of totals so we can add a totals row to the end
	my $totalRevisions = 0;
	my $totalLinesAdded = 0;
	my $totalLinesRemoved = 0;
	my $totalLinesAbs = 0;
	my $totalMethodsAdded = 0;
	my $totalMethodsRemoved = 0;
	
	my $result = $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryMRIDDefaultSort,
		-sortValues => [hardcode->cgiQueryMRIDSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			my $select = $parms{-mridselect};
			
			return "
			SELECT
				mrsfiles.filename, mrsfiles.revisionid, linesadd,
				abs(linesrm) as linesrm, linesadd + linesrm as linestotal, state
			FROM
				mrsfiles, revisions, mrs2
			WHERE
				mrs2.mrid = '$select' AND
				mrs2.mrid = mrsfiles.mrid AND
				mrsfiles.filename = revisions.filename AND
				mrsfiles.revisionid = revisions.revisionid
				AND $dev AND $dates
			ORDER BY
				$sort $sortDir
			OFFSET
				$offset
			LIMIT
				$limit
			;";
		},
		-queryDebugFlag => hardcode->dbQueryMRIDDebug,
		-queryDebugMsg => 'get mrs by id',
		-getRow => sub {
			my %mainParms = @_;
			my $mainRow = $mainParms{-row};
			
			# Add to the main totals
			$totalRevisions++;
			$totalLinesAdded += $mainRow->[2];
			$totalLinesRemoved += $mainRow->[3];
			$totalLinesAbs += $mainRow->[4];
			
			if ($deltas) {
				# Perform a subquery on the filename and add some columns
				my $deltaColumns = $this->databaseQuery(
					-getQuery => sub {
						return "
						SELECT
							methodsadded,
							methodsdeleted,
							methodsafter,
							methodsbefore
						FROM
							methoddeltas
						WHERE
							filename = '$mainRow->[0]' AND
							revisionid = '$mainRow->[1]'
						;";
					},
					-queryDebugFlag => hardcode->dbQueryMRIDDebug,
					-queryDebugMsg => 'get files in mr'
				);
				
				# Add the extra columns to the main row
				# Extra columns are in 2nd row, 1st row is more flag.
				# Skip the 1st col of 2nd row, it's the line number.
				my $index = @{$mainRow};
				map {$mainRow->[$index++] = $_} @{$deltaColumns->[1]}[1 .. 4];
			
				# Add to the methoddeltas totals
				$totalMethodsAdded += $mainRow->[6];
				$totalMethodsRemoved += $mainRow->[7];
			}
			
			return $mainRow;
		}
	);
	
	# Create a totals line, including a line number column.
	my $totalLine = [scalar(@{$result}),
		hardcode->termTotal,
		$totalRevisions,
		$totalLinesAdded,
		$totalLinesRemoved,
		$totalLinesAbs,
		""];
		
	# Add total method deltas only if deltas are supported
	push @{$totalLine},
		$totalMethodsAdded,
		$totalMethodsRemoved,
		"",
		""
		if $deltas;
	
	# Add the totals line to the data
	push @{$result}, $totalLine;
	
	# Return the data
	return $result;
}

1;
