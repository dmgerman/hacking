#!/usr/bin/perl -w

package htmlbybugzilla;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRByBugzilla'
);

=head1 html class : C<htmlbybugzilla.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRByBugzilla (results : [[rownum : int , mrid : string, bugs : [int], daterev : date, log : string]]) => body : string

Add the by bugzilla query results to the body

Parameters:

=over

=item* results => the rownum, mrid, bug numbers, date, and log of each MR that is likely a Bugzilla fix

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRByBugzilla {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-columnTexts => [hardcode->colsQueryBugzilla],
		-sortValues => [hardcode->cgiQueryBugzillaSortBy],
		-sortDefault => hardcode->cgiQueryBugzillaDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;

			# Format the bug list
			my $bugzilla = $this->bugzillaURL();
			my $bugs = "";
			map {
				$bugs .= $q->br() if $bugs;
				$bugs .= $q->a(
						{-href => $bugzilla.$_},
						$_
					).
					hardcode->nonBreakingSpace;
			} @{$row->[2]};
			
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

				# Bugs
				$bugs,
					
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
							$this->getSQLMonth($row->[3])."-01",
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort,
						hardcode->cgiParmQueryDate => $row->[3]
						},
						1
					)},
					htmlSpace($c->getFormattedDate($row->[3]))
				).hardcode->nonBreakingSpace,

				# Description
				$q->pre(formatLog($row->[4]))
			);
		}
	);
}

1;
