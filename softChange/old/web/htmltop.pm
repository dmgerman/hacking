#!/usr/bin/perl -w

package htmltop;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'mainHeader',
	'mainQuery',
	'mainMRID'
);

=head1 html class : C<htmltop.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 Methods for creating the top portion of all query pages

=cut
	
=head3 mainHeader ()

Create the initial header values except the cookies.
There are different types of headers, one for the
initial list of databases, and one for queries.
This function handles both. If the database name is false,
then the initial list type of header is
chosen, otherwise the query type is chosen.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub mainHeader {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	my $icon = $this->{'icon'};
	my $dbname = $this->getDatabase();
	my $query = $this->getQuery();
	
	my $queryPage = $dbname && $query ne hardcode->cgiQueryList;
	
	# There's always the set of languages to choose from
	my $langChoices = "";
	my $langTable = "";
	my @languages =
		sort {
			! $a->[0] ?
			-1 :
			! $b->[0] ?
			1 :
			$a->[0] cmp $b->[0];
		} map {
			[$_, hardcode->termLanguages->{$_}]
		} (keys %{hardcode->termLanguages});
	
	# Only provide the language choices if there is more than 1.
	# Counting the default choice, that means more than 2.
	if (keys %{hardcode->termLanguages} > 2) {
		map {
			$langChoices .=
				getTabs(SET, 1).$q->td($q->a({
					-href => $this->getLocaleURL($_->[0]),
					},
					$_->[1]
				).hardcode->nonBreakingSpace).
				getTabs(OUT);
		} @languages;
	} else {
		# If there is only one language choice, then show it
		# as straight text.
		$langChoices =
			getTabs(SET, 1).$q->td(
				$languages[1]->[1]
			);
	}
	
	# There's always links to the installed documentation	
	my $userDoc = 
		hardcode->withUserManual ?
		getTabs(SET, 1).$q->td($q->a(
			{-href => hardcode->userManualURL},
			hardcode->termUserManual
		).hardcode->nonBreakingSpace) :
		"";
	
	my $progDoc = 
		hardcode->withProgManual ?
		getTabs(SET, 1).$q->td($q->a(
			{-href => hardcode->progManualURL},
			hardcode->termProgManual
		).hardcode->nonBreakingSpace) :
		"";
	
	my $podDoc = 
		hardcode->withPOD ?
		getTabs(SET, 1).$q->td($q->a(
			{-href => hardcode->podURL},
			hardcode->termPOD
		)) :
		"";

	# Put the languages and documentation into a table
	$langTable =
		$q->br().
		getTabs(SET, 0).$q->table({
			-border => 0,
			-cellpadding => 0,
			-cellspacing => 0
			},
			getTabs().$q->TR($langChoices),
			($userDoc || $progDoc || $podDoc) ?
			getTabs().$q->TR(
				$userDoc,
				$progDoc,
				$podDoc
			) :
			""
		).getTabs().
		$q->br();
		
	# Draw the logo, the line, the languages, and the documentations
	$this->addBody(
		$q->img({-src => hardcode->logoIcon}),
		$q->br()."\n",
		$q->img({
			-src => hardcode->lineIcon,
			-width => hardcode->logoLineWidth,
			-height => hardcode->logoLineHeight,
		})."\n",
		$langTable
	);
		
	# There's always the table containing the preferences,
	# but it has different stuff depending on whether it is
	# the initial page or not.
	my $prefsTable =
		getTabs(SET, 4).$q->table(
			{
				-border => hardcode->tablePrefsBorder,
				-cellpadding => 0,
				-cellspacing => 0
			},
			getTabs().$q->TR(
				getTabs(IN).$q->td(
					{-valign => "top", -class => hardcode->classPrefs},
					getTabs(IN).$q->a({
						-href => $this->getURL(
							hardcode->prefsURL, {
							hardcode->cgiParmPrefs =>
								hardcode->cgiPrefsTrue,
							hardcode->cgiParmReferer =>
								hardcode->mainURL
						})},
						hardcode->prefsTitle
					).
					hardcode->nonBreakingSpace.getTabs(OUT)
				),
				$queryPage ?
				getTabs().$q->td(
					{-valign => "top", -class => hardcode->classPrefs},
					getTabs(IN).htmlSpace(
						hardcode->textTimeRange.
						hardcode->nonBreakingSpace.
						$q->b("'".$c->getDateRange()."'")
					).hardcode->nonBreakingSpace.getTabs(OUT)
				) :
				"",
				$queryPage ?
				getTabs().$q->td(
					{-valign => "top", -class => hardcode->classPrefs},
					getTabs(IN).htmlSpace(
						hardcode->textAuthorList.
						hardcode->nonBreakingSpace.
						$q->b("'".
							(join ',', $c->developers())
						."'").
						hardcode->nonBreakingSpace
					).getTabs(OUT)
				) :
				"",
				getTabs().$q->td(
					{-valign => "top", -class => hardcode->classPrefs},
					getTabs(IN).htmlSpace(
						hardcode->termRowPlural.':'.
						hardcode->nonBreakingSpace.
						$q->b("'".$c->maximumRows()."'").
						hardcode->nonBreakingSpace
					).getTabs(OUT)
				),
				getTabs().$q->td(
					{-valign => "top", -class => hardcode->classPrefs},
					getTabs(IN).$q->a({
						-href => $this->getSelfURL({
							hardcode->cgiParmQueryOffset => 0,
							hardcode->cgiParmResetCookie =>
								hardcode->cgiResetTrue
						})},
						hardcode->resetTitle
					).getTabs(OUT)
				).getTabs(OUT)
			).getTabs()
		).getTabs(OUT);
	
	# Print the table that comes under the logo
	if ($queryPage) {
		# The query type
		
		# The row containing the project name
		my $projectRow = 
			getTabs(SET, 2).$q->TR(
				getTabs(IN).$q->td(
					{-valign => "top", -colspan => 2},
					$q->h3(
						hardcode->termDatabase." <font color=darkblue>".ucfirst $dbname."</font>".
						$q->br().
						$q->img({-src => hardcode->lineIcon})
					)
				).getTabs(OUT)
			);
		
		# The row containing the description of the data and associated icon
		my $titleRow = 
			getTabs(SET, 2).$q->TR(
				getTabs(IN).$q->td(
					{-valign => "top"},
					$q->h3($this->title())
				),
				getTabs().$q->td(
					{-valign => "top"},
					$icon ?
					$q->img({-src => $icon}) :
					'&nbsp;'
				).getTabs(OUT)
			);
		
		# The row of links for by month, by author, etc
		my $links;
		
		foreach my $ln (hardcode->cgiQueryLinks) {
			# For the bugzilla link, make it plain text if there is no bugzilla URL.
			my $noBug = 
				$ln eq hardcode->cgiQueryBugzilla &&
				$this->bugzillaURL() eq hardcode->cookieDefaultValue;
			
			$links .=
				getTabs(SET, 5).
				$q->td(
					{-class => hardcode->classLinks},
					getTabs(IN).
					($links ? hardcode->nonBreakingSpace : "").
					($noBug ?
					htmlSpace(hardcode->titleURLTexts->{$ln}) :
					$q->a({
						-href => $this->getSelfURL(
							{hardcode->cgiParmDB =>
								($ln eq hardcode->cgiQueryList) ?
								'' :
								$this->getDatabase(),
							hardcode->cgiParmSupportedTables =>
								$this->supportedTables(),
							hardcode->cgiParmQuery => $ln,
							hardcode->cgiParmQueryDetail =>
								hardcode->cgiQueryDetailByQuery,
							hardcode->cgiParmQuerySortBy =>
								hardcode->cgiQueryDefaultSortAll->{$ln},
							hardcode->cgiParmBugzillaURL =>
								$this->bugzillaURL()
							},
							1
						)},
						htmlSpace(hardcode->titleURLTexts->{$ln})
					)).
					getTabs(OUT)
				);
		};
		
		# The link for changing the project is different,
		# it also needs to reset the preferences.	
		my $linkRow =
			getTabs(SET, 4).$q->TR(
				$links
			).getTabs(NO);
		
		# The horizontal rule row
		my $hrRow = 
			getTabs(SET, 4).$q->TR(
				getTabs(IN).$q->td(
					{-colspan => 5},
					$q->hr()
				).getTabs(OUT)
			).getTabs();
				
		# The table containing the links and the horizontal rule
		my $linkTable =
			getTabs().$q->table(
				{
					-border => hardcode->tableLinkBorder,
					-cellpadding => 0,
					-cellspacing => 0
				},
				$linkRow,
				$hrRow
			).getTabs();

		# The table containing the links and preferences
		my $botRightTable =
			getTabs(SET, 2).$q->TR(
				getTabs(IN).$q->td(
					{-valign => "top", -colspan => 2},
					$linkTable,
					$prefsTable
				).getTabs(OUT)
			).getTabs();
	
		# The right hand table of the whole display
		my $rightTable = 
			getTabs(SET, 2).$q->table(
				{-border => hardcode->tableRightSideBorder},
				$projectRow,
				$titleRow,
				$botRightTable
			).getTabs(OUT);
		
		# Add the whole nested table to the body
		# The art for the db may not exist
		my $art =
			-e "art/$dbname-small.png" ?
			"art/$dbname-small.png" :
			"";
		$this->addBody(
			$q->table(
				{-border => hardcode->tableHeaderBorder},
				getTabs(SET, 0).$q->TR(
					getTabs(IN).$q->td(
						{-valign => "top"},
						$art ?
						$q->img({-src => $art}).getTabs() :
						'&nbsp;'
					),
					getTabs().$q->td(
						{-valign => "top"},
						$rightTable
					).getTabs(OUT)
				).getTabs(OUT)
			).getTabs()
		);
	} else {
		# The list of databases type
		$this->addBody(
			$q->p(),
			$prefsTable,
			$q->p(),
			$q->table(
				{-border => hardcode->tableBorder},
				getTabs(SET, 0).$q->TR(
					getTabs(IN).$q->td(
						{-valign => "top"},
						$q->h3($this->title()),
						$q->img({-src => "art/line.gif"})
					).getTabs(OUT)
				).getTabs()
			).getTabs()
		);
	}
}

