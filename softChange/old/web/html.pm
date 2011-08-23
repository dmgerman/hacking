#!/usr/bin/perl -w

package html;
use strict;
use CGI;
use hardcode;
use htmlutility;
use htmlforms;
use htmlbody;
use htmlurl;
use htmltop;
use htmldblist;
use htmlbymonth;
use htmlbyauthor;
use htmlbyfile;
use htmlbybugzilla;
use htmlsearch;
use htmlmrdetail;
use htmlbyfilename;
use htmlmriddetail;
use htmlmridstats;
use htmlrevisiondetails;
use htmlrevisiondefs;
use htmlrevisiondiffs;
use htmlpreferences;
use cookie;

=head1 html class : C<html.pm>

=head2 Requires: C<none>

=head2 Uses: C<CGI.pm>, C<cookie.pm>, C<hardcode.pm>, C<htmlbody.pm>, C<htmlbyauthor.pm>, C<htmlbybugzilla.pm>, C<htmlbyfile.pm>, C<htmlbyfilename.pm>, C<htmlbymonth.pm>, C<htmldblist.pm>, C<htmlforms.pm>, C<htmlmrdetail.pm>, C<htmlmriddetail.pm>, C<htmlpreferences.pm>, C<htmlsearch.pm>, C<htmltop.pm>, C<htmlurl.pm>, C<htmlutility.pm>

=head2 Pragmas: C<strict>

This class writes out nice html code for the application.
The html code is accumulated in the object until the
processing is finished, then it is all written out at
once to the browser.

When the code is finished accumulating html, a call to
C<writeHTML()> will write out all the header and body information
accumulated so far.

Cookies are automatically managed by the C<writeHTML()> function,
by getting the cookie strings and writing them all to the
header.

The state information that needs to be managed from page
to page is divided into two types of information:

=over

=item* Information that conveys the current state (eg, the
current database and query type).

=item* Information that is useful for a short-term operation
(eg, setting the preferences)

=back

The current state is basically composed of long-term data
that needs to be carried from page to page regardless of
the operation being performed. The values will change over time,
but the set of data remains fixed in size.

The current state is information that is not appropriate
for a cookie to control, such as which column to sort
output by.

Short term state information only exists for a short time
(eg one or two page loads), then it is gone. An example
would be the information for setting the preferences. Once
the preferences are set, the information is no longer needed
until the next time preferences are set.

Some of these get methods require an array called goodValues to check against,
for security purposes. The array must be passed by reference, and the first element
of the array is the default value to take on if the parameter is not within the list.
This default can be a copy of another element.

=cut

=head2 Constructors

=cut

=head3 html (cgi : CGI, cook : cookie)

This method queries the CGI object for long term state information
and stores it in a hash table.

Parameters:

=over

=item* cgi => CGI object

=item* cook => cookie object

=back

