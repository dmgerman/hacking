#!/usr/bin/perl -w

package databaseAccess;
use strict;
use DBI;
use hardcode;
use html;
use databasegetinfo;
use databaseList;
use databasebymonth;
use databasebyauthor;
use databasebyfile;
use databasebybugzilla;
use databasesearch;
use databasebymr;
use databasebymrid;
use databasemridstats;
use databasebyfilename;
use databasefilerevtomrid;
use databaserevisiondetails;
use databaserevisiondefs;
use databaserevisiondiffs;
use databasePreferences;

=head1 databaseAccess class : C<databaseAccess.pm>

=head2 Uses: C<DBI.pm>, C<databaseList.pm>, C<databasePreferences.pm>, C<databasebyauthor.pm>, C<databasebybugzilla.pm>, C<databasebyfile.pm>, C<databasebyfilename.pm>, C<databasebymonth.pm>, C<databasebymr.pm>, C<databasebymrid.pm>, C<databasegetinfo.pm>, C<databasesearch.pm>, C<hardcode.pm>, C<html.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

This class provides database access for the application.
A single instance of databaseAccess is enough to manage
the database accesses for the site.

This class is broken up into a set of submodules, each of
which handles one database query.

=cut

=head2 Constructors

=cut

=head3 databaseAccess (cgi : CGI, html : html, cook : cookie)

=cut
sub new {
	my $class = shift;
	
	my $this = {
		'q' => shift,
		'h' => shift,
		'c' => shift
	};
	
	bless $this, $class;
	return $this;
}

=head2 Error Handling functions

=cut

=head3 dbQueryDebugid (id : string, query : string)

Output a debugging message containing a database query.
Used by the query modules when debugging flags are set in
the C<hardcode> module.

Parameters:

=over

=item* id => a string that identifies the query (some functions perform more than one query)

=item* query => the SQL query string

=back

Returns:

=over

=item* none

=back

=cut
sub dbQueryDebug {
	my $this = shift;
	my $h = $this->{'h'};
	my $q = $this->{'q'};
	
	# Get the caller, or the package name if there is no caller
	my $caller;
	if ((caller(1))[3]) {
		# Sometimes, the caller uses en eval block, in which case
		# it is necessary to go back 2 levels on the stack.
		# Otherwise, go back 1 level on the stack.
		if ((caller(1))[3] eq "(eval)") {
			$caller = (caller(2))[3];
		} else {
			$caller = (caller(1))[3];
		}
	} else {
		# Must be called from the package outside of any function
		$caller = (caller(0))[3];
	}

	# Output the message only if the flag is set
	$h->addBody($q->p(
		"$caller(): QUERY ($_[0]) = ",
		$q->br(),
		"'",
		$q->b($_[1]),
		"'"
	)."\n");
}

=head2 Accessor methods to get or set database parameters

=cut

=head3 database ([ db : string ]) => db : string

Get/Set the currently connected database

Parameters:

=over

=item* db => The name of the database to connect to

=back

Returns:

=over

=item* db

=back

=head4 Error 1: hardcode->dbServer doesn't exist

=head4 Error 2: hardcode->dbUsername doesn't exist on server

=head4 Error 3: hardcode->dbPassword is wrong on server

=head4 Error 4: database specified doesn't exist on server

=head4 Note: The result is the name of the database, not its handle

The database handle is maintained internally. It is not intended
for the handle to be accessed outside of the class.

=cut
sub database {
	my $this = shift;
	my $dbname = shift;
	my $h = $this->{'h'};
	my $q = $this->{'q'};
	
	# Connect to the specified database if one was specified
	if ($dbname) {
		# Attempt to connect to the database.
		# Support unix domain sockets if the hostname is empty.
		my $hostname = hardcode->dbServer || "";
		my $host = $hostname && ";host=$hostname";
		eval {
			$this->{'connect'} = DBI->connect(
				"dbi:Pg:dbname=$dbname$host",
				hardcode->dbUsername,
				hardcode->dbPassword
			) or die;
			1;
		} or $h->addBody($q->p($q->b($DBI::errstr)));

		# If the database opened successfully, store its name
		$this->{'currentDatabase'} = $dbname;
	}
	
	# Return the name of the current database
	return $this->{'currentDatabase'};
}

=head2 Destructor methods

=cut

=head3 disconnect ()

Disconnect from whatever database is connected to.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=head4 Note: If no database is connected to, it is not an error to call this method

=cut
sub disconnect {
	my $this = shift;
	
	if ($this->{'connect'}) {
		$this->{'connect'}->disconnect();
		$this->{'connect'} = 0;
	}
}

