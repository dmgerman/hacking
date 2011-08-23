#!/usr/bin/perl -w

package hardcode;
use strict;
use Exporter;

our (@ISA, @EXPORT, @LANG);
@ISA = 'Exporter';
@EXPORT = (
	'language',
	'trim', 'trim2', 'IN', 'OUT', 'SET', 'NO', 
	'getTabs', 'monthName', 'htmlSpace', 'formatLog',
	'emptyQuerySingleDate'
);

=head1 hardcode package : C<hardcode.pm>

=head2 Uses: C<Exporter.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<constant>, C<strict>

This package contains all hard coded data.
Any literal string that appears on a web page,
or any pathname to artwork are all defined
here. Explanations are given for what each
hard coded piece of data affects on the web site.

=cut

# The set of languages we have locale-specific files for
opendir LOCDIR, "." or die "Can't open current directory";
while (my $next = readdir LOCDIR) {
	push @LANG, $1 if ($next =~ /^locale_(\w\w)\.pm$/);
}
close LOCDIR;


#
#
# Constants that do not need to be internationalised
#
#

# The default language to use
use constant defaultLanguage => 'en';

# Which sets of documentation have been installed
use constant withUserManual => 1;
use constant withProgManual => 1;
use constant withPOD => 1;

# The word to use for this software package
use constant termSoftChange => 'softChange';


#
# Cookie values
#

use constant cookieDefaultValue => 'any';

# The amount of non-breaking space to use between items
use constant nonBreakingSpace => '&nbsp;&nbsp;&nbsp;';

#
# Table debugging flags
#

# Whether or not to put a border around all tables
use constant tableBorder => 0;

# Border flags for specific tables

# The table of links (By Date, By Author, etc)
use constant tableLinkBorder => tableBorder || 0;

# The table of preferences (Preferences, Time Range, Authors)
use constant tablePrefsBorder => tableBorder || 0;

# The table for the right hand side of the header
# Contains the links and prefs tables
use constant tableRightSideBorder => tableBorder || 0;

# The table containing the project icon and all the above tables
use constant tableHeaderBorder => tableBorder || 0;

# The table containing the query results
use constant tableQueryResults => tableBorder || 0;

#
# Table settings
#

# The padding for the query tables
use constant tableQueryPadding => 5;

#
# Database query debugging flags
#

# Debug all queries
use constant dbQueryDebug => 0;

# Debug specific queries

# Debug the database list query
use constant dbQueryDBListDebug => dbQueryDebug || 0;

# Debug the developer list query
use constant dbQueryDevListDebug => dbQueryDebug || 0;

# Debug the date ranges query
use constant dbQueryDateRangesDebug => dbQueryDebug || 0;

# Debug the bymonth query
use constant dbQueryByMonthDebug => dbQueryDebug || 0;

# Debug the byauthor query
use constant dbQueryByAuthorDebug => dbQueryDebug || 0;

# Debug the byfile query
use constant dbQueryByFileDebug => dbQueryDebug || 0;

# Debug the byfilename query
use constant dbQueryByFileNameDebug => dbQueryDebug || 0;

# Debug the mr query
use constant dbQueryMRDebug => dbQueryDebug || 0;

# Debug the mrid query
use constant dbQueryMRIDDebug => dbQueryDebug || 0;

# Debug the mrid stats query
use constant dbQueryMRIDStatsDebug => dbQueryDebug || 0;

# Debug the bugzilla query
use constant dbQueryByBugzillaDebug => dbQueryDebug || 0;

# Debug the search query
use constant dbQuerySearchDebug => dbQueryDebug || 0;

# Debug the info query
use constant dbQueryInfoDebug => dbQueryDebug || 0;

# Debug the mrid from filename/rev id query
use constant dbQueryFileRevToMRIDDebug => dbQueryDebug || 0;

# Debug the revision details query
use constant dbQueryRevisionDetailsDebug => dbQueryDebug || 0;