=cut
sub new {
	my $class = shift;
	my $q = shift;
	my $c = shift;
	
	# When there is no database selected,the operation is
	# to list databases. When a database is selected, the
	# operation determines what query to perform on it.
	# The default operation on a selected database is to
	# list MRs by date (really by month).
	# Set all params to default if not provided.
	
	# Store the supported tables as a hash ref
	my $tables = {};
	my @tableNames = $q->param(hardcode->cgiParmSupportedTables);
	if (@tableNames > 0) {
		map {$tables->{$_} = 1} @tableNames;
	}
	
	# Create the table for the new object.
	# There are two subtables, state and get.
	# State holds the values of cgi parameters,
	# Get holds the functions of cgi parameters.
	# Only the functions in the get table should directly
	# access the state table.
	my $this = {
		'q' => $q,
		'c' => $c,
		'title' => '',
		'icon' => '',
		'state' => {
			hardcode->cgiParmDB =>
				$q->param(hardcode->cgiParmDB) || "",
			hardcode->cgiParmQuery =>
				$q->param(hardcode->cgiParmQuery) || hardcode->cgiQueryList,
			hardcode->cgiParmQueryOffset =>
				$q->param(hardcode->cgiParmQueryOffset) || 0,
			hardcode->cgiParmQueryDetail =>
				$q->param(hardcode->cgiParmQueryDetail) || hardcode->cgiQueryDetailDefault,
			hardcode->cgiParmQueryMRSelect =>
				$q->param(hardcode->cgiParmQueryMRSelect) || hardcode->cookieDefaultValue,
			hardcode->cgiParmQueryMRIDSelect =>
				$q->param(hardcode->cgiParmQueryMRIDSelect) || hardcode->cookieDefaultValue,
			hardcode->cgiParmQueryFileSelect =>
				$q->param(hardcode->cgiParmQueryFileSelect) || hardcode->cookieDefaultValue,
			hardcode->cgiParmQueryRevisionSelect =>
				$q->param(hardcode->cgiParmQueryRevisionSelect) || hardcode->cookieDefaultValue,
			hardcode->cgiParmQuerySortBy =>
				$q->param(hardcode->cgiParmQuerySortBy) || hardcode->cgiQueryMonthDefaultSort,
			hardcode->cgiParmQuerySortDir =>
				$q->param(hardcode->cgiParmQuerySortDir) || hardcode->cgiQuerySortDefaultDir,
			hardcode->cgiParmQueryDeveloper =>
				$q->param(hardcode->cgiParmQueryDeveloper) || hardcode->cookieDefaultValue,
			hardcode->cgiParmQueryDate =>
				$q->param(hardcode->cgiParmQueryDate) || hardcode->cookieDefaultValue,
			hardcode->cgiParmBugzillaURL =>
				$q->param(hardcode->cgiParmBugzillaURL) || hardcode->cookieDefaultValue,
			hardcode->cgiParmSupportedTables =>
				$tables
		},
		'get' => {
			hardcode->cgiParmDB => \&getDatabase,
			hardcode->cgiParmQuery => \&getQuery,
			hardcode->cgiParmQueryOffset => \&getOffset,
			hardcode->cgiParmQueryDetail => \&getDetail,
			hardcode->cgiParmQueryMRSelect => \&getMRSelect,
			hardcode->cgiParmQueryMRIDSelect => \&getMRIDSelect,
			hardcode->cgiParmQueryFileSelect => \&getFileSelect,
			hardcode->cgiParmQueryRevisionSelect => \&getRevisionSelect,
			hardcode->cgiParmQuerySortBy => \&getSort,
			hardcode->cgiParmQuerySortDir => \&getSortDir,
			hardcode->cgiParmQueryDeveloper => \&getDeveloper,
			hardcode->cgiParmQueryDate => \&getDate,
			hardcode->cgiParmBugzillaURL => \&bugzillaURL,
			hardcode->cgiParmSupportedTables => \&supportedTables
		}
	};
	
	map {
		$this->{'state'}->{$_} = $q->param($_) || '';
		my $subname = "get$_";
		$this->{'get'}->{$_} = \&$subname;
	} (hardcode->searchPhraseNames);
	
	bless $this, $class;
	
	return $this;
}

=head2 Set methods to set state properties

=cut

=head3 setMRIDSelect (mrid : string)

Set the selected MRID

Parameters:

=over

=item* mrid => the mrid to select

=back

Returns:

=over

=item* none

=back

=cut
sub setMRIDSelect {
	my $this = shift;
	my $mrid = shift;
	
	$this->{'state'}->{hardcode->cgiParmQueryMRIDSelect} = $mrid;
}

=head3 setDetail (detail : string)

Set the detail level for the query

Parameters:

=over

=item* detail => the detail level

=back

Returns:

=over

=item* none

=back

=cut
sub setDetail {
	my $this = shift;
	my $detail = shift;
	
	$this->{'state'}->{hardcode->cgiParmQueryDetail} = $detail;
}

=head2 Get methods to get state properties

=cut

=head3 getDatabase () => name : string

Get the current database

Parameters:

=over

=item* none

=back

Returns:

=over

=item* database name

=back

=cut
sub getDatabase {
	my $this = shift;
	
	return $this->{'state'}->{hardcode->cgiParmDB};
}

=head3 getQuery () => qtype : string