=head2 Generic Query function

=cut

=head3 databaseQuery (parms : (key => value)) => results : [more : bool, rows : [scalar]]

=head3 databaseQuery (parms : {key => value}) => results : [more : bool, rows : [scalar]]

Execute a specific query in a generic way by using the
provided data and code references to make decisions.

The result returned is a ref to an array, each element of which
is a ref to an array of one row of data, each element of which
is generlly a scalar. In some cases, the data for a row may contain
array refs.

The more flag indicates that there are more results after the ones being returned.

Parameters:

=over

=item* [ -sortDefault ] => default sorting value : string

=item* [ -sortValues ] => sorting values : [string]

=item* [ -getSortField => code(sortfield : string, sortdir : string) ] => sortfield : string

=item* -getQuery => code(parms : (key => value)) => query : string

=item* -queryDebugFlag => debugging flag for query : bool

=item* -queryDebugMsg => debugging message : string

=item* [ -getRow => code(parms : (key => value, -row => [string])) ] => row : [scalar]

=item* [ -getSortedResults => code(parms : (key => value, -results => [[scalar]])) ] => [[scalar]]

=item* [ -getManualLimitFlag => code(parms : (key => value)) ] => flag : bool

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rows of results

=back

All code parameters are optional.

The code executed by C<-getSortField> determines what sort field to use
if the value returned by C<html-E<gt>getSort()> is not necessarily the right
value to use. If the code returns an empty string, then no sorting
is performed. If the code is undefined, then C<html-E<gt>getSort()> is used.

The code executed by C<-getRow()> will always receive an array ref of strings,
but it may return an array ref that contains strings, array refs, or both.
If the code returns a false value for the array ref, then the row is rejected.
If the code is undefined, the rows returned by the SQL query are accepted
as is.

The code executed by C<-getSortedResults()> has to be able to sort whatever is returned
by C<-getRow>, generally an array ref of string array refs. If the code is undefined,
the rows returned by C<-getRow()> are accepted as is.

Note that when the code for C<-getSortedResults()> is executed, the results passed
do NOT have the line numbers column added, that is performed immediately after sorting.

There are a number of common parameters passed to all code functions, indicated above
by the C<key =E<gt> value> pairs. The common parameters are:

=over

=item* -query => the type of query (by month, by author, etc) : string

=item* -detail => the level of detail to provide (by query, by filename, etc) : string

=item* -sort => the field to sort by, as determined by the C<-sortDefault> and C<-getSortField> parameters : string

=item* -sortDir => the direction to sort in, as determined by the C<html-E<gt>getSortDir> method

=item* -developers => the list of developers in the preferencers as an SQL string : string

=item* -dateRange => the range of dates in the preferences as an SQL string : string

=item* -selectedDay => a single selected day : date

=item* -selectedAuthor => a single selected author : string

=item* -offset => the SQL offset to use : int

=item* -limit => the SQL limit to use : int

=item* -mrselect => the selected mr value (a month or a developer name) : string

=item* -mridselect => the selected mrid : string

=item* -fileselect => the selected filename : string

=item* -revisionselect => the selected revision id : string

=item* -searchWithAll => a string of words to search for all of : string

=item* -searchWithExact => an exact phrase to search for : string

=item* -searchWithAtLeast => a string of words to search for at least one of : string

=item* -searchWithout => a string of words to not search for : string

This method assumes there is already a valid database connection, and that the
database connection will remain the same throughout the query. If the database
connection changes throughout the query, then the caller will have to save the
database name and connection handle.

=back