# Debug the revision defs queries
use constant dbQueryRevisionDefsDebug => dbQueryDebug || 0;

# Debug the revision diffs queries
use constant dbQueryRevisionDiffs => dbQueryDebug || 0;

#
# Database server information
#

# The server containing the databases
use constant dbServer => '';

# The username to connect to the server with
use constant dbUsername => 'apache';

# The password for the above username
use constant dbPassword => 'evolution';

# The database to use for the initial connection
use constant dbInitialConnect => 'template1';

# Databases that are known not to be able to connect to.
# Setting this just eliminates error messages in apache's error-Log.
use constant dbBadDatabases => ('template0');

#
# Style information
#

# The dtd to use for the web pages
use constant htmlDTD => '-//W3C//DTD HTML 3.2//EN';

# The content type for the web pages
use constant htmlType => 'text/html';

# The color to use for the background
use constant styleBackColor => 'white';

# The stylesheet to use for html styles
use constant styleSheet => 'style.css';

# The class to use for the set of links
use constant classLinks => 'bar';

# The class to use for the query header column
use constant classQueryHeader => 'black';

# The classes to use for alternating rows
use constant classQueryRows => (
	'back1',
	'back0'
);

# The color to use to hide non-breaking space in a
# multi-line link. This color should be the same as
# some style in the stylesheet.
use constant styleMultiLineNBSPColor => 'black';

# The class to use on the prefs page
use constant classPrefs => classLinks;

#
# The method to use for forms
#

use constant formMethod => 'GET';

#
# The names of CGI parameters
#

# The main page
use constant cgiParmDB => 'database';
use constant cgiParmQuery => 'query';
use constant cgiParmQueryOffset => 'queryOffset';
use constant cgiParmQueryDetail => 'queryDetail';
use constant cgiParmQueryMRSelect => 'queryMRSelect';
use constant cgiParmQueryMRIDSelect => 'queryMRIDSelect';
use constant cgiParmQueryFileSelect => 'queryFileSelect';
use constant cgiParmQueryRevisionSelect => 'queryRevisionSelect';
use constant cgiParmQuerySortBy => 'querySort';
use constant cgiParmQuerySortDir => 'querySortDir';
use constant cgiParmQueryDeveloper=> 'queryDeveloper';
use constant cgiParmQueryDate => 'queryDate';
use constant cgiParmBugzillaURL => 'bugzilla';
use constant cgiParmSupportedTables => 'supportedTables';
use constant cgiParmPrefs => 'prefs';
use constant cgiParmResetCookie => 'reset';

# The preferences page
use constant cgiParmReferer => 'referer';
use constant cgiParmApplyDevelopers => 'applyDevel';
use constant cgiParmSetDevelopers => 'developers';
use constant cgiParmApplyDates => 'applyDates';
use constant cgiParmDateFrom => ('fromMonth', 'fromDay', 'fromYear');
use constant cgiParmFromMonth => 'fromMonth';
use constant cgiParmFromDay => 'fromDay';
use constant cgiParmFromYear => 'fromYear';
use constant cgiParmDateTo => ('toMonth', 'toDay', 'toYear');
use constant cgiParmToMonth => 'toMonth';
use constant cgiParmToDay => 'toDay';
use constant cgiParmToYear => 'toYear';
use constant cgiParmMaxRows => 'maxRows';
use constant cgiParmLanguage => 'language';
use constant cgiParmDateFormat => 'dateFormat';
use constant cgiParmWritePrefs => 'writePrefs';
use constant cgiParmCancelPrefs => 'cancelPrefs';

#
# Values of CGI parameters
#

use constant cgiQueryList => 'project';
use constant cgiQueryMonth => 'byMonth';
use constant cgiQueryAuthor => 'byAuthor';
use constant cgiQueryFile => 'byFileName';
use constant cgiQueryBugzilla => 'byBugzilla';
use constant cgiQuerySearch => 'search';
use constant cgiQueryRevision => 'revision';
use constant cgiPrefsTrue => 'preferences';
use constant cgiResetTrue => 'reset';
use constant cgiQueryDefault => cgiQueryMonth;