Get the current query type

Parameters:

=over

=item* none

=back

Returns:

=over

=item* the type of query to perform

=back

=cut
sub getQuery {
	my $this = shift;
	
	# Test against known good values for security purposes.
	my $result = $this->{'state'}->{hardcode->cgiParmQuery};
	$result =~ s/://g;
	my $str = join ':', (hardcode->cgiQueryAll);
	$result = hardcode->cgiQueryList if (index $str, $result) == -1;
	
	return $result;
}


=head3 getOffset () => offset : int

Get the current offset

Parameters:

=over

=item* none

=back

Returns:

=over

=item* offset => the current offset

=back

=cut
sub getOffset {
	my $this = shift;
	
	return $this->{'state'}->{hardcode->cgiParmQueryOffset};
}

=head3 getDetail () => detail : string

Get the current detail level

Parameters:

=over

=item* none

=back

Returns:

=over

=item* detail => the level of detail to provide

=back

=cut
sub getDetail {
	my $this = shift;
	
	# Test against known good values for security purposes.
	my $result = $this->{'state'}->{hardcode->cgiParmQueryDetail};
	$result =~ s/://g;
	my $str = join ':', (hardcode::getCGIQueryDetailAll());
	$result = hardcode->cgiQueryDetailDefault if (index $str, $result) == -1;
	
	return $result;
}

=head3 getSort (goodValues : [string]) => sort : string

Get the current sort field

Parameters:

=over

=item* 

=back

Returns:

=over

=item* sort => the field to sort by

=back

=cut
sub getSort {
	my $this = shift;
	my $sortValues = shift;
	
	my $result = $this->{'state'}->{hardcode->cgiParmQuerySortBy};
	
	if (ref($sortValues) eq "ARRAY") {
		# Test against known good values for security purposes.
		$result =~ s/://g;
		my $str = join ':', @{$sortValues};
		$result = $sortValues->[0] if (index $str, $result) == -1;
	}
	
	return $result;
}

=head3 getSortDir () => sortDir : string

=head3 getSortDir (goodValues : [string], sortBy : string, [ check : string ]) => sortDir : string

Get the current sort direction, ascending or descending.

The second form compares the given column to sort by against the current
sorting column. If they match, then the opposite sorting direction is
returned, otherwise the default sorting direction is returned.

If sortBy matches check, then the default sort direction is used, even
if sortBy is the current sorting column. Essentially, check is a mechanism
for specifying an "unless" qualifier to the above mechanism. This is
useful when you have a column that is the current sorting column, but
it needs to do some other operation rather than change sorting direction.

For example, the mr details page may be narrowed down to a single author
and the author may also be the current sort column. If you click on the author
title, the action is to show all authors. After showing all authors, then
action becomes changing the sort order.

This method is useful for making the column headers switch sort orders,
where the sort order switch should only occur if the current column is
clicked on again. Any column header other than the column
being sorted on should use the default order, that way when changing
sorting columns, the default sort order is used.

Parameters:

=over

=item* goodValues => acceptable sorting values

=item* sortBy => the column to compare against the current sorting column

=item* check => = sortBy if this column is an exception to the rule

=back

Returns:

=over

=item* sortDir => the current sort direction

=back

=cut
sub getSortDir {
	my $this = shift;
	my $sortValues = shift;
	my $sortBy = shift;
	my $check = shift;
	
	my $sort = "";
	if (ref($sortValues) eq "ARRAY") {
		$sort = $this->getSort($sortValues);
	}
	
	# The current sorting direction
	my $result = $this->{'state'}->{hardcode->cgiParmQuerySortDir};
	$result = hardcode->cgiQuerySortDefaultDir
		if $result ne hardcode->cgiQuerySortDirAsc &&
		$result ne hardcode->cgiQuerySortDirDesc;
	
	if ($sortBy) {
		# Check the provided column, keep the sorting direction if it matches
		if (! $check) {
			# Change the sorting direction
			if ($sortBy eq $sort) {
				# The provided column is the current column, switch direction
				if ($result eq hardcode->cgiQuerySortDirAsc) {
					$result = hardcode->cgiQuerySortDirDesc;
				} else {
					$result = hardcode->cgiQuerySortDirAsc;
				}
			} else {
				# The provided column is not the current column, default direction
				$result = hardcode->cgiQuerySortDefaultDir;
			}
		}
	}
				
	
	return $result;
}

