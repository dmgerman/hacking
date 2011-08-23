#!/usr/bin/perl -w

package htmlbyfile;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRByFile'
);

=head1 html class : C<htmlbyfile.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRByFile (results : [[rownum : int, filename : string, numrevisions : int, numauthors : int, first : date, last : date]]) => body : string

Add the by file name query results to the body

Parameters:

=over

=item* results => the rownum, filename, number of revisions, number of authors, earliest and latest dates for each MR by file name

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRByFile {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-columnTexts => [hardcode->colsQueryFile],
		-sortValues => [hardcode->cgiQueryFileSortBy],
		-sortDefault => hardcode->cgiQueryFileDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# File Name
				$q->a({
					-href => $this->getSelfURL({
						hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByFile,
						hardcode->cgiParmQueryFileSelect => $row->[1],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryFileNameDefaultSort,
						hardcode->cgiParmQuerySortDir =>
							hardcode->cgiQuerySortDefaultDir
					})},
					htmlSpace($row->[1])
				).hardcode->nonBreakingSpace,

				# Revisions
				htmlSpace($row->[2]).
				hardcode->nonBreakingSpace,
					
				# Author
				htmlSpace($row->[3]).
				hardcode->nonBreakingSpace,

				# First Date
				htmlSpace($c->getFormattedDate($row->[4])).
				hardcode->nonBreakingSpace,

				# Last Date
				htmlSpace($c->getFormattedDate($row->[5])).
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
