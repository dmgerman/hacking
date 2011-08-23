#!/usr/bin/perl -w

package htmlmriddetail;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRIDDetail'
);

=head1 html class : C<htmlmriddetail.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRIDDetail (mrid : string, results : [[rownum : int, filename : string, revisionid : string, added : int, removed : int, total : int, state : string]]) => body : string

Add the by mrid query results to the body

Parameters:

=over

=item* mrid => the current mrid

=item* results => the rownum, filename, revision id, lines added, lines removed, added - removed, and state for each file of the given MRID

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRIDDetail {
	my $this = shift;
	my $mrid = shift;
	my $results = shift;
			
	# The project may support the methoddeltas table, in which case
	# the rows contain extra columns for methods added, deleted,
	# after, and before.
	my $deltas = $this->supportedTables()->{'methoddeltas'};
	
	# If the revisondiffs table is supported, then the revision id
	# is a url to the revision details page.
	my $diffs = $this->supportedTables()->{'revisiondiffs'};
	
	return $this->generateHTML(
		-results => $results,
		-tableTitle => hardcode->MRIDTitle,
		-columnTexts => [hardcode::colsQueryMRIDDetail($deltas)],
		-sortValues => [hardcode->cgiQueryMRIDSortBy],
		-sortDefault => hardcode->cgiQueryMRIDDefaultSort,
		-multipleRows => sub {
			my $row = shift;
			
			# In this case, we have an added 'Totals' row, so the test for
			# multiple rows of data is that there are more than 2 rows,
			# since there will always be the at least one result and the totals line.
			
			return @{$row} > 2;
		},
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
	
			# The last line is a totals line, so it has to not display any
			# URLs, and shd display all the columns in bold.
			my $lastLine = $row->[0] == @{$results};
			
			# The row of data
			my @row;
			
			if ($lastLine) {
				@row = map {$q->b(htmlSpace($_)).hardcode->nonBreakingSpace} @{$row};
				$row[0] = hardcode->nonBreakingSpace.$row[0];
			} else {
				@row = (
					hardcode->nonBreakingSpace.
					htmlSpace($row->[0]).
					hardcode->nonBreakingSpace,

					# File Name
					$q->a({
						-href => $this->getSelfURL(
							{hardcode->cgiParmDB =>
								$this->getDatabase(),
							hardcode->cgiParmSupportedTables =>
								$this->supportedTables(),
							hardcode->cgiParmQuery =>
								hardcode->cgiQueryFile,
							hardcode->cgiParmQueryDetail =>
								hardcode->cgiQueryDetailByFile,
							hardcode->cgiParmQueryFileSelect => $row->[1],
							hardcode->cgiParmQuerySortBy =>
								hardcode->cgiQueryFileDefaultSort
							},
							1
						)},
						htmlSpace($row->[1])
					).hardcode->nonBreakingSpace,

					# Revision ID. Add the mrid passed.
					$diffs ?
					$q->a({
						-href => $this->getSelfURL(
							{hardcode->cgiParmDB =>
								$this->getDatabase(),
							hardcode->cgiParmSupportedTables =>
								$this->supportedTables(),
							hardcode->cgiParmQuery =>
								hardcode->cgiQueryRevision,
							hardcode->cgiParmQueryDetail =>
								hardcode->cgiQueryDetailByQuery,
							hardcode->cgiParmQueryMRIDSelect => $mrid,
							hardcode->cgiParmQueryFileSelect => $row->[1],
							hardcode->cgiParmQueryRevisionSelect => $row->[2],
							hardcode->cgiParmQuerySortBy =>
								hardcode->cgiQueryRevisionDefaultSort
							},
							1
						)},
						htmlSpace($row->[2])
					).hardcode->nonBreakingSpace :
					htmlSpace($row->[2]).
					hardcode->nonBreakingSpace,

					# Lines Added
					htmlSpace($row->[3]).
					hardcode->nonBreakingSpace,

					# Lines Removed
					htmlSpace($row->[4]).
					hardcode->nonBreakingSpace,

					# Lines Total
					htmlSpace($row->[5]).
					hardcode->nonBreakingSpace,

					# State
					htmlSpace($row->[6]).
					hardcode->nonBreakingSpace
				);

				# Add the methoddeltas data if it is supported
				push @row, 
					# Methods Added
					htmlSpace($row->[7]).
					hardcode->nonBreakingSpace,

					# Methods Removed
					htmlSpace($row->[8]).
					hardcode->nonBreakingSpace,

					# Methods After
					htmlSpace($row->[9]).
					hardcode->nonBreakingSpace,

					# Methods Before
					htmlSpace($row->[10]).
					hardcode->nonBreakingSpace

					if $deltas;
			}
			
			return @row;
		}
	);
}

1;