=head3 getMRSelect () => mrselect : string

Get the value to select MRs by (a month or an author).

Parameters:

=over

=item* none

=back

Returns:

=over

=item* mrselect => the selected month or author

=back

=cut
sub getMRSelect {
	my $this = shift;
	
	return $this->{'state'}->{hardcode->cgiParmQueryMRSelect};
}

=head3 getMRIDSelect () => mrselect : string

Get the ID to select MR IDs by.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* mridselect => the selected MR ID

=back

=cut
sub getMRIDSelect {
	my $this = shift;
	
	return $this->{'state'}->{hardcode->cgiParmQueryMRIDSelect};
}

=head3 getFileSelect () => fileselect : string

Get the file to select files by.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* fileselect => the selected file

=back

=cut
sub getFileSelect {
	my $this = shift;
	
	return $this->{'state'}->{hardcode->cgiParmQueryFileSelect};
}

=head3 getRevisionSelect () => revselect : string

Get the revision to select.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* revselect => the selected revision

=back

=cut
sub getRevisionSelect {
	my $this = shift;
	
	return $this->{'state'}->{hardcode->cgiParmQueryRevisionSelect};
}

=head3 getDeveloper () => dev : string

Get the current selected developer. This setting is used to override the list
of developers in the cookie settings with a single developer. If
this developer is the default value, it means that the cookie settings
apply instead.

If the cookie settings are set to a non-default value and the selected developer
is not in the list, then this function returns the default value to solve
the conflict by saying that the cookie settings apply. It is effectively as
is there was no selected developer.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* dev => the selected developer or default value

=back

=cut
sub getDeveloper {
	my $this = shift;
	my $c = $this->{'c'};
	
	my $dev = $this->{'state'}->{hardcode->cgiParmQueryDeveloper};
	$dev =~ s/://g;
	my $devList = join ':', $c->developers();
	
	# If the selected developer doesn't match the cookie developer list,
	# then return the default value to indicate the cookie list applies.
	$dev = hardcode->cookieDefaultValue
		if $devList ne hardcode->cookieDefaultValue &&
		(index $devList, $dev) == -1;
		
	return $dev;
}

=head3 getDate () => date : string

Get the current selected date. This setting is used to override the
date range in the cookie settings with a single date. If
this date is the default value, it means that the cookie settings
apply instead.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* date => the selected date

=back

=cut
sub getDate {
	my $this = shift;
	my $c = $this->{'c'};
	
	my $date = $this->{'state'}->{hardcode->cgiParmQueryDate};
	
	# Make sure it really is a date
	$date = hardcode->cookieDefaultValue
		if $date !~ /^\d\d\d\d-\d\d-\d\d$/;
	
	# Make sure it is within the range of the preferences
	if ($date ne hardcode->cookieDefaultValue) {
		$date = hardcode->cookieDefaultValue
			if $c->startMonth() && 
			($date lt $c->getSQLStartDate() ||
			$date gt $c->getSQLEndDate());
	}
		
	return $date;
}

=head3 getsearchWithAll () => all : string

Get the current set of search with all words.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* all => the set of search with all words

=back

=cut
sub getsearchWithAll {
	my $this = shift;
	
	return $this->{'state'}->{'searchWithAll'};
}

=head3 getsearchWithExact () => exact : string

Get the current search with exact phrase.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* exact => exact phrase to search for

=back

=cut
sub getsearchWithExact {
	my $this = shift;
	
	return $this->{'state'}->{'searchWithExact'};
}

=head3 getsearchWithAtLeast () => least : string

Get the current set of search with at least one of words.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* least => the set of search with at least one of words

=back

=cut
sub getsearchWithAtLeast {
	my $this = shift;
	
	return $this->{'state'}->{'searchWithAtLeast'};
}

