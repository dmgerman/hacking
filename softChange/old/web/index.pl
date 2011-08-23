#!/usr/bin/perl -w

use strict;
use databaseAccess;
use html;
use hardcode;

=head1 Main softChange Application Code : C<index.pl>

=head2 Uses: C<databaseAccess.pm>, C<hardcode.pm>, C<html.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

This is the main application code to create web pages and interact
with the user. This code just acts as a conduit between F<databaseAccess.pm>,
F<cookie.pm>, and F<html.pm>.

=cut

# Objects needed for creating other objects
my $q = new CGI();
my $c = new cookie($q);

# Set the language before doing anything else.
# First, check the cookie language. If it is
# not defined, then use whatever apache indicates.
$0 =~ /(\w\w)$/;
language($1);

# Create the html object
my $h = new html($q, $c);

# The title and icon to use for this page
my $query = $h->getQuery();
my $detail = $h->getDetail();
my $mrselect = $h->getMRSelect();
my $mridselect = $h->getMRIDSelect();
my $fileselect = $h->getFileSelect();
my $revisionselect = $h->getRevisionSelect(),
$h->title(hardcode->titleNames->{$query});
$h->icon(hardcode->titleIcons->{$query})
	unless $query eq hardcode->cgiQueryList;

# Create the database access object
my $db = new databaseAccess($q, $h, $c);

# Information that may need to be inserted into display phrases.
my $offset = $h->getOffset() * $c->maximumRows() + 1;
my $server = hardcode->dbServer;
my $user = hardcode->dbUsername;
my $singleDate = $h->getDate();
$singleDate = $c->getFormattedDate($singleDate)
	if $singleDate ne hardcode->cookieDefaultValue;
my $startDate = $c->getStartDate();
my $endDate = $c->getEndDate();
my @devList = $c->developers();
my $month = $h->getFormattedMonth();

# Get the bugzilla URL for the current project.
# If it is the default value, then the info table has not been loaded.
# In that case, load the table into the parameters and then they will
# be carried automatically from page to page.
if ($h->getDatabase()) {
	if ($h->bugzillaURL() eq hardcode->cookieDefaultValue) {
		# Connect to the current database
		$db->database($h->getDatabase());
		
		# Get the information from the table
		my $results = $db->getInfo();
		
		print STDERR "BUGZILLA = ".$results->[1]->[2]."\n";
		
		# Extract the bugzilla URL
		# Remember: the first row is the more flag,
		# and the first column of the remaining rows is
		# the line number.
		$h->bugzillaURL($results->[1]->[2]);
	}
}

# The mainHeader() function will produce the top of the page.
# If there is no selected database, it is just a logo and a
# choose project list. If there is a selected database, it is
# the logo and a set of links in a table.
$h->mainHeader();

