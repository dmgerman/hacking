#!/usr/bin/perl -w

package htmlbymonth;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRByMonth'
);

=head1 html class : C<htmlbymonth.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRByMonth (results : [[rownum : int, month : date, count : int]]) => body : string

Add the by month query results to the body

Parameters:

=over

=item* results => the rownum, month, and number of MRs for each month

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRByMonth {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-columnTexts => [hardcode->colsQueryMonth],
		-sortValues => [hardcode->cgiQueryMonthSortBy],
		-sortDefault => hardcode->cgiQueryMonthDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# Month
				$q->a({
					-href => $this->getSelfURL({
						hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMR,
						hardcode->cgiParmQueryMRSelect => $row->[1],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort,
						hardcode->cgiParmQuerySortDir =>
							hardcode->cgiQuerySortDefaultDir
					})},
					htmlSpace($this->getFormattedMonth($row->[1]))
				).hardcode->nonBreakingSpace,

				# Count
				htmlSpace($row->[2]).
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