# Detail level
use constant cgiQueryDetailByQuery => 'byQuery';
use constant cgiQueryDetailByMR => 'byMR';
use constant cgiQueryDetailByMRID => 'byMRID';
use constant cgiQueryDetailByFile => 'byFile';
use constant cgiQueryDetailDefault => cgiQueryDetailByQuery;

use constant cgiQueryLinks => (
	cgiQueryList,
	cgiQueryMonth,
	cgiQueryAuthor,
	cgiQueryFile,
	cgiQueryBugzilla,
	cgiQuerySearch
);

use constant cgiQueryAll => (
	cgiQueryList,
	cgiQueryMonth,
	cgiQueryAuthor,
	cgiQueryFile,
	cgiQueryBugzilla,
	cgiQuerySearch,
	cgiQueryRevision
);

# Sorting directions
use constant cgiQuerySortDirAsc => 'ASC';
use constant cgiQuerySortDirDesc => 'DESC';
use constant cgiQuerySortDefaultDir => cgiQuerySortDirAsc;

# Specify that there is no sort
use constant cgiQuerySortNone => 'NO';

# These cgi parameter values are the names of SQL tables
use constant cgiQueryDBListSortBy => (
	cgiQuerySortNone,
	'd.datname'
);
use constant cgiQueryDBListDefaultSort =>
	(cgiQueryDBListSortBy)[1];

use constant cgiQueryMonthSortBy => (
	cgiQuerySortNone,
	'month',
	'count'
);
use constant cgiQueryMonthDefaultSort =>
	(cgiQueryMonthSortBy)[1];

use constant cgiQueryMRSortBy => (
	cgiQuerySortNone,
	'mrid',
	'author',
	'files',
	'daterev',
	'timerev',
	'log'
);
use constant cgiQueryMRDefaultSort =>
	(cgiQueryMRSortBy)[4];

use constant cgiQueryMRIDSortBy => (
	cgiQuerySortNone,
	'filename',
	'revisionid',
	'linesadd',
	'linesrm',
	'linestotal',
	'state'
);
use constant cgiQueryMRIDDefaultSort =>
	(cgiQueryMRIDSortBy)[2];

use constant cgiQueryAuthorSortBy => (
	cgiQuerySortNone,
	'author',
	'count',
	'first',
	'last'
);
use constant cgiQueryAuthorDefaultSort =>
	(cgiQueryAuthorSortBy)[1];


use constant cgiQueryFileSortBy => (
	cgiQuerySortNone,
	'filename',
	'mrs',
	'author',
	'first',
	'last'
);
use constant cgiQueryFileDefaultSort =>
	(cgiQueryFileSortBy)[1];

use constant cgiQueryFileNameSortBy => (
	cgiQuerySortNone,
	'mrsfiles.mrid',
	'author',
	'revisionid',
	'linesadd',
	'linesrm',
	'linesabs',
	'state',
	'mrsfiles.daterev',
	'mrsfiles.timerev',
	'log'
);
use constant cgiQueryFileNameDefaultSort =>
	(cgiQueryFileNameSortBy)[8];
	
use constant cgiQueryBugzillaSortBy => (
	cgiQuerySortNone,
	'mrid',
	'bugs',
	'daterev',
	'log'
);
use constant cgiQueryBugzillaDefaultSort =>
	(cgiQueryBugzillaSortBy)[3];

use constant cgiQuerySearchSortBy => (
	cgiQuerySortNone,
	'mrid',
	'author',
	'daterev',
	'timerev',
	'log'
);
use constant cgiQuerySearchDefaultSort =>
	(cgiQuerySearchSortBy)[3];
	
