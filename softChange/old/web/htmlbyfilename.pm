#!/usr/bin/perl -w

package htmlbyfilename;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRByFileName'
);

=head1 html class : C<htmlbyfilename.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRByFileName (results : [[numrow : int, mrid : string, author : string, revisionid : string, added : int, removed : int, abs : int, state : string, date : string, time : string, log : string]]) => body : string

Add the by query results for a specific filename to the body

Parameters:

=over

=item* results => the rownum, mrid, author, revisionid, lines added, lines removed, |added| + |removed|, state, date, time, and log of each MR for a specific filename

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRByFileName {
	my $this = shift;
	my $results = shift;
	
	# If the revisondiffs table is supported, then the revision id
	# is a url to the revision details page.
	my $diffs = $this->supportedTables()->{'revisiondiffs'};
	
	return $this->generateHTML(
		-results => $results,
		-tableTitle => hardcode::byFileDetailTitle($this->getFileSelect()),
		-columnTexts => [hardcode->colsQueryFileName],
		-sortValues => [hardcode->cgiQueryFileNameSortBy],
		-sortDefault => hardcode->cgiQueryFileNameDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# MRID
				$q->a({
					-href => $this->getSelfURL({
						hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMRID,
						hardcode->cgiParmQueryMRIDSelect => $row->[1],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRIDDefaultSort,
						hardcode->cgiParmQuerySortDir =>
							hardcode->cgiQuerySortDefaultDir
					})},
					htmlSpace($row->[1])
				).
				hardcode->nonBreakingSpace,

				# Author
				$q->a({
					-href => $this->getSelfURL(
						{hardcode->cgiParmDB =>
							$this->getDatabase(),
						hardcode->cgiParmSupportedTables =>
							$this->supportedTables(),
						hardcode->cgiParmQuery =>
							hardcode->cgiQueryAuthor,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMR,
						hardcode->cgiParmQueryMRSelect => $row->[2],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort
						},
						1
					)},
					htmlSpace($row->[2])
				).hardcode->nonBreakingSpace,
				
				# Revision ID
				# Add the mrid to the URL
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
						hardcode->cgiParmQueryMRIDSelect => $row->[1],
						hardcode->cgiParmQueryFileSelect => $this->getFileSelect(),
						hardcode->cgiParmQueryRevisionSelect => $row->[3],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryRevisionDefaultSort
						},
						1
					)},
					htmlSpace($row->[3])
				).hardcode->nonBreakingSpace :
				htmlSpace($row->[3]).hardcode->nonBreakingSpace,

				# Lines Added
				htmlSpace($row->[4]).
				hardcode->nonBreakingSpace,

				# Lines Temoved
				htmlSpace($row->[5]).
				hardcode->nonBreakingSpace,

				# Lines Abs
				htmlSpace($row->[6]).
				hardcode->nonBreakingSpace,

				# State
				htmlSpace($row->[7]).
				hardcode->nonBreakingSpace,
				
				# Date
				$q->a({
					-href => $this->getSelfURL(
						{hardcode->cgiParmDB =>
							$this->getDatabase(),
						hardcode->cgiParmSupportedTables =>
							$this->supportedTables(),
						hardcode->cgiParmQuery =>
							hardcode->cgiQueryMonth,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMR,
						hardcode->cgiParmQueryMRSelect => 
							$this->getSQLMonth($row->[8])."-01",
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort,
						hardcode->cgiParmQueryDate => $row->[8]
						},
						1
					)},
					htmlSpace($c->getFormattedDate($row->[8]))
				).
				hardcode->nonBreakingSpace,

				# Time
				htmlSpace($this->getFormattedTime($row->[9])).
				hardcode->nonBreakingSpace,
				
				# Description
				$q->pre(formatLog($row->[10]))
			);
		}
	);
}

1;