=head3 getsearchWithout () => without : string

Get the current set of search without words.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* without => the set of search without words

=back

=cut
sub getsearchWithout {
	my $this = shift;
	
	return $this->{'state'}->{'searchWithout'};
}

=head2 Accessor methods to get or set data

=cut

=head3 title ([ text : string ]) => text : string

Get/Set starting month

Parameters:

=over

=item* text => The title text

=back

Returns:

=over

=item* text

=back

=cut
sub title {
	my $this = shift;
	my $title = shift;
	
	$this->{'title'} = $title if $title;
	
	return $this->{'title'};
}

=head3 icon ([ loc : string ]) => loc : string

Get/Set icon location

Parameters:

=over

=item* loc => The icon URL

=back

Returns:

=over

=item* loc

=back

=cut
sub icon {
	my $this = shift;
	my $icon = shift;
	
	$this->{'icon'} = $icon if $icon;
	
	return $this->{'icon'};
}

=head3 bugzillaURL ([ url : string ]) => bugurl : string

Get/Set the bugzilla URL

Parameters:

=over

=item* url => the url to use for bugzilla

=back

Returns:

=over

=item* bugurl => The bugzilla base url, including parameter and equals sign

=back

=cut
sub bugzillaURL {
	my $this = shift;
	my $url = shift;

	$this->{'state'}->{hardcode->cgiParmBugzillaURL} = $url if $url;

	return $this->{'state'}->{hardcode->cgiParmBugzillaURL};
}

=head3 supportedTables ([ tables : {tablename => 1} ]) => tables : {tablename => 1}

Get/Set the currently supported set of tables as a hash ref, where they
keys are the names of tables that are supported.

Returns an empty hash if no database has been connected to.

Parameters:

=over

=item* tables => a hash ref of table names supported by the current project

=back

Returns:

=over

=item* tables => a hash ref of supported table names

=back

=cut
sub supportedTables {
	my $this = shift;
	my $tables = shift;
	
	$this->{'state'}->{hardcode->cgiParmSupportedTables} = $tables if $tables;
	
	return $this->{'state'}->{hardcode->cgiParmSupportedTables};
}

=head2 Generic HTML generation function

=cut

=head3 generateHTML (parms : (key => value)) => table : string

Generate the HTML table for a specific page of data in a generic way,
by using the provided data and code references to make decisions.
The result is added to the body of the web page to be delivered.

Parameters:

=over

=item* -results : [[scalar]] => the results to be displayed, as returned by C<databaseAccess-E<gt>databaseQuery()>, without the boolean flag

=item* [ -tableTitle : string ] => the title to use for the table

=item* [ -tableOuterTitle : string ] => the title row to place before the table title

=item* [ -tableOuterSpan : int ] => the number of columns the outer title should span

=item* -columnTexts : [string] => the text of each column to display

=item* [ -columnClass : string ] => the class of the column header instead of the default

=item* -sortValues : [string] => the SQL field to sort by for each column

=item* -sortDefault : string => the default SQL field to sort by for the page

=item* [ -multipleRows : code(row : [scalar]) => isMultiple : bool ] => test to see if there are multiple results, the default test is more than 1 row

=item* [ -rowClasses : [string] ] => the HTML stylesheet classes to cycle through for the rows

=item* [ -getRowClass : code(row : [scalar]) => rowClass : string ] => the HTML class to use for the row instead of cycling through the -rowClasses parameter

=item* [ -getRow : code(q : CGI, c : cookie, row : [scalar]) => row : string ] => convert a row of scalars into HTML

=item * [ -columnClass : string ] => the HTML stylesheet class to use for the columns

=back

Returns:

=over

=item* table => the html table to add to the body

=back

