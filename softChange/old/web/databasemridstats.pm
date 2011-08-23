#!/usr/bin/perl -w

package databasemridstats;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRIDStats'
);

=head1 databaseAccess class : C<databasemridstats.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRIDStats () => results : [more : bool, rows : [rownum : int, sourceCode : bool, numFiles : int, filesAdded : int, filesRemoved : int, methodsAdded : int, methodsRemoved : int]]

Get the stats of the selected MR ID.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the grand total rownum, source code, number of files, files added, files removed , methods added, and methods removed for each file in the MR ID

=back

=cut
sub getMRIDStats {
	my $this = shift;
	my $h = $this->{'h'};
	
	return $this->databaseQuery(
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			my $select = $parms{-mridselect};
			
			return "
			SELECT
				code,
				filesCount,
				filesAdded,
				filesRemoved,
				methodsAdded,
				methodsRemoved
			FROM
				mrstats
			WHERE
				mrid = '$select'
			;";
		},
		-queryDebugFlag => hardcode->dbQueryMRIDStatsDebug,
		-queryDebugMsg => 'get mr id stats'
	);
}

1;