use constant cgiQueryRevisionSortBy => (
	cgiQuerySortNone,
	'removed',
	'added'
);
use constant cgiQueryRevisionDefaultSort =>
	(cgiQueryRevisionSortBy)[1];
	
use constant cgiQueryRevisionDefsDefaultSort =>
	'definition';

use constant cgiQueryDefaultSortAll => {
	hardcode->cgiQueryList => cgiQueryMonthDefaultSort,
	hardcode->cgiQueryMonth => cgiQueryMonthDefaultSort,
	hardcode->cgiQueryAuthor => cgiQueryAuthorDefaultSort,
	hardcode->cgiQueryFile => cgiQueryFileDefaultSort,
	hardcode->cgiQueryBugzilla => cgiQueryBugzillaDefaultSort,
	hardcode->cgiQuerySearch => cgiQueryMonthDefaultSort,
	hardcode->cgiQueryRevision => cgiQueryRevisionDefaultSort
};

# Preferences
use constant cgiMaxRowsValues => (10, 25, 50, 75, 100);
use constant cgiMaxRowsDefault => (cgiMaxRowsValues)[1];
use constant cgiWritePrefsTrue => 'writePrefs';
use constant cgiCancelPrefsTrue => 'cancelPrefs';

#
# URLs
#

# Base directory for files
use constant baseDirectory => '/softChange';

# The main project url
use constant mainURL => "index.html";

# The preferences url
use constant prefsURL => "preferences.html";

# The documentation urls
use constant userManualURL => baseDirectory."/usermanual";
use constant progManualURL => baseDirectory."/progmanual";
use constant podURL => baseDirectory."/pod";

# The separator to use for the path
use constant pathSeparator => '&nbsp;-&gt;&nbsp;';

#
# Form names
#

# Main page forms

# The name of the form that lists databases to choose from
use constant databaseListForm => 'databaseList';

# The name of the form with the links for By Date, etc
use constant linksFormName => 'setQuery';

# The name of the subform within the links for choosing a new project
use constant projectFormName => 'project';

# The name of the form for linking to preferences
use constant prefsLinkFormName => 'gotoPrefs';

# The name of the form for resetting preferences
use constant prefsResetFormName => 'resetPrefs';

# Search form

# The name of the form for search queries
use constant searchFormName => 'search';

# The names of the form elements for entering search queries
use constant searchPhraseNames => (
	'searchWithAll',
	'searchWithExact',
	'searchWithAtLeast',
	'searchWithout'
);

# Preferences forms

# The name of the form that presents preferences
use constant prefsFormName => 'preferences';

# The name of the form that has the cancel button
use constant prefsCancelFormName => 'cancel';

#
# The locations and attributes of artwork
#

# The location of the logo
use constant logoIcon => 'art/softchange.gif';

# The location of the line
use constant lineIcon => 'art/line.gif';

# The size of the line under the logo
use constant logoLineWidth => 600;
use constant logoLineHeight => 4;

# The icons for display beside the titles
use constant titleIcons => {
	hardcode->cgiQueryMonth => 'art/bymonth.png',
	hardcode->cgiQueryAuthor => 'art/bydeveloper.png',
	hardcode->cgiQueryFile => 'art/byfile.png',
	hardcode->cgiQueryBugzilla => 'art/bybug.png'
};

#
# Preferences constants
#

use constant prefsDeveloperListSize => 10;
use constant prefsDateFirst => 0;
use constant prefsDateLast => 1;


#
#
# Constants used by internationalised text
#
#


# Date formatting constants for ordering
use constant dateMonthOrder => 0;
use constant dateDayOrder => 1;
use constant dateYearOrder => 2;

# Date formatting constants for formatting
use constant dateLongFormat => 0;
use constant dateShortFormat => 1;

# The default date format
use constant dateDefaultFormat => hardcode->dateLongFormat;


=head2 Function for Getting/Setting the language

=cut