=head3 mainQuery (dbMethod : code(), htmlMethod : code(results : [[scalar]]), emptyQueryMethod : code(offset : int, startDate : string, endDate : string, devList : (string)))

Create the by query page, which is common to most query types.

Parameters:

=over

=item* dbMethod => the databaseAccess method to get the data for the page

=item* htmlMethod => the html method to display the data for the page

=item* emptyQueryMethod => the method to display an error if there is no data to display

=back

Returns:

=over

=item* none

=back

=cut
sub mainQuery {
	my $this = shift;
	my $dbMethod = shift;
	my $htmlMethod = shift;
	my $emptyQueryMethod = shift;
	my $emptyQueryData = shift;
	
	# Get the data from the database
	my $data = $dbMethod->();
	
	# Are there more results?
	my $more = shift @{$data};
	
	# Display the results if there are any
	if (@{$data} > 0) {
		$this->addBody($htmlMethod->($data));
		
		# Display the prvious and next links
		$this->offsetLinks($more);
	} else {
		my $q = $this->{'q'};
		my $c = $this->{'c'};
		
		$this->addBody($q->p($q->b(&$emptyQueryMethod(
			-specific => $emptyQueryData,
			-offset => $this->getOffset() * $c->maximumRows() + 1,
			-singleDate => $this->getDate(),
			-startDate => $c->getStartDate(),
			-endDate => $c->getEndDate(),
			-devList => [$c->developers()]
		))));
	}
}
	
