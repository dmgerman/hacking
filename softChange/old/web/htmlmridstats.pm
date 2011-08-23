#!/usr/bin/perl -w

package htmlmridstats;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRIDStats'
);

=head1 html class : C<htmlmridstats.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRIDStats (results : [[rownum : int, sourceCode : bool, numFiles : int, filesAdded : int, filesRemoved : int, methodsAdded : int, methodsRemoved : int]]) => body : string

Add the by mrid query results to the body

Parameters:

=over

=item* results => thethe grand total rownum, source code, number of files, files added, files removed , methods added, and methods removed for each file in the MR ID

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub MRIDStats {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-tableTitle => hardcode->MRIDStatsTitle,
		-columnTexts => [hardcode->colsQueryMRIDStats],
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# Source Code?
				htmlSpace(hardcode::booleanText($row->[1])).
				hardcode->nonBreakingSpace,
				
				# Files
				htmlSpace($row->[2]).
				hardcode->nonBreakingSpace,

				# Files Added
				htmlSpace($row->[3]).
				hardcode->nonBreakingSpace,

				# Files Removed
				htmlSpace($row->[4]).
				hardcode->nonBreakingSpace,

				# Methods Added
				htmlSpace($row->[5]).
				hardcode->nonBreakingSpace,

				# Methods Removed
				htmlSpace($row->[6]).
				hardcode->nonBreakingSpace
			);
		}
	);
}

1;
