#!/usr/bin/perl -w

package htmlbyauthor;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRByAuthor'
);

=head1 html class : C<htmlbyauthor.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRByAuthor (results : [[rownum : int, name : string, count : int, first : date, last : date]]) => body : string

Add the by author query results to the body

Parameters:

=over

=item* results => the rownum, name, number of MRs, earliest, and latest dates for each author

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRByAuthor {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-columnTexts => [hardcode->colsQueryAuthor],
		-sortValues => [hardcode->cgiQueryAuthorSortBy],
		-sortDefault => hardcode->cgiQueryAuthorDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# Author
				$q->a({
					-href => $this->getSelfURL(
						{hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMR,
						hardcode->cgiParmQueryMRSelect => $row->[1],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort,
						hardcode->cgiParmQuerySortDir =>
							hardcode->cgiQuerySortDefaultDir
						},
					)},
					htmlSpace($row->[1])
				).
				hardcode->nonBreakingSpace,

				# Count
				htmlSpace($row->[2]).
				hardcode->nonBreakingSpace,
				
				# First Date	
				htmlSpace($c->getFormattedDate($row->[3])).
				hardcode->nonBreakingSpace,

				# Last Date
				htmlSpace($c->getFormattedDate($row->[4])).
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