=head3 language [ code : string, filecode : string ] => code : string

Set the language to use for displayed text.
The code must be a 2-character language code
as in 'en', 'fr', etc.

The filecode is the same kind of string as for code, if code
is an empty string, then the filecode is used. This is for
the implemtation of the default cookie choice, which is a
blank string.

Always returns the 2-char code that will be used, which may
be different. If the 2-char code given is not recognised,
it will default to english. 

If is up to the caller to first check the cookie language
before calling this function.

Parameters:

=over

=item* code => the 2-character language code to set

=item* filecode => the 2-character language code contained in the module filename

=back

Returns:

=over

=item* code => the current 2-character language code

=back

=cut
sub language {
	# The global language variable
	our $language;
	
	# Get the language code
	my $code = 'en';
	
	# If the code is specified, it must be non-blank,
	# and it must be a valid value. It can only come from
	# a file extension after apache type mapping.
	if ($code) {
		# Store the code for later use.
		$language = $code;

		# Load the file in
		require "locale_$code.pm";

		# Use typeglobs to set the values located
		# in the locale-specific file without actually
		# knowing what they are.
		my %hash = eval "%locale_".$code."::";
		map {
			eval "*$_ = *locale_".$code."::$_"
			if $_ ne "BEGIN" &&
			$_ ne "END" &&
			$_ ne "import";
		} keys %hash;
	}
	
	# Return the selected language
	return $language
}

=head2 Utility functions not specific to any class

=cut

=head3 getCGIQueryDetailAll => details : (string)

Get all the possible values for the detail level of a query.
This function is necessary because some of these values are
displayed to the user and must be internationalised.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* details => the array of possible detail values

=back

=cut
sub getCGIQueryDetailAll {
	return (
		cgiQueryDetailByQuery,
		cgiQueryDetailByMR,
		cgiQueryDetailByMRID,
		cgiQueryDetailByFile,
		eval "titleURLDoSearch"
	);
}

=head3 trim str : (string | list : [string]) => str : (string)

Trim leading and trailing whitespace across an array of strings.
Each element of the array may be either a scalar or array reference.
In the case of array references, each element of the array reference will be trimmed.

Parameters:

=over

=item* str => The strings to trim

=back

Returns:

=over

=item* trimmed strings

=back

=head4 Note: The regular expression character class C<\s> is used to match whitespace

=cut
sub trim {
	my @result;
	foreach my $i (@_) {
		if (ref($i) eq "ARRAY") {
			my $row;
			foreach my $j (@{$i}) {
				$j =~ s/^\s+//;
				$j =~ s/\s+$//;
				push @{$row}, $j;
			}
			push @result, $row;
		} else {
			my $j = $i;
			$j =~ s/^\s+//;
			$j =~ s/\s+$//;
			push @result, $j;
		}
	}
	
	return wantarray ? @result : $result[0];
}

sub trim2 {
	@_ = map {
		if (ref($_) eq "ARRAY") {
			trim2(@{$_});
		} else {
			if ($_) {
				$_ =~ s/^\s+//;
				$_ =~ s/\s+$//;
			}
			$_;
		}
	} @_;
	
	return @_;
}

=head3 getTabs IN [, NO ] => tabs : string

=head3 getTabs OUT [, NO ] => tabs : string

=head3 getTabs SET, numTabs : int [, NO ] => tabs : string

=head3 getTabs [ NO ] => tabs : string

Returns a string of tab characters, optionally prefixed with
a newline. The different forms operate as follows:

=over

=item* getTabs IN [, NO ] => Increment tabbing level and return string

=item* getTabs OUT [, NO ] => Decrement tabbing level and return string

=item* getTabs SET, numTabs : int [, NO ] => Set tabbing level and return string

=item* getTabs [ NO ] => Get tabbing level and return string

=back

The information required to track the tabbing level is a side effect of
the function maintained by global variables.