=head3 mainMRID (db : databaseAccess) => areResults : bool

Create the mrid details page, which is common to all query types.

Parameters:

=over

=item* db => databaseAccess object

=back

Returns:

=over

=item* areResults => true if there are results to display, false if not

=head4 Note: The areResults flag is false only if there are no results AND this routine doesn't have enough information to process the error by itself

=back

=cut
sub mainMRID {
	my $this = shift;
	my $db = shift;
	
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	# Get the MR details results
	my $mrresults = $db->getMRDetail();

	# Eliminate the flag in this case
	shift @{$mrresults};
	
	# The flag to return
	my $areResults = @{$mrresults} > 0;
	
	if ($areResults) {
		# Get some data we need if an error occurs
		my $mridselect = $this->getMRIDSelect();
		my $offset = $this->getOffset();
		my $startDate = $c->getStartDate();
		my $endDate = $c->getEndDate();
		my @devList = $c->developers();
		
		# Get the MR ID results
		my $mridresults = $db->getMRIDDetail();

		# Are there more results?
		my $more = shift @{$mridresults};

		# Get the MR ID stats if the mrstats table is supported
		my $mridstats = $this->supportedTables()->{'mrstats'};
		my $mridstatsresults =
			$mridstats ?
			$db->getMRIDStats() :
			[];

		# Dump the more flag on the stats
		shift @{$mridstatsresults};

		# Display them
		if (@{$mridresults} > 0) {
			$this->addBody(
				$this->MRDetail($mrresults),
				$this->MRIDDetail($mridselect, $mridresults)
			);

			# Display the stats if available
			if ($mridstats) {
				if (@{$mridstatsresults} > 0) {
					$this->addBody($this->MRIDStats($mridstatsresults));

				# No results for the mr id stats
				} else {
					$this->addBody($q->p($q->b(
						hardcode::emptyQueryMRIDStats(
							$mridselect,
							$startDate,
							$endDate,
							@devList
						)
					)));
				}
			}
				
			# Show the previous and next links
			$this->offsetLinks($more);

		# No results for the mr id
		} else {
			$this->addBody($q->p($q->b(
				hardcode::emptyQueryMRIDDetail(
					$mridselect,
					$offset,
					$startDate,
					$endDate,
					@devList
				)
			)));
		}
	}
	
	return $areResults;
}

1;