# Display either a list of database or query results
CASE: {
	($query eq hardcode->cgiQueryList) && do {
		# Reset the cookie parameters
		$c->resetCookie();
		
		# Connect to the initial database
		$db->database(hardcode->dbInitialConnect);

		# Add a blank paragraph
		$h->blankParagraph();

		# Show the list of projects
		$h->mainQuery(
			sub {$db->getDatabaseList()},
			sub {$h->databaseList(@_)},
			\&hardcode::emptyQueryDBList,
			[$server, $user]
		);
		
		$db->disconnect();

		last CASE;
	};

	($query eq hardcode->cgiQueryMonth) && do {
		# Connect to the current database
		$db->database($h->getDatabase());

		# Add a blank paragraph
		$h->blankParagraph();
		
		MONTHDETAIL: {
			# Show the list of months for basic details
			($detail eq hardcode->cgiQueryDetailByQuery) && do {
				$h->mainQuery(
					sub {$db->getMRByMonth()},
					sub {$h->MRByMonth(@_)},
					\&hardcode::emptyQueryMonth
				);
				
				last MONTHDETAIL;

			};
			
			# Show the details for one month
			($detail eq hardcode->cgiQueryDetailByMR) && do {
				$h->mainQuery(
					sub {$db->getMRDetail()},
					sub {$h->MRDetail(@_)},
					\&hardcode::emptyQueryMonthDetail,
					[$month]
				);
				
				last MONTHDETAIL;
			};

			# Show the details for the selected mrid
			($detail eq hardcode->cgiQueryDetailByMRID) && do {
				# Display the results or an error if there are none
				$h->mainMRID($db) ||
					$h->addBody($q->p($q->b(
						hardcode::emptyQueryMonthDetail(
							$month,
							$offset,
							$singleDate,
							$startDate,
							$endDate,
							@devList
						)
					)));

				last MONTHDETAIL;
			};

			# Any other level of detail represents an invalid state.
			$h->unimplementedPage();
		};

		last CASE;
	};
	
	($query eq hardcode->cgiQueryAuthor) && do {
		# Connect to the current database
		$db->database($h->getDatabase());

		# Get the query results
		# Add a blank paragraph
		$h->blankParagraph();
		
		AUTHDETAIL: {
			# Show the list of authors for basic details
			($detail eq hardcode->cgiQueryDetailByQuery) && do {
				$h->mainQuery(
					sub {$db->getMRByAuthor()},
					sub {$h->MRByAuthor(@_)},
					\&hardcode::emptyQueryAuthor
				);
				
				last AUTHDETAIL;
			};
			
			# Show the details for the selected author or date
			($detail eq hardcode->cgiQueryDetailByMR) && do {
				# Get the details of all mrs for the author or date
				$h->mainQuery(
					sub {$db->getMRDetail()},
					sub {$h->MRDetail(@_)},
					\&hardcode::emptyQueryAuthorDetail,
					[$mrselect]
				);
				
				last AUTHDETAIL;
			};

			# Show the details for the selected mrid
			($detail eq hardcode->cgiQueryDetailByMRID) && do {
				# Display the results or an error if there are none
				$h->mainMRID($db) ||
					$h->addBody($q->p($q->b(
						hardcode::emptyQueryAuthorDetail(
							$mrselect,
							$offset,
							$singleDate,
							$startDate,
							$endDate,
							@devList
						)
					)));

				last AUTHDETAIL;
			};

			# Any other level of detail represents an invalid state.
			$h->unimplementedPage();
		};
	
		last CASE;
	};
	
	($query eq hardcode->cgiQueryFile) && do {
		# Connect to the current database
		$db->database($h->getDatabase());

		# Add a blank paragraph
		$h->blankParagraph();
		
		FILEDETAIL: {
			# Show the list of files for basic details
			($detail eq hardcode->cgiQueryDetailByQuery) && do {
				# Get the results for the list of files
				$h->mainQuery(
					sub {$db->getMRByFile()},
					sub {$h->MRByFile(@_)},
					\&hardcode::emptyQueryFile
				);
				
				last FILEDETAIL;
			};
		
			# Show the details for one file
			($detail eq hardcode->cgiQueryDetailByFile) && do {
				# Display the results for the file
				$h->mainQuery(
					sub {$db->getMRByFileName()},
					sub {$h->MRByFileName(@_)},
					\&hardcode::emptyQueryFileName,
					[$fileselect]
				);
				
				last FILEDETAIL;
			};

			# Show the details for the selected mrid
			($detail eq hardcode->cgiQueryDetailByMRID) && do {
				# Display the results or an error if there are none
				$h->mainMRID($db) ||
					$h->addBody($q->p($q->b(
						hardcode::emptyQueryFileName(
							$fileselect,
							$offset,
							$singleDate,
							$startDate,
							$endDate,
							@devList
						)
					)));

				last FILEDETAIL;
			};

			# Any other level of detail represents an invalid state.
			$h->unimplementedPage();
		
		};
	
		last CASE;
	};
	
	($query eq hardcode->cgiQueryBugzilla) && do {
		# Connect to the current database
		$db->database($h->getDatabase());

		# Add a blank paragraph
		$h->blankParagraph();
		
		BUGDETAIL: {
			# Show the list of bugs for basic details
			($detail eq hardcode->cgiQueryDetailByQuery) && do {
				# Get the results for the list of bugs, if there's a valid bugzilla URL
				$h->mainQuery(
					sub {$db->getBugzilla()},
					sub {$h->MRByBugzilla(@_)},
					\&hardcode::emptyQueryBugzilla
				);
				
				last BUGDETAIL;
			};

			# Show the details for the selected mrid
			($detail eq hardcode->cgiQueryDetailByMRID) && do {
				# Display the results or an error if there are none
				$h->mainMRID($db) ||
					$h->addBody($q->p($q->b(
						hardcode::emptyQueryMRIDDetail(
							$mridselect,
							$offset,
							$startDate,
							$endDate,
							@devList
						)
					)));

				last BUGDETAIL;
			};

			# Any other level of detail represents an invalid state.
			$h->unimplementedPage();

		};
	
		last CASE;
	};
	
	# The search page has four boxes:
	# with all of the words
	# with the exact phrase
	# with at least one of the words
	# without the words
	($query eq hardcode->cgiQuerySearch) && do {
		SEARCHDETAIL: {
			# Show the search form for basic details and search results
			($detail ne hardcode->cgiQueryDetailByMRID) && do {

				# Add the form to the body
				$h->searchForm();
				
				# Continue on and perform the search if necessary
			};
			
			($detail eq hardcode->titleURLDoSearch) && do {
				# Connect to the current database
				$db->database($h->getDatabase());

				# Add a blank paragraph
				$h->blankParagraph();
				
				# Display the search results
				$h->mainQuery(
					sub {$db->getSearch()},
					sub {$q->hr(); $h->searchResults(@_)},
					\&hardcode::emptyQuerySearch
				);
				
				last SEARCHDETAIL;
			};

			# Show the details for the selected mrid
			($detail eq hardcode->cgiQueryDetailByMRID) && do {
				# Connect to the current database
				$db->database($h->getDatabase());

				# Display the results or an error if there are none
				$h->mainMRID($db) ||
					$h->addBody($q->p($q->b(
						hardcode::emptyQuerySearch(
							$offset,
							$startDate,
							$endDate,
							@devList
						)
					)));

				last SEARCHDETAIL;
			};

			# Any other level of detail represents an invalid state.
			# However, we've already displayed the search form, so don't
			# display an error message. Just do nothing.

		};
	
		last CASE;
	};
	
	# The search page has four boxes:
	# with all of the words
	# with the exact phrase
	# with at least one of the words
	# without the words
	($query eq hardcode->cgiQueryRevision) && do {
		# Make sure the required tables exist
		my $haveTables = $h->supportedTables()->{'revisiondiffs'};
		
		if ($haveTables) {
			# Connect to the current database
			$db->database($h->getDatabase());

			# Get the query results
			# Add a blank paragraph
			$h->blankParagraph();

			REVISIONDETAIL: {
				# Show the revisison diffs for basic details
				($detail eq hardcode->cgiQueryDetailByQuery) && do {
					# Get the details of the revision
					my $details = $db->getRevisionDetails();

					# Eliminate the flag in this case
					shift @{$details};

					# Make it look as if this is a request for mrid details.
					$h->setDetail(hardcode->cgiQueryDetailByMRID);

					# Get the MR details results
					my $mrresults = $db->getMRDetail();

					# Eliminate the flag in this case
					shift @{$mrresults};
					
					# Extract the previous id from the details, if available
					my $previd = $details->[0]->[3];
					
					# Get the differences in the definitions. There can always
					# be defs added, even if there is only one revision.
					# However, defs removed will not exist if there is no
					# previous revision. Regardless, calling the database
					# functions will always work, they will at least return
					# the more flag.
					my $defsRemoved = $db->getRevisionDefsRemoved($previd);
					my $defsAdded = $db->getRevisionDefsAdded($previd);
					my $defsModified = $db->getRevisionDefsModified($previd);
					
					# Eliminate the flags in this case
					shift @{$defsRemoved};
					shift @{$defsAdded};
					shift @{$defsModified};
					
					my $cleanDiffs = "";
					my $originalDiffs = "";
					
					if ($previd) {
						$cleanDiffs = $db->getRevisionDiffs(1, $previd, $details->[0]->[8]);
						$originalDiffs = $db->getRevisionDiffs(0, $previd, $details->[0]->[7]);
						
						# Eliminate the flags in this case
						shift @{$cleanDiffs};
						shift @{$originalDiffs};
					}

					# Display the results.
					# It is possible that the set of differences in
					# definitions is empty, that is ok - it just means
					# that no methods/functions/etc were added or removed.
					# So do not count that as an error.
					if (@{$details} > 0) {
						if (@{$mrresults} > 0) {
							$h->addBody($h->revisionDetails($details));
							$h->smallSpace();
							
							$h->addBody($h->MRDetail($mrresults));
							$h->smallSpace();
							
							# Make a table that surrounds the differences in
							# the definitions, with the removed definitions on
							# the left and the added definitions on the right.
							# Manually place the title before the outer table.
							# Only display this if there some definitions that
							# were either removed or added.
							if (($defsRemoved && @{$defsRemoved}) || ($defsAdded && @{$defsAdded}) || 
							    ($defsModified && @{$defsModified})) {
		
								# Get the removed subtable
								my $removed =
									$defsRemoved ?
									$h->revisionDefs($defsRemoved, (hardcode->colsRevisionDefsOuter)[0]) :
									"";
								
								# Get the added subtable
								my $added =
									$defsAdded ?
									$h->revisionDefs($defsAdded, (hardcode->colsRevisionDefsOuter)[1]) :
									"";
									
								my $modified =
									$defsModified ?
									$h->revisionDefs($defsModified, (hardcode->colsRevisionDefsOuter)[2]) :
									"";

								$h->addBody(
									$q->h3(hardcode->revisionDefsTitle),
									$q->table(
										{-cellpadding => 0,
										-cellspacing => 0,
										-border => 0
										},
										$q->TR(
											{-valign => "top"},
											$q->td($removed),
											$q->td($added),
											$q->td($modified),
										)."\n"
									)."\n");
								$h->smallSpace();
							}
							
							# Make a table that contains the side by side changes in the clean source
							# code, with the revious rev on the left and the current rev on the right.
							# Only do this if there is a previous revision to compare to.
							if ($previd) {
								$h->addBody(
									$q->hr(),
									$q->h3($q->b(hardcode->cleanDiffsTitle)),
									$h->revisionDiffs(1, $previd, $revisionselect, $cleanDiffs)
								);
								$h->smallSpace();
								$h->addBody(
									$q->hr(),
									$q->h3($q->b(hardcode->originalDiffsTitle)),
									$h->revisionDiffs(0, $previd, $revisionselect, $originalDiffs)
								);
							}

						# No results for the revision
						} else {
							$h->addBody($q->p($q->b(
								hardcode::emptyQueryRevision(
									$fileselect,
									$revisionselect,
									$startDate,
									$endDate,
									@devList
								)
							)));
						}
					# No results for the details
					} else {
						$h->addBody($q->p($q->b(
							hardcode::emptyQueryRevisionDetails(
								$fileselect,
								$revisionselect
							)
						)));
					}

					last REVISIONDETAIL;
				};

				# Show the details for the selected mrid
				($detail eq hardcode->cgiQueryDetailByMRID) && do {
					# Connect to the current database
					$db->database($h->getDatabase());
					
					# Display the results or an error if there are none
					$h->mainMRID($db) ||
						$h->addBody($q->p($q->b(
							hardcode::emptyQueryRevisionDetails(
								$fileselect,
								$revisionselect
							)
						)));

					last REVISIONDETAIL;
				};

				# Any other level of detail represents an invalid state.
				$h->unimplementedPage();
			};
		} else {
			$h->addBody($q->p($q->b(
				hardcode::revisionsNotSupported($h->getDatabase())
			)));
		}
	}
}

# Disconnect from the database
$db->disconnect();

# Write out the html
$h->writeHTML();