=cut
sub generateHTML {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	my %parms = @_;
	
	my $results = $parms{-results};
		
	my $columnClass = $parms{-columnClass} || hardcode->classQueryHeader;
	
	my $tableOuterSpan =
		exists $parms{-tableOuterSpan} ?
		$parms{-tableOuterSpan} :
		1;
		
	my $tableOuterTitle =
		exists $parms{-tableOuterTitle} ?
		$q->TR(
			{-class => $columnClass},
			$q->td(
				{-colspan => $tableOuterSpan,
				-align => "center"},
				$q->b($parms{-tableOuterTitle})
			)
		) :
		"";
		
	my $tableTitle = 
		exists $parms{-tableTitle} ? 
		$q->h3($parms{-tableTitle}) : 
		"";
		
	my @columnTexts = @{$parms{-columnTexts}};
	
	my $doSort = exists $parms{-sortValues};
	my @sortValues = $doSort ?
		@{$parms{-sortValues}} :
		("");
		
	my $sortCheck = [$parms{-sortDefault}, @sortValues];
	
	my @rowClasses = 
		exists $parms{-rowClasses} ? 
		@{$parms{-rowClasses}} : 
		hardcode->classQueryRows;
	
	my @backing;
	my $getRowClass = $parms{-getRowClass} ||
		sub {
			# Reload the set of row classes if they are exhausted
			@backing = @rowClasses if @backing == 0;
			
			# Return the next row class
			return shift @backing;
		};
	
	my $getRow = $parms{-getRow} ||
		sub {
			my ($q, $c, $row) = @_;
			
			my $first = 1;
			return
				map {
					my $begin = 
						$first ? 
						($first = 0, hardcode->nonBreakingSpace) : 
						'';
						
					$begin.
					htmlSpace($_).
					hardcode->nonBreakingSpace;
				} @{$row};
		};
	
	# The row of column headers
	my $columnHeaders;
	
	# The rows of data
	my $dataRows = "";
	
	# Is there more than one row of results?
	my $multiple = $parms{-multipleRows} ||
		sub {
			my $row = shift;
			
			return @{$row} > 1;
		};
	$multiple = &$multiple($results);
	
	# Create the column headers
	map {
		# The title for this column
		my $title;
		if ($multiple) {
			# Don't use a URL if there is nothing to sort by
			if (! $doSort || $sortValues[0] eq hardcode->cgiQuerySortNone) {
				$title = $q->b(htmlSpace(
					"$_",
					($doSort ? 
					$q->font(
						{-color => hardcode->styleMultiLineNBSPColor},
						hardcode->nonBreakingSpace
					).
					$q->br() : 
					"&nbsp;")
				));
				
				shift @sortValues;
				
			} else {
				$title = $q->a({
					-class => hardcode->classQueryHeader,
					-href => $this->getSelfURL({
						hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQuerySortBy =>
							$sortValues[0],
						hardcode->cgiParmQuerySortDir =>
							$this->getSortDir(
								$sortCheck,
								$sortValues[0]
							)
					})},
					$q->b(htmlSpace(
						$_.
						$this->getSortDirString(
							$sortCheck, 
							shift @sortValues
						)
					))
				);
			}
		} else {
			$title = $q->b(htmlSpace($_));
		}
		
		$columnHeaders .= getTabs(SET, 0).$q->td(
			getTabs(IN).
			($columnHeaders ? '' : hardcode->nonBreakingSpace).
			$title.
			hardcode->nonBreakingSpace.
			getTabs(OUT)
		);
	} @columnTexts;
	
	# Make the header a table row and apply a stylesheet class.
	# Add the outer table title first if necessary.
	$columnHeaders = "\n".$tableOuterTitle."\n".$q->TR(
		{-class => $columnClass},
		$columnHeaders."\n",
	)."\n";
	
	# Create the rows of data
	map {
		
		# Add the columns of data to the string of rows
		$dataRows .= $q->TR(
			{-class => &$getRowClass($_)},
			(map {getTabs(SET, 1).$q->td({-valign => 'top'}, $_)} &$getRow($q, $c, $_)),
			getTabs(OUT)
		).getTabs();
	} @{$results};
	
	# Return the column headers and rows
	return
		$tableTitle.
		$q->table(
			{
				-cellpadding => hardcode->tableQueryPadding,
				-cellspacing => 0,
				-border => hardcode->tableQueryResults
			},
			$columnHeaders.
			$dataRows
		)."\n";
}

# Return true so this file can be required
1;
