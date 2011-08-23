#!/usr/bin/perl -w

package htmlpath;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getPath'
);

=head1 html class : C<htmlpath.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 This module is not currently in use because it doesn't work. It may or may not be used at some point in the future.

The idea is to provide a path that shows how the set of clicks the user made that got them to the
current page being displayed. The user could then click on any path element except the last one
to go back to a previously viewed page. Each element describes the page that will show if the
element is clicked on, with the last element describing the current page.

=head3 getPath () => path : string

Parameters:

=over

=item* none

=back

Returns:

=over

=item* path => The path as a series of URLs

=back

=cut
sub getPath {
	my $this = shift;
	my $q = $this->{'q'};
	
	# The resulting path to return
	my $results = "";
	
	# Don't do anything for the list of databases page
	if ($this->getQuery() ne hardcode->cgiQueryList) {
		# Get all the pieces together we may need to use
		# for the path, then we can put togther whatever
		# pieces we want.

		# The values of the parameters
		my $database = $this->getDatabase();
		my $detail = $this->getDetail();
		my $mrselect = $this->getMRSelect();
		my $mridselect = $this->getMRIDSelect();
		my $fileselect = $this->getFileSelect();
		
		# The type of query
		my $query = $this->getQuery();

		# The text to use for path pieces
		my $databaseText = htmlSpace(
			hardcode->cgiPathValDatabase." ".ucfirst $database
		);
		
		my $queryText = htmlSpace(
			hardcode->titleURLTexts->{$query}
		);
		
		my $mrText;
		if ($query eq hardcode->cgiQueryMonth) {
			$mrText = 
				hardcode->cgiPathValMonthDetail."  '".
				$this->getSQLMonth($mrselect)."'";
		} else {
			$mrText = 
				hardcode->cgiPathValAuthorDetail."  '".
				$mrselect."'";
		}
		$mrText = htmlSpace($mrText);
		
		my $mridText = htmlSpace(
			hardcode->cgiPathValMRDetail." '".$mridselect."'"
		);
		
		my $fileText = htmlSpace(
			hardcode->cgiPathValFileDetail." '".$fileselect."'"
		);

		# The urls to use for path pieces

		# Complete URL with database only
		my $dbURL = 
			$q->script_name().
			"?".
			hardcode->cgiParmDB.
			"=".
			$database;
		my $dbHref = $q->a(
			{-href => $dbURL}, 
			$databaseText
		);

		# Add the by query portion
		my $queryURL = 
				$dbURL.
				"&".
				hardcode->cgiParmQuery.
				"=".
				$query;
		my $queryHref = $q->a(
			{-href => 
				$queryURL.
				"&".
				hardcode->cgiParmQueryDetail.
				"=".
				hardcode->cgiQueryDetailByQuery
			},
			$queryText
		);

		# Add the mr portion
		my $mrURL = 
				$dbURL.
				"&".
				hardcode->cgiParmQuery.
				"=".
				hardcode->cgiQueryMonth.
				"&".
				hardcode->cgiParmQueryMRSelect.
				"=".
				$mrselect;
		my $mrHref = $q->a(
			{-href =>
				$mrURL.
				"&".
				hardcode->cgiParmQueryDetail.
				"=".
				hardcode->cgiQueryDetailByMR
			},
			$mrText
		);
		
		# Add the file portion
		my $fileURL =
			$queryURL.
			"&".
			hardcode->cgiParmQueryFileSelect.
			"=".
			$fileselect;
		my $fileHref = $q->a(
			{-href =>
				$queryURL.
				"&".
				hardcode->cgiParmQueryDetail.
				"=".
				hardcode->cgiQueryDetailByFile.
				"&".
				hardcode->cgiParmQueryFileSelect.
				"=".
				$fileselect
			},
			$fileText
		);


		# Create the path

		$results = $dbHref.hardcode->pathSeparator;
		DETAIL: {
			($detail eq hardcode->cgiQueryDetailByQuery) && do {
				# Database and query type
				$results .= $queryText;
				last DETAIL;
			};
		
			($detail eq hardcode->cgiQueryDetailByFile) && do {
				# Database, query, and file
				$results .=
					$queryHref.
					hardcode->pathSeparator.
					$fileText;
				last DETAIL;
			};

			($detail eq hardcode->cgiQueryDetailByMR) && do {
				# Database, query, file, and MR
				$results .=
					$queryHref.
					hardcode->pathSeparator.
					$fileHref.
					hardcode->pathSeparator.
					$mrText;
				last DETAIL;
			};

			# If coming by file, the path shd be db, query, file, mr, mrid
			($detail eq hardcode->cgiQueryDetailByMRID) && do {
				# Database, query, file, and MR ID
				$results .=
					$queryHref.
					hardcode->pathSeparator.
					$fileHref.
					hardcode->pathSeparator.
					$mridText;
				last DETAIL;
			};		
		}
	}
	
	return ''; #$results ? $q->p($results) : '';
}

1;
