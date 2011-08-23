#!/usr/bin/perl -w

package htmlrevisiondefs;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'revisionDefs'
);

=head1 html class : C<htmlrevisiondefs.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 revisionDefs (results : [[rownum : int, name : string, type : string]], title : string) => body : string

Add the differences in definitions to the body

Parameters:

=over

=item* results => the rownum, name, and type of definitions added or removed by the selected revision

=item* title => the title to add before all the rows, spanning all the columns

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=head4 Note: The caller may use this function for both the added and the removed definitions with two seperate calls

=cut
sub revisionDefs {
	my $this = shift;
	my $defs = shift;
	my $title = shift;
	
	# Add the sub table containing the removed definitions.
	# The columns passed to it are the columns of the subtable.
	return $this->generateHTML(
		-results => $defs,
		-columnTexts => [hardcode->colsRevisionDefs],
		-tableOuterTitle => $title,
		-tableOuterSpan => 3,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# Function/Method Name
				htmlSpace($q->b($row->[1])).
				hardcode->nonBreakingSpace,

				# Type
				htmlSpace(ucfirst($row->[2])).
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
