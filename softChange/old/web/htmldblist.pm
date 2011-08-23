#!/usr/bin/perl -w

package htmldblist;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'databaseList'
);

=head1 html class : C<htmldblist.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 databaseList (results : [[rownum : int, databasename : string]]) => body : string

Add the database list to the body

Parameters:

=over

=item* results => the rownum and database name for each database that is probably compatible with softChange

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub databaseList {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-columnTexts => [hardcode->colsQueryDBList],
		-sortValues => [hardcode->cgiQueryDBListSortBy],
		-sortDefault => hardcode->cgiQueryDBListDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# Project
				$q->a({
					-href => $this->getSelfURL(
						{hardcode->cgiParmDB => $row->[1],
						hardcode->cgiParmQuery =>
							hardcode->cgiQueryDefault,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByQuery,
						hardcode->cgiParmSupportedTables =>
							$row->[2]
						},
						1
					)},
					ucfirst $row->[1]
				).
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