The optional NO suppresses the prefixing of a newline. Without this option,
a newline will be prefixed to the string.

=head4 Note: getTabs, IN, OUT, SET, and NO are exported as the group 'utility'

=cut
use constant IN => 1;
use constant OUT => 2;
use constant SET => 3;
use constant NO => 4;

our @tabs;
sub getTabs {
	my $tabCmd = shift;
	my $tabSet = shift;
	my $new = shift;
	
	$tabCmd = 0 if ! $tabCmd;
	my $prefix = "";
	
	CASE: {
		($tabCmd == IN) && do {
			push @tabs, "\t";
			$prefix = "\n" unless $tabSet;
			last CASE;
		};
		
		($tabCmd == OUT) && do {
			shift @tabs;
			$prefix = "\n" unless $tabSet;
			last CASE;
		};
		
		($tabCmd == SET) && do {
			@tabs = ();
			for(my $i = 0; $i < $tabSet; $i++) {
				push @tabs, "\t";
			}
			$prefix = "\n" unless $new;
			last CASE;
		};
		
		$prefix = "\n" unless $tabCmd;
	}
	
	return $prefix.join '', @tabs;
}

=head3 monthName numbers : [int] [ , ui : bool ] => names : (string)

Return the names of months from their numbers

Parameters:

=over

=item* numbers => an array of month numbers

=item* ui => true if unaccented month names should be used, otherwise false

=back

Returns:

=over

=item* (month names)

=back

=cut
sub monthName {
	my @result;
	
	my $monthList = shift;
	my $ui = shift;
	
	# A reverse hash lookup on termMonthNames
	foreach my $month (@{$monthList}) {
		# Use a copy of the list because we use each and
		# break out of the loop early.
		my %list = 
			$ui ?
			%{(eval "uiMonthNames")} :
			%{(eval "termMonthNames")};
			
		while((my $name, my $num) = each %list) {
			# The month could be an empty string
			if ($month && $num == $month) {
				push @result, $name;
				last;
			}
		}
	}
	
	return wantarray ? @result : $result[0];
}

=head3 htmlSpace str : string, [ replace : string ] => sp : string

=head3 htmlSpace str : [string], [ replace : string ] => sp : string

Convert any whitespace in str to the html C<&nbsp;> non-breaking space character.
Each whitespace characater is converted into a non-breaking space character.

If the optional string replace is supplied, then all whitespace is converted into
the string replace instead of non-breaking space.

Also replaces any dashes with &minus; so hypenation rules are not applied by the browser.

Parameters:

=over

=item* str => the string or string array reference to be converted

=item replace => optional string to replace whitespace with

=back

Returns:

=over

=item* sp => the converted string

=back

=cut
sub htmlSpace {
	# Use a regular expression with \s for whitespace
	my $str = shift;
	my $replace = shift || '&nbsp;';
	
	my @result;
	if (ref($str) eq "ARRAY") {
		foreach my $s (@{$str}) {
			$s =~ s/\s/$replace/g;
			$s =~ s/-/&minus;/g;
			push @result, $s;
		}
	} else {
		$str =~ s/\s/$replace/g if $str;
		$str =~ s/-/&minus;/g if $str;
		push @result, $str;
	}
	
	return wantarray ? @result : $result[0];
}

=head3 formatLog log : string => flog : string

Format the provided log by translating various strings
into characters, and some characters into strings.
This makes the log display properly in html.

Parameters:

=over

=item* log => the log to format

=back

Returns:

=over

=item* flog => the formatted log

=back

=cut
sub formatLog {
	my $log = shift;
	
	if ($log) {
		$log =~ s/</&lt;/g;
		$log =~ s/>/&gt;/g;
		$log =~ s/NEWLINE/<br>/g;
		$log =~ s/SEMICOLON/;/g;
		$log =~ s/BACKSLASH/\\/g;
	}
	
	return $log;
}

# Return true so this file can be required
1;
