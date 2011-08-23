#!/usr/bin/perl -w

package databasefilerevtomrid;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRIDFromFileRev'
);

=head1 databaseAccess class : C<databasefilerevtomrid.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 This module is not currently in use because it isn't necessary. It may or may not be used at some point in the future.

=head3 getMRIDFromFileRev () => mrid : string

Get the mrid from the filename and revision id..

Parameters:

=over

=item* none

=back

Returns:

=over

=item* mrid => the mrid of the MR corresponding to the given filename and revision id

=back

=cut
sub getMRIDFromFileRev {
	my $this = shift;
	
	my $result = $this->databaseQuery(
		-getQuery => sub {
			my %parms = @_;
			my $file = $parms{-fileselect};
			my $rev = $parms{-revisionselect};
			
			return "
			SELECT
				f.mrid
			FROM
				mrsfiles f,
				mrs2
        		WHERE
				f.filename = '$file' AND
				f.revisionid = '$rev' AND
				f.mrid = mrs2.mrid
			;"
		},
		-queryDebugFlag => hardcode->dbQueryFileRevToMRIDDebug,
		-queryDebugMsg => 'get mrid from filename and rev id',
	);
	
	# Pick the mrid out of the result
	if ($result->[1] && $result->[1]->[1]) {
		$result = $result->[1]->[1];
	}
}

1;
