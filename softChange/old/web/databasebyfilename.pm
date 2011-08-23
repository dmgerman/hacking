#!/usr/bin/perl -w

package databasebyfilename;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMRByFileName'
);

=head1 databaseAccess class : C<databasebyfilename.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMRByFileName () => results : [more : bool, rows : [rownum : int, mrid : string, author : string, revisionid : string, added : int, removed : int, abs : int, state : string, date : string, time : string, log : string]]

Get the list of MR files for the database

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, mrid, author, revisionid, lines added, lines removed, |added| + |removed|, state, date, time, and log for each MR of a specified filename

=back

=cut
sub getMRByFileName {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryFileNameDefaultSort,
		-sortValues => [hardcode->cgiQueryFileNameSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $dev = $parms{-developers};
			my $dates = $parms{-dateRange};
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			my $offset = $parms{-offset};
			my $limit = $parms{-limit};
			my $file = $parms{-fileselect};
			
			return "
			SELECT
				mrsfiles.mrid, author, revisionid, 
				linesadd, abs(linesrm) as linesrm,
				linesadd + linesrm as linesabs,
				state, mrsfiles.daterev, mrsfiles.timerev, log 
			FROM
				revisions natural join mrsfiles, mrs2
			WHERE
				mrsfiles.mrid = mrs2.mrid AND
				filename='$file'
				AND $dev AND $dates
			ORDER BY
				$sort $sortDir
			OFFSET
				$offset
			LIMIT
				$limit
			;"
		},
		-queryDebugFlag => hardcode->dbQueryByFileNameDebug,
		-queryDebugMsg => 'get mrs by file name',
	);
}

# Return true
1;
