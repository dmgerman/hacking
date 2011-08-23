#!/usr/bin/perl -w

package htmlrevisiondetails;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'revisionDetails'
);

=head1 html class : C<htmlrevisiondetails.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 revisionDetails (results : [[rownum : int, filename : string, revisionid : string, prevrevisionid : string, nextrevisionid : string, linesAdded : int, linesRemoved : int, diff : string]]) => body : string

Add the by month query results to the body

Parameters:

=over

=item* results => the rownum, filename, selected revision id, previous revision id, next revision id, lines added, lines removed, and diff of the selected revision

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub revisionDetails {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-tableTitle => hardcode::revisionDetailsTitle($this->getRevisionSelect()),
		-columnTexts => [hardcode->colsRevisionDetails],
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			# We need the mrid to optimize the page
			my $mrid = $this->getMRIDSelect();
			
			# The selected revision is need not be a URL, since this is the display
			# for the selected revision id. The next and previous ids shd be URLs.
			return (
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
							hardcode->cgiQueryFileNameDefaultSort,
						hardcode->cgiParmQuerySortDir =>
							hardcode->cgiQuerySortDefaultDir
					},
					1)},
					htmlSpace($row->[1])
				).hardcode->nonBreakingSpace,
				
				# Revision ID
				htmlSpace($row->[2]).
				hardcode->nonBreakingSpace,
				
				# Previous Revision ID
				# Add the mrid to the result
				$row->[3] ?
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
						hardcode->cgiParmQueryRevisionSelect => $row->[3],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryRevisionDefaultSort
						},
						1
					)},
					htmlSpace($row->[3])
				).hardcode->nonBreakingSpace :
				hardcode->nonBreakingSpace,
				
				# Next Revision ID
				# Add the mrid to the result
				$row->[4] ?
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
						hardcode->cgiParmQueryRevisionSelect => $row->[4],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryRevisionDefaultSort
						},
						1
					)},
					htmlSpace($row->[4])
				).hardcode->nonBreakingSpace :
				hardcode->nonBreakingSpace,

				# Lines Added
				htmlSpace($row->[5]).
				hardcode->nonBreakingSpace,

				# Lines Removed
				htmlSpace($row->[7] ? $row->[6] : "").
				hardcode->nonBreakingSpace,

				# Diff Lewngth
				# For some reason, length() in perl is one char less than
				# what the php code comes up with.
				htmlSpace($row->[7] ? length($row->[7]) + 1 : "").
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
