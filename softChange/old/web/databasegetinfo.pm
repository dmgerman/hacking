#!/usr/bin/perl -w

package databasegetinfo;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getInfo'
);

=head1 databaseAccess class : C<databasegetinfo.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getInfo () => results : [more : bool, rows : [key : string, value : string]]

Get the data from the info table.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => irrelevant, this query is only ever performed once per project session

=item* rows => the key,value pairs of information

=back

=cut
sub getInfo {
	my $this = shift;
	
	return $this->databaseQuery(
		-getQuery => sub {
			return "
			SELECT
				key, value
			FROM
				info
			ORDER BY
				serial
			;"
		},
		-queryDebugFlag => hardcode->dbQueryInfoDebug,
		-queryDebugMsg => 'get information',
	);
}

1;
