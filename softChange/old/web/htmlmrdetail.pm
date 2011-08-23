#!/usr/bin/perl -w

package htmlmrdetail;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'MRDetail'
);

=head1 html class : C<htmlmrdetail.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 MRDetail (results : [[romnum : int, mrid : string, author : string, numfiles : int, daterev : date, timerev : time, log : string]]) => body : string

Add the query results for a set of MRs for a particular month or author to the body.

Parameters:

=over

=item* results => the rownum, mrid, author, number of files, date, time, and log for each MR by month/author

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=head4 Note: This method is far more complicated than any other due to this code being used in multiple contexts. As a result, it does not use the C<generateHTML()> method.

=cut

sub MRDetail {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	my @texts = hardcode->colsQueryMRDetail;
	my @values = hardcode->cgiQueryMRSortBy;
	my @classes = hardcode->classQueryRows;
	my $dataRows = shift;
	
	# The known good values for the sorting field
	my $sortValues = [
		hardcode->cgiQueryMRDefaultSort,
		@values
	];
	
	# The header row
	my $header;
	
	# The set of rows
	my $rows;
	
	# Which backing to use for each row
	my $backing = 0;
	
	# Is there more than one row of results?
	my $multiple = @{$dataRows} > 1;
	
	# The type of query
	my $query = $this->getQuery();
	
	# The selected author or date
	my $mrselect = $this->getMRSelect();
	
	# Is the query by month?
	my $byMonth = $query eq hardcode->cgiQueryMonth;
	
	# Is the query by author?
	my $byAuthor = $query eq hardcode->cgiQueryAuthor;
	
	# Is the query by file name?
	my $byFile = $query eq hardcode->cgiQueryFile;
	
	# Is the query by bugzilla?
	my $byBugzilla = $query eq hardcode->cgiQueryBugzilla;
	
	# Is the query for search results?
	my $bySearch = $query eq hardcode->cgiQuerySearch;
	
	# Is the query for revision details?
	my $byRevision = $query eq hardcode->cgiQueryRevision;
	
	# The detail of query - by mr or by mrid
	my $byMRID = $this->getDetail() eq hardcode->cgiQueryDetailByMRID;
	
	# Get the month text from the queryMRSelect parameter.
	my $monthText = $byMonth ? "'".$this->getFormattedMonth()."'" : "";
	
	# The title for the table. This page can be displayed in any 
	# of the following pages:
	#
	# by month
	# by author
	# by file name
	# by bugzilla
	# search
	# revision
	#
	# Display the table title as per the page it is embedded in.
	my $tableTitle;
	CASE : {
		$byMonth && do {
			$tableTitle = hardcode::byMonthDetailTitle($monthText);
			last CASE;
		};
		
		$byAuthor && do {
			$tableTitle = hardcode::byAuthorDetailTitle($this->getMRSelect());
			last CASE;
		};
		
		$byFile && do {
			$tableTitle = hardcode::byFileDetailTitle($this->getFileSelect());
			last CASE;
		};
		
		$byBugzilla && do {
			$tableTitle = hardcode::byBugzillaMRIDTitle($this->getMRIDSelect());
			last CASE;
		};
		
		$bySearch && do {
			$tableTitle = hardcode::searchMRIDTitle($this->getMRIDSelect());
			last CASE;
		};
		
		$byRevision && do {
			# In this case, this table is the second table in a series of tables,
			# the first one already has a title.
			$tableTitle = "";
			last CASE;
		};
	};
	
	# The sort by value
	my $sortBy =
		$byMRID ?
		hardcode->cgiQueryMRDefaultSort :
		$this->getSort($sortValues);
	
	# If bymrid, then the author column shd be a url to by author,
	# and the date column shd be a url to by month.
	my $authSortBy = $sortBy;
	my $dateSortBy = $sortBy;
	if ($byMRID) {
		$authSortBy = (hardcode->cgiQueryMRSortBy)[4];
		$dateSortBy = (hardcode->cgiQueryMRSortBy)[2];
	}
	
	# Is the query is by file name or by bugzilla or by revision and it's the mrid page?
	my $byFileOrBugzillaorRevisionMRID =
		($query eq hardcode->cgiQueryFile ||
		$query eq hardcode->cgiQueryBugzilla ||
		$query eq hardcode->cgiQueryRevision) && $byMRID;
	
	# The current queryDeveloper
	my $dev = $this->getDeveloper();
	
	# The current date
	my $date = $this->getDate();
	
	# The checks for getSortDir() to perform for each column of the header
	my @checks = ("", "", "", "", "", "", "");
	
	# If the queryDeveloper has been specified, set a check for it
	if ($dev ne hardcode->cookieDefaultValue) {
		$checks[2] = $values[2];
	}
	
	# if the queryDate has been specified, set a check for it
	if ($date ne hardcode->cookieDefaultValue) {
		$checks[4] = $values[4];
	}
	
	# Create a list of each mrs' data
	foreach my $row (@{$dataRows}) {
		# Format the log entry
      		my $log = formatLog($row->[6]);
		
		# mrid col is a url if displayed on a non-mrid details page,
		# or when displayed on the revision details page. It's possible
		# to get to the revision details page without using the mrid to
		# get there, so it is helpful in that case.
		# The URL goes down one level in detail.
		my $mrid = htmlSpace($row->[1]).hardcode->nonBreakingSpace;
		$mrid = "\n".$q->a({
			-href => $this->getSelfURL({
				hardcode->cgiParmQueryOffset => 0,
				hardcode->cgiParmQueryDetail =>
					hardcode->cgiQueryDetailByMRID,
				hardcode->cgiParmQueryMRIDSelect => $row->[1],
				hardcode->cgiParmQuerySortBy =>
					hardcode->cgiQueryMRIDDefaultSort,
				hardcode->cgiParmQuerySortDir =>
					hardcode->cgiQuerySortDefaultDir,
				hardcode->cgiParmQueryDeveloper =>
					hardcode->cookieDefaultValue,
				hardcode->cgiParmQueryDate =>
					hardcode->cookieDefaultValue
			})},
			htmlSpace($row->[1])
		).hardcode->nonBreakingSpace.getTabs(OUT)
			if ! $byMRID || $byRevision;
		
		# devRow is a URL on byMonthDetail if multiple rows,
		# and always a URL on byMonthMrDetail.
		# devRow is a URL that sets the author, but maintains
		# the current url and selection.
		# If we're viewing by author, there's no point in narrowing
		# down by the author, they will all be the same.
		# If we're viewing by file name and it's the mrid detail page,
		# then the developer link does not roll back to displaying
		# the mrdetails page, because there isn't one for that query.
		# Instead, switch over to by author with the author preselected.
		my $devRow = htmlSpace($row->[2]).hardcode->nonBreakingSpace;
		$devRow = "\n".$q->a({
			-href => $this->getSelfURL({
				hardcode->cgiParmQuery =>
					$byFileOrBugzillaorRevisionMRID ?
					hardcode->cgiQueryAuthor :
					$query,
				hardcode->cgiParmQueryMRSelect =>
					$byFileOrBugzillaorRevisionMRID ?
					$row->[2] :
					$mrselect,
				hardcode->cgiParmQueryOffset => 0,
				hardcode->cgiParmQueryDetail =>
					hardcode->cgiQueryDetailByMR,
				hardcode->cgiParmQuerySortBy => $authSortBy,
				hardcode->cgiParmQueryDeveloper => $row->[2],
				hardcode->cgiParmQueryDate =>
					hardcode->cookieDefaultValue
			})},
			htmlSpace($row->[2])
		).hardcode->nonBreakingSpace.getTabs(OUT)
			if  (! $byMRID && $byMonth && ! $checks[2] && $multiple) || $byMRID;
		
		# DateRow is like devRow
		my $dateRow = htmlSpace($c->getFormattedDate($row->[4])).hardcode->nonBreakingSpace;
		$dateRow = "\n".$q->a({
			-href => $this->getSelfURL({
				hardcode->cgiParmQuery =>
					$byFileOrBugzillaorRevisionMRID ?
					hardcode->cgiQueryMonth :
					$query,
				hardcode->cgiParmQueryMRSelect =>
					$byFileOrBugzillaorRevisionMRID ?
					$this->getSQLMonth($row->[4])."-01" :
					$mrselect,
				hardcode->cgiParmQueryOffset => 0,
				hardcode->cgiParmQueryDetail =>
					hardcode->cgiQueryDetailByMR,
				hardcode->cgiParmQuerySortBy => $dateSortBy,
				hardcode->cgiParmQueryDeveloper =>
					hardcode->cookieDefaultValue,
				hardcode->cgiParmQueryDate => $row->[4]
			})},
			htmlSpace($c->getFormattedDate($row->[4]))
		).hardcode->nonBreakingSpace.getTabs(OUT)
			if (! $checks[4] && $multiple) || $byMRID;
		
		my $timeRow = htmlSpace($this->getFormattedTime($row->[5])).hardcode->nonBreakingSpace;
      		
		# Create the row of data
		$rows .= "\n".$q->TR(
			{-class => $classes[$backing]},
			getTabs(SET, 0).$q->td({-valign => 'top'},
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace
			),
			
			# MRID
			"\n".$q->td({-valign => 'top'}, $mrid),
			
			# Author
			"\n".$q->td({-valign => 'top'}, $devRow),
			
			# Files Modified
			"\n".$q->td({-valign => 'top'}, htmlSpace($row->[3]).hardcode->nonBreakingSpace),
			
			# Date
			"\n".$q->td({-valign => 'top'}, $dateRow),
			
			# Time
			"\n".$q->td({-valign => 'top'}, $timeRow),
			
			# Description
			"\n".$q->td({-valign => 'top'}, $q->pre($log))."\n"
		);
		
		# Alternate the classes for each row
		$backing = 1 - $backing;
	}
		
	# Create the header, which allows the user to choose a column to sort by
	for (my $i = 0; $i < scalar(@texts); $i++) {
		# The text, value, and check for this column
		my $head = $texts[$i];
		my $val = $values[$i];
		my $chk = $checks[$i];
		
		# If the query has been narrowed down to one author or one date,
		# Change the title to indicate clicking on it will show all.
		$head = hardcode->termAllDevelopers
			if ! $byAuthor && $i == 2 && $checks[2];
		$head = hardcode->termAllDates
			if $i == 4 && $checks[4];
		
		# Format the column titles
		my $title;
		
		# Is this the author column and we're viewing by author?
		my $noAuthorURL = ! $byMonth && $i eq 2;
		
		# Display a URL for this column if there are multiple rows
		# of results or the query has been narrowed down to one value
		# of this column.
		# Don't make the Author column title a URL if by author,
		# since they will all be the same author anyway.
		if (($multiple || $chk) && ! $noAuthorURL) {
			# Don't use a URL if there is nothing to sort by
			if ($val eq hardcode->cgiQuerySortNone) {
				$title = $q->b(htmlSpace(
					$head,
					$q->font(
						{-color => hardcode->styleMultiLineNBSPColor},
						hardcode->nonBreakingSpace
					).
					$q->br()
				));
				
			} else {
				$title = $q->a({
					-class => hardcode->classQueryHeader,
					-href => $this->getSelfURL({
						hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQuerySortBy =>
							($val eq $chk) ?
							$this->getSort($sortValues) :
							$val,
						hardcode->cgiParmQuerySortDir =>
							$this->getSortDir(
								$sortValues,
								$val,
								$chk
							),
						hardcode->cgiParmQueryDeveloper =>
							($i == 2 && $checks[2]) ?
							hardcode->cookieDefaultValue :
							$dev,
						hardcode->cgiParmQueryDate =>
							($i == 4 && $checks[4]) ?
							hardcode->cookieDefaultValue :
							$date
					})},
					$q->b(htmlSpace("$head".$this->getSortDirString(
						$sortValues,
						$val
					)))
				);
			}
		} else {
			$title = $q->b(htmlSpace($head));
		}
		
		$header .= getTabs(SET, 0).$q->td(
			getTabs(IN).($header ? '' : hardcode->nonBreakingSpace).
			$title.hardcode->nonBreakingSpace.
			getTabs(OUT)
		);
	}
	$header = "\n".$q->TR(
		{-class => hardcode->classQueryHeader},
		$header."\n",
	)."\n";
	
	# Return the header and columns to add to the body.
	return 
		$tableTitle ?
		$q->h3($tableTitle) :
		"",
		$q->table(
			{
				-cellpadding => hardcode->tableQueryPadding,
				-cellspacing => 0,
				-border => hardcode->tableQueryResults
			},
			$header,
			$rows
		)."\n"
}

1;
