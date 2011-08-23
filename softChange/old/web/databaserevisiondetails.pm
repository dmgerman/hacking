#!/usr/bin/perl -w

package databaserevisiondetails;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getRevisionDetails'
);

=head1 databaseAccess class : C<databaserevisiondetails.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getRevisionDetails () => results : [more : bool, rows : [rownum : int, filename : string, revid : string, previd : string, nextrev : string, linessAdded : int, linesRemoved : int, length : int]]

Get the sorted list of months for the MRs.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, filename, revision id, previous revision id, next revision id, lines added, lines removed, and diff length of the selected revision

=back

=cut
sub getRevisionDetails {
	my $this = shift;
	
	return $this->databaseQuery(
		-getQuery => sub {
			my %parms = @_;
			my $file = $parms{-fileselect};
			my $rev = $parms{-revisionselect};
			
			# Get the details except for the next revision id to start with.
			# There may not be a next revision id.	
			return "
			SELECT
				prevrevisionid,
				linesAdd,
				abs(linesRm),
				diff,
				diffclean
			FROM
				revisiondiffs d, revisions r
        		WHERE
				r.filename = '$file' AND
				r.revisionid = '$rev' AND
				d.filename = r.filename AND
				d.revisionid = r.revisionid
			;";
		},
		-queryDebugFlag => hardcode->dbQueryRevisionDetailsDebug,
		-queryDebugMsg => 'get revision details',
		-getRow => sub {
			my %parms = @_;
			my $file = $parms{-fileselect};
			my $rev = $parms{-revisionselect};
			my $row = $parms{-row};
			
			# Get the next revision id
			my $details = $this->databaseQuery(
				-getQuery => sub {
					my %parms = @_;
					my $file = $parms{-fileselect};
					my $rev = $parms{-revisionselect};
					
					return "
					SELECT
						revisionid
					FROM
						revisiondiffs
					WHERE
						filename = '$file' AND
						prevrevisionid = '$rev'
					;";
				},
				-queryDebugFlag => hardcode->dbQueryRevisionDetailsDebug,
				-queryDebugMsg => 'get next revision id'
			);
			
			# Extract just the next revision id from the details.
			# There may not be a next revision id. Make sure there is
			# more than one row (the first one has the more flag),
			# then we know we got a next revision id.
			my $nextID =
				@{$details} > 1 ?
				$details->[1]->[1] :
				"";
			
			# Combine the filename, revision id, next revision id and details
			# into a single row to return. Skip the line number column of the details.
			$row = [$file, $rev, $row->[0], $nextID, $row->[1], $row->[2], $row->[3], $row->[4]];
			
			# Return the new row
			return $row;
		}
	);
}

1;
