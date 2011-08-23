#!/usr/bin/perl -w

package databasebyfile;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRByFile'
);

=head1 databaseAccess class : C<databasebyfile.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRByFile () => results : [more : bool, rows : [rownum : int, filename : string, numrevisions : int, numauthors : int, first : date, last : date]]

Get the list of MR files for the database.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, filename, number of distinct revisions, number of distinct authors, earliest and latest dates for each MR by file

=back

=cut
sub getMRByFile {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryFileDefaultSort,
		-sortValues => [hardcode->cgiQueryFileSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			
			return "
			SELECT 
				filename, count(distinct mrs2.mrid) as mrs, 
				count(distinct author) as author, 
				min(mrsfiles.daterev) as first, 
				max(mrsfiles.daterev) as last
			FROM
				mrsfiles, mrs2
			WHERE
				mrs2.mrid = mrsfiles.mrid
				AND $dev AND $dates
			GROUP BY
				filename
			ORDER BY
				$sort $sortDir
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQueryByFileDebug,
		-queryDebugMsg => 'get mrs by file',
	);
}

1;