=cut
sub databaseQuery {
	my $this = shift;
	
	# Objects needed
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	my $h = $this->{'h'};
	
	# Data provided by the caller
	my %data;
	if (ref($_[0]) eq "HASH") {
		%data = %{$_[0]};
	} else {
		%data = @_;
	}
	
	# The sorting values to check against
	my $sortValues = [
		$data{-sortDefault}, 
		exists $data{-sortValues} ? @{$data{-sortValues}} : ()
	];
	
	# The sort field and direction
	my $sort = "";
	my $sortDir = "";
	if ($sortValues->[0]) {
		$sortDir = $h->getSortDir($sortValues);
		$sort =
			$data{-getSortField} || 
			sub {return shift};
		$sort = &$sort($h->getSort($sortValues), $sortDir);
	}

	# Set the author and date criteria from the preferences
	my @dev = $c->developers();
	my $devCriteria = $dev[0] eq hardcode->cookieDefaultValue ?
		'TRUE' :
		"author in ('".(join "', '", @dev)."')";

	my $dateCriteria = $c->startMonth() ? 
		"mrs2.daterev >= '".$c->getSQLStartDate().
		"' AND mrs2.daterev <= '".$c->getSQLEndDate()."'"
		: 'TRUE';
	
	# The selected day and developer, independent of the preferences
	my $selectedDay = $h->getDate();
	$selectedDay = ''
		if $selectedDay eq hardcode->cookieDefaultValue;
	my $selectedAuthor = $h->getDeveloper();
	$selectedAuthor = ''
		if $selectedAuthor eq hardcode->cookieDefaultValue;
	
	# The offset and limit to use in the SQL query, and for
	# manually implementing offset and limit.
	# The SQLlimit is incremented by 1 so we can accurately
	# determine whether or not there is a 'next' page of data
	# without any extra query.
	# The other limit is not incremented because it is the one used
	# for manual limits.
	my $limit = $c->maximumRows();
	my $offset = $h->getOffset();
	my $SQLlimit = $sort ? $limit + 1 : 'ALL';
	my $SQLoffset = $sort ? $offset * $limit : 0;
	
	# The parameters to pass to the remaining functions
	my @names = hardcode->searchPhraseNames;
	my %parms = (
		-query => $h->getQuery(),
		-detail => $h->getDetail(),
		-sort => $sort,
		-sortDir => $sortDir,
		-developers => $devCriteria,
		-dateRange => $dateCriteria,
		-selectedDay => $selectedDay,
		-selectedAuthor => $selectedAuthor,
		-offset => $SQLoffset,
		-limit => $SQLlimit,
		-mrselect => $h->getMRSelect(),
		-mridselect => $h->getMRIDSelect(),
		-fileselect => $h->getFileSelect(),
		-revisionselect => $h->getRevisionSelect(),
		-searchWithAll => $q->param(shift @names) || "",
		-searchWithExact => $q->param(shift @names) || "",
		-searchWithAtLeast => $q->param(shift @names) || "",
		-searchWithout => $q->param(shift @names) || ""
	);
	
	# Get the query to execute.
	my $query = $data{-getQuery};
	$query = &$query(%parms);
	
	# Display a debugging message if requested	
	$this->dbQueryDebug(
		$data{-queryDebugMsg},
		$query
	) if $data{-queryDebugFlag};
	
	# Assume a database has already been connected to
	my $dbh = $this->{'connect'};
	my $results = [];
	
	if ($dbh && $query) {
		# Execute the query
		my $queryh = $dbh->prepare($query);
		$queryh->execute();
		
		# Get the function for massaging the rows
		my $getRow =
			$data{-getRow} || 
			sub {
				my %parms = @_; 
				return $parms{-row}
			};
		
		# Build the results
		while(my @row = $queryh->fetchrow_array()) {
			# Massage the row
			my $rowData = &$getRow(%parms, -row => \@row);
			
			# Include the row if it is still defined
			push @{$results}, $rowData if $rowData;
		}
		
		# Get the sorting function
		my $getSortRes =
			$data{-getSortedResults} || 
			sub {
				my %parms = @_; 
				return $parms{-results}
			};
			
		# Sort the results with perl code
		$results = &$getSortRes(%parms, -results => $results);
		
		# Are limits implemented manually?
		my $manual = 
			$data{-getManualLimitFlag} || 
			sub {return 0};
		$manual = &$manual(%parms);
		
		# Number the results after sorting
		my $rowCount = $manual ? 1 : $offset * $limit + 1;
		map {unshift @{$_}, $rowCount++; $_} @{$results};
		
		# Manually slice out the offset and limit from the results
		# if necessary
		if ($manual) {
			# Don't let the ending index go beyond the
			# array size, or perl will fill in the
			# extras with blanks.
			# However, there is one extra row in the results to
			# determine if there are more results or not, so do
			# not subtract one from the end.
			my $begin = $offset * $limit;
			my $end = $begin + $limit;
			$end = 
				$end >= @{$results} ? 
				$end = @{$results} - 1 : 
				$end;
			@{$results} = @{$results}[$begin .. $end];
		}
		
		# Prepend a flag to indicate if there are more results.
		# If the flag is true, then kill the extra row at the end,
		# otherwise return all rows of data. Since manual sorting
		# needs all rows of data to work, we have to do this at
		# the end.
		my $moreResults = @{$results} > $limit;
		unshift @{$results}, $moreResults;
		$moreResults && (@{$results} = @{$results}[0..$limit]);
	}
	
	# Trim leading and trailing whitespace from the results
	trim2($results);
	
	# Return the results as [[scalar]]
	return $results;
}

# Return true
1;
