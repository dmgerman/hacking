#!/usr/bin/perl -w

package locale_en;
use strict;

=head1 English localization package : C<locale_en.pm>

=head2 Uses: C<none>

=head2 Requires: C<none>

=head2 Pragmas: C<constant>, C<strict>

This package provides the English localized strings and phrases
for use by softChange. The C<hardcode::language()> function imports
all functions and constants contained in this package.

=head2 Terminology

Map a database or programming term to a user term

=cut

=head3 The set of languages currently supported, written in French

=over

=item* constant termLanguages : hash ref

=back

=cut
use constant termLanguages => {
	'' => 'Default',
	'en' => 'English',
	'fr' => 'French'
};

=head3 The terms for the different documentations that may be available

=over 

=item* constant termUserManual : string

=item* constant termProgManual : string

=item* constant termPOD : string

=back

=cut
use constant termUserManual => 'User Manual';
use constant termProgManual => 'Programmers Manual';
use constant termPOD => 'POD Documentation';

=head3 The word to use to refer to databases

=over

=item* constant termDatabase : string

=back

=cut
use constant termDatabase => 'Project';

=head3 The word to use to refer to developers

=over

=item* constant termAllDevelopers : string

=item* constant termDeveloperPlural : string

=back

=cut
use constant termAllDevelopers => 'All Authors';
use constant termDeveloperPlural => 'Authors';

=head3 The word to use for dates

=over

=item* constant termAllDates : string

=back

=cut
use constant termAllDates => 'All Dates';

=head3 The words for long and short date formats

=over

=item* constant termLong : string

=item* constant termShort : string

=back

=cut
use constant termLong => 'Long';
use constant termShort => 'Short';

=head3 The word to use for continue

=over

=item* constant termContinue : string

=back

=cut
use constant termContinue => 'Continue';

=head3 The words for lines

=over

=item* constant termLine : string

=back

=cut
use constant termLine => 'Line';

=head3 The word for total

=over

=item* constant termTotal : string

=back

=cut
use constant termTotal => 'Total';

=head3 The words for previous and next

=over

=item* constant termPrevious : string

=item* constant termNext : string

=back

=cut
use constant termPrevious => 'Previous';
use constant termNext => 'Next';

=head3 The word to use for rows

=over

=item* constant termRowPlural : string

=back

=cut
use constant termRowPlural => 'Rows';

=head3 The word to use for None

=over

=item* constant termNone : string

=back

=cut
use constant termNone => 'None';

=head2 Date formatting text

=cut

=head3 The words to use for month names. These DO have accents.

=over

=item* constant termMonthNames : hash ref

=back

=cut
use constant termMonthNames => {
	'January' => 1,
	'February' => 2,
	'March' => 3,
	'April' => 4,
	'May' => 5,
	'June' => 6,
	'July' => 7,
	'August' => 8,
	'September' => 9,
	'October' => 10,
	'November' => 11,
	'December' => 12
};

=head3 The month names for ui elements. These do NOT have accents.

=over

=item* constant uiMonthNames : hash ref

=back

=cut
use constant uiMonthNames => {
	'January' => 1,
	'February' => 2,
	'March' => 3,
	'April' => 4,
	'May' => 5,
	'June' => 6,
	'July' => 7,
	'August' => 8,
	'September' => 9,
	'October' => 10,
	'November' => 11,
	'December' => 12
};

=head3 The textual name of each element

=over

=item* constant dateTexts : array

=back

=cut
use constant dateTexts => (
	'Month',
	'Day',
	'Year'
);

=head3 The order of the date elements

=over

=item* constant dateOrder : array

=back

=head4 Note: 0 is month, 1 is day, 2 is year

=head4 Note: English order is month, day, year

=cut
use constant dateOrder => (
	0,
	1,
	2
);

=head3 The separators to use between elements of a long formatted date

=over

=item* constant dateLongSeparators : array

=back

=head4 Note: Be sure to use &minus; instead of just a minus sign, otherwise the browser will treat the minus as a hyphen and change the formatting.

=cut
use constant dateLongSeparators => (
	' ',
	', '
);

=head3 The separators to use between elements of a short formatted date

=over

=item* constant dateShortSeparators : array

=back

=head4 Note: Be sure to use &minus; instead of just a minus sign, otherwise the browser will treat the minus as a hyphen and change the formatting.

=cut
use constant dateShortSeparators => (
	'/',
	'/'
);

=head3 The order of the time elements

=over

=item* constant timeOrder : array

=back

=head4 Note: 0 is hour, 1 is minute, 2 is seconds

=head4 Note: English order is hour, minute, second

=cut
use constant timeOrder => (
	0,
	1,
	2
);

=head3 The separators to use between elements of time

=over

=item* constant timeSeparators : array

=back

=head4 Note: Be sure to use &minus; instead of just a minus sign, otherwise the browser will treat the minus as a hyphen and change the formatting.

=cut
use constant timeSeparators => (
	':',
	':'
);

=head2 Formatting data and functions for date errors

=over

=item* constant dateStartAfterEnd : string

=back

=cut
use constant dateStartAfterEnd =>
	"Date Error: The starting date must be on or before the ending date.";

=head3 dateOutsideRange (startDate : string, endDate : string, [ startOrEnd : bool ]) => string

The phrase for when the starting or ending date is outside the usable range.

Parameters:

=over

=item* startDate => the earliest usable date, preformatted for locale

=item* endDate => the latest usable date, preformatted for locale

=item* startOrEnd => true if starting date, false if ending date

=back

Returns:

=over

=item* The localized phrase

=back

Locale Variations:

=over

=item* Date Error: The starting date must be between March 2, 2000 and August 4, 2003.

=item* Date Error: The ending date must be between March 2, 2000 and August 4, 2003.

=item* Date Error: The starting date must be between 03/02/2000 and 08/04/2003.

=item* Date Error: The ending date must be between 03/02/2000 and 08/04/2003.

=back

=cut
sub dateOutsideRange {
	my $startDate = shift;
	my $endDate = shift;
	my $startOrEnd = shift;
	
	return
		"Date Error: The ".
		($startOrEnd ? "starting " : "ending ").
		"date must be between $startDate and $endDate.";
}

=head3 Error to report when an unimplemented page is displayed

=over

=item* constant notImplementedPhrase : string

=back

=head4 Note: This message is in three parts, separated by newlines.

=cut
use constant notImplementedPhrase =>
	"Unimplemented Page\n".
	"This page represents an invalid state.\n".
	"If you did not alter the URL manually, then there is an error in softChange.";

=head2 Formatting constants and functions for html query results

=cut

=head3 Database list

=over

=item* constant colsQueryDBList : array

=back

=cut
use constant colsQueryDBList => (
	'#',
	'Project'
);

=head3 emptyQueryDBList (offset : string, server : string, user : string) => string

The phrase for an empty database list

Parameters:

=over

=item* offset => the SQL offset

=item* server => the name of the server being connected to

=item* user => the user name used to connect to the server

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over 

=item* There are no databases available starting at offset 1 accessible by the user joe that can be used by softChange.

=item* There are no databases available starting at offset 1 on server.company.com accessible by the user joe that can be used by softChange.

=back

=cut
sub emptyQueryDBList {
	my %parms = (@_);
	my $offset = $parms{-offset};
	my $server = $parms{-specific}->[0];
	my $user = $parms{-specific}->[1];
	
	# If the server is blank, don't mention the server name
	$server = $server ? " on $server" : "";
	
	return "There are no databases available starting at offset $offset$server ".
	"accessible by the user $user that can be used by softChange.";
}

=head3 Column titles for By Month

=over

=item* constant colsQueryMonth : array

=back

=cut
use constant colsQueryMonth => (
	'#',
	'Month',
	'Count'
);

=head3 emptyQueryMonth (offset : string, singleDate : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by month

Parameters:

=over

=item* offset => the SQL offset

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no MRs starting at offset 1.

=item* There are no MRs starting at offset 1 on January 1, 2004.

=item* There are no MRs starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no MRs starting at offset 1 authored by joe.

=item* There are no MRs starting at offset 1 authored by any of (joe, jack).

=item* There are no MRs starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no MRs starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no MRs starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no MRs starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryMonth {
	my %parms = (@_);
	my $offset = $parms{-offset};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no MRs starting at offset $offset$endPhrase.";
}

=head3 Column titles for MR Detail

=over

=item* constant colsQueryMRDetail : array

=back

=cut
use constant colsQueryMRDetail => (
	'#',
	'MR ID',
	'Author',
	'Files Modified',
	'Date',
	'Time',
	'Description'
);

=head3 emptyQueryMonthDetail (month : string, offset : string, dateSingle : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by month detail

Parameters:

=over

=item* month => the formatted month

=item* offset => the SQL offset

=item* dateSingle => a single date to override the date range, or 'any'

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no MRs during the month January, 2004 starting at offset 1.

=item* There are no MRs during the month January, 2004 starting at offset 1 on January 1, 2004.

=item* There are no MRs during the month January, 2004 starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no MRs during the month January, 2004 starting at offset 1 authored by joe.

=item* There are no MRs during the month January, 2004 starting at offset 1 authored by any of (joe, jack).

=item* There are no MRs during the month January, 2004 starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no MRs during the month January, 2004 starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no MRs during the month January, 2004 starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no MRs during the month January, 2004 starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryMonthDetail {
	my %parms = (@_);
	my $month = $parms{-specific}->[0];
	my $offset = $parms{-offset};
	my $dateSingle = $parms{-dateSingle};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateSingle ne hardcode->cookieDefaultValue ?
		"on $dateSingle" :
		($dateStart ne hardcode->cookieDefaultValue ?
			($dateStart eq $dateEnd ?
			"on $dateStart" :
			"between $dateStart and $dateEnd") :
			""
		);
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no MRs during the month $month ".
	"starting at offset $offset$endPhrase.";
}

=head3 emptyQueryAuthorDetail (author : string, offset : string, dateSingle : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by author detail

Parameters:

=over

=item* author => the name of the author

=item* offset => the SQL offset

=item* dateSingle => a single date to override the date range, or 'any'

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no MRs authored by jill starting at offset 1.

=item* There are no MRs authored by jill starting at offset 1 on January 1, 2004.

=item* There are no MRs authored by jill starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no MRs authored by jill starting at offset 1 authored by joe.

=item* There are no MRs authored by jill starting at offset 1 authored by any of (joe, jack).

=item* There are no MRs authored by jill starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no MRs authored by jill, 2004 starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no MRs authored by jill, 2004 starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no MRs authored by jill, 2004 starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut	
sub emptyQueryAuthorDetail {
	my %parms = (@_);
	my $author = $parms{-specific}->[0];
	my $offset = $parms{-offset};
	my $dateSingle = $parms{-singleDate};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateSingle ne hardcode->cookieDefaultValue ?
		"on $dateSingle" :
		($dateStart ne hardcode->cookieDefaultValue ?
			($dateStart eq $dateEnd ?
			"on $dateStart" :
			"between $dateStart and $dateEnd") :
			""
		);
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no MRs authored by $author ".
	"starting at offset $offset$endPhrase.";
}

=head3 colsQueryMRIDDetail (deltas : bool) => columns : (string)

Column titles for MRID Detail

Parameters:

=over

-item* deltas => true if the methoddeltas table is supported by the project

=back

Returns:

=over

=item* columns => the columns of the mrid details page, possibly including methoddeltas columns

=back

=cut
sub colsQueryMRIDDetail {
	my $deltas = shift;
	
	my @columns = (
		'#',
		'File Name',
		'Revision ID',
		'Lines Added',
		'Lines Removed',
		'Lines Total',
		'State'
	);
	
	push @columns,
		'Methods Added',
		'Methods Removed',
		'Methods After',
		'Methods Before'
		if $deltas;
	
	return @columns;
}

=head3 emptyQueryMRIDDetail (mrid : string, offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by mrid

Parameters:

=over

=item* mrid => the selected MRID

=item* offset => the SQL offset

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1.

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 on January 1, 2004.

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 authored by joe.

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 authored by any of (joe, jack).

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no files in any MR with the id jill:2003/03/23 03:10:21 starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryMRIDDetail {
	my $mrid = shift;
	my $offset = shift;
	my $dateStart = shift;
	my $dateEnd = shift;
	my @devList = shift;
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no files in any MR with the id $mrid ".
	"starting at offset $offset$endPhrase.";
}

=head3 Column titles for MR ID Statictics

=over

=item* constant colsQueryMRIDStats : array

=back

=cut
use constant colsQueryMRIDStats => (
	'#',
	'Source Code?',
	'Files',
	'Files Added',
	'Files Removed',
	'Methods Added',
	'Methods Removed'
);

=head3 emptyQueryMRIDStats (mrid : string) => string

The phrase for an empty query for mrid stats

Parameters:

=over

=item* mrid => the selected MRID

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no stats for any MR with the id jill:2003/03/23 03:10:21.

=back

=cut
sub emptyQueryMRIDStats {
	my $mrid = shift;
	my $dateStart = shift;
	my $dateEnd = shift;
	my @devList = shift;
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "There are no statistics for any MR with the id $mrid$endPhrase.";
}

=head3 Column titles for By Author

=over

=item* constant colsQueryAuthor : array

=back

=cut
use constant colsQueryAuthor => (
	'#',
	'Author',
	'Count',
	'First Date',
	'Last Date'
);

=head3 emptyQueryAuthor (offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by author

Parameters:

=over

=item* offset => the SQL offset

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no authors starting at offset 1.

=item* There are no authors starting at offset 1 on January 1, 2004.

=item* There are no authors starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no authors starting at offset 1 authored by joe.

=item* There are no authors starting at offset 1 authored by any of (joe, jack).

=item* There are no authors starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no authors starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no authors starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no authors starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryAuthor {
	my %parms = (@_);
	my $offset = $parms{-offset};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no authors ".
	"starting at offset $offset$endPhrase.";
}

=head3 Column titles for By File

=over

=item* constant colsQueryFile : array

=back

=cut
use constant colsQueryFile => (
	'#',
	'File Name',
	'Revisions',
	'Author',
	'First Date',
	'Last Date'
);

=head3 emptyQueryFile (offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by file

Parameters:

=over

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no files starting at offset 1.

=item* There are no files starting at offset 1 on January 1, 2004.

=item* There are no files starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no files starting at offset 1 authored by joe.

=item* There are no files starting at offset 1 authored by any of (joe, jack).

=item* There are no files starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no files starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no files starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no files starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryFile {
	my %parms = (@_);
	my $offset = $parms{-offset};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no files ".
	"starting at offset $offset$endPhrase.";
}

=head3 Column titles for By File Name

=over

=item* constant colsQueryFileName : array

=back

=cut	
use constant colsQueryFileName => (
	'#',
	'MR ID',
	'Author',
	'Revision ID',
	'Lines Added',
	'Lines Removed',
	'Lines Abs',
	'State',
	'Date',
	'Time',
	'Description'
);

=head3 emptyQueryFileName (file : string, offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by month detail

Parameters:

=over

=item* file => the name of the file

=item* offset => the SQL offset

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no MRs for any file named art/bybug.png starting at offset 1.

=item* There are no MRs for any file named art/bybug.png starting at offset 1 on January 1, 2004.

=item* There are no MRs for any file named art/bybug.png starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no MRs for any file named art/bybug.png starting at offset 1 authored by joe.

=item* There are no MRs for any file named art/bybug.png starting at offset 1 authored by any of (joe, jack).

=item* There are no MRs for any file named art/bybug.png starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no MRs for any file named art/bybug.png starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no MRs for any file named art/bybug.png starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no MRs for any file named art/bybug.png starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryFileName {
	my %parms = (@_);
	my $file = $parms{-specific}->[0];
	my $offset = $parms{-offset};
	my $dateSingle = $parms{-singleDate};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateSingle ne hardcode->cookieDefaultValue ?
		"on $dateSingle" :
		($dateStart ne hardcode->cookieDefaultValue ?
			($dateStart eq $dateEnd ?
			"on $dateStart" :
			"between $dateStart and $dateEnd") :
			""
		);
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no MRs for any file named $file ".
	"starting at offset $offset$endPhrase.";
}

=head3 Column titles for By Bugzilla

=over

=item* constant colsQueryBugzilla : array

=back

=cut
use constant colsQueryBugzilla => (
	'#',
	'MR ID',
	'Bugs',
	'Date',
	'Description'
);

=head3 emptyQueryBugzilla (offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by bugzilla

Parameters:

=over

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no Bugzilla bug fixes starting at offset 1.

=item* There are no Bugzilla bug fixes starting at offset 1 on January 1, 2004.

=item* There are no Bugzilla bug fixes starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no Bugzilla bug fixes starting at offset 1 authored by joe.

=item* There are no Bugzilla bug fixes starting at offset 1 authored by any of (joe, jack).

=item* There are no Bugzilla bug fixes starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no Bugzilla bug fixes starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no Bugzilla bug fixes starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no Bugzilla bug fixes starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryBugzilla {
	my %parms = (@_);
	my $offset = $parms{-offset};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no Bugzilla bug fixes ".
	"starting at offset $offset$endPhrase.";
}

=head3 Column titles for Search

=over

=item* constant colsQuerySearch : array

=back

=cut
use constant colsQuerySearch => (
	'#',
	'MR ID',
	'Author',
	'Date',
	'Time',
	'Description'
);

=head3 emptyQuerySearch (offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

The phrase for an empty query by bugzilla

Parameters:

=over

=item* offset => the SQL offset

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no MRs that satisfy your query starting at offset 1.

=item* There are no MRs that satisfy your query starting at offset 1 on January 1, 2004.

=item* There are no MRs that satisfy your query starting at offset 1 between January 1, 2004 and January 2, 2004.

=item* There are no MRs that satisfy your query starting at offset 1 authored by joe.

=item* There are no MRs that satisfy your query starting at offset 1 authored by any of (joe, jack).

=item* There are no MRs that satisfy your query starting at offset 1 on January 1, 2004 authored by joe.

=item* There are no MRs that satisfy your query starting at offset 1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no MRs that satisfy your query starting at offset 1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no MRs that satisfy your query starting at offset 1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQuerySearch {
	my %parms = (@_);
	my $offset = $parms{-offset};
	my $dateStart = $parms{-startDate};
	my $dateEnd = $parms{-endDate};
	my @devList = @{$parms{-devList}};
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no MRs that satisfy your query ".
	"starting at offset $offset$endPhrase.";
}

=head3 revisionsNotSupported (dbname : string) => string

The phrase for a project that doesn't support revisions queries.

Parameters:

=over

=item* dbname => the name of the project

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* The project evolution does not support revision queries.

=back

=cut
sub revisionsNotSupported {
	my $dbname = shift;
	
	return "The project $dbname does not support revision queries.";
}

=head3 emptyQueryRevision (file : string, revid : string) => string

The phrase for an empty revision query

Parameters:

=over

=item* file => the file name the query failed on

=item* revid => the revision id the query failed on

=item* dateStart => the starting date of the date range, or 'any'

=item* dateEnd => the ending date of the date range

=item* devList => the list of developers

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1'.

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' on January 1, 2004.

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' between January 1, 2004 and January 2, 2004.

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' authored by joe.

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' authored by any of (joe, jack).

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' on January 1, 2004 authored by joe.

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' on January 1, 2004 authored by any of (joe, jack).

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no revisions with the file name 'ally/init.c' and revision id '1.1' between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

=back

=cut
sub emptyQueryRevision {
	my $file = shift;
	my $revid = shift;
	my $dateStart = shift;
	my $dateEnd = shift;
	my @devList = shift;
	
	my $datePhrase = 
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"on $dateStart" :
		"between $dateStart and $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"authored by ".
		(@devList > 1 ? "any of ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "There are no revisions with the file name $file and ".
	"revision id $revid$endPhrase.";
}

=head3 Column titles for Revision Details

=over

=item* constant colsRevisionDetails : array

=back

=cut
use constant colsRevisionDetails => (
	'#',
	'File Name',
	'Revision',
	'Previous Revision',
	'Next Revision',
	'Lines Added',
	'Lines Removed',
	'Diff Length'
);

=head3 emptyQueryRevisionDetails (filename : string, revid : string) => string

The phrase for an empty revision details query

Parameters:

=over

=item* filename => the filename of the query

=item* revid => the revision id of the query

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no revisions for any MR with the filename test.c and the revision id 1.18.

=back

=cut
sub emptyQueryRevisionDetails {
	my $filename = shift;
	my $revid = shift;
		
	return "There are no revisions for any MR with the filename $filename and the revision id $revid.";
}

=head3 Column titles for Revision Definitions outer table

=over

=item* constant colsRevisionDefsOuter : array

=back

=cut
use constant colsRevisionDefsOuter => (
	'Removed',
	'Added',
        'Modified',
);

=head3 Column titles for Revision Definitions

=over

=item* constant colsRevisionDefs : array

=back

=cut
use constant colsRevisionDefs => (
	'#',
	'Name',
	'Type'
);

=head3 Table titles for clean and original Revision Differences

=over

=item* constant cleanDiffsTitle : string

=item* constant originalDiffsTitle : string

=back

=cut
use constant cleanDiffsTitle => "Differences in clean source code";
use constant originalDiffsTitle => "Differences in original source code";

=head3 colsRevisionDiffs (previd : string, revid : string) => cols : (string)

The column names for the revision diffs table

Parameters:

=over

=item* previd => the prevision revision id

=item* revid => the revision id of the query

=back

Returns:

=over

=item* cols => the localized columns

=back

Locale Variations:

=over

=item* ("Before (1.1)", "After (1.2)")

=back

=cut
sub colsRevisionDiffs {
	my $previd = shift || "";
	my $revid = shift || "";
		
	return (
		"#",
		"Before ($previd)",
		"After ($revid)"
	);
}
	
=head2 Titles for URLs

=cut

=head3 The titles for the window and for displaying underneath the project title

=over

=item* constant titleNames : hash ref

=back

=cut
use constant titleNames => {
	'project' => 'Choose A Project',
	'byMonth' => 'Modification Requests By Month',
	'byAuthor' => 'Modification Requests By Author',
	'byFileName' => 'Modification Requests By File Name',
	'byBugzilla' => 'Modification Requests By Bugzilla Bug Number',
	'search' => 'Search Modification Requests',
	'revision' => 'Revision Details'
};

=head3 The url text to use for the By Month, By Author, etc. links

=over

=item* constant titleURLTexts : hash ref

=back

=cut
use constant titleURLTexts => {
	'project' => 'Change Project',
	'byMonth' => 'By Month',
	'byAuthor' => 'By Author',
	'byFileName' => 'By File Name',
	'byBugzilla' => 'By Bugzilla Bug Number',
	'search' => 'Search'
};

=head3 The text to use for the time range and author list

=over

=item* constant textTimeRange : string

=item* constant textAuthorList : string

=back

=cut
use constant textTimeRange => 'The Time Range Is:';
use constant textAuthorList => 'The Authors Are:';

=head3 The preferences title

=over

=item* constant prefsTitle : string

=back

=cut
use constant prefsTitle => 'Preferences';

=head3 The reset title

=over

=item* constant resetTitle : string

=back

=cut
use constant resetTitle => 'Reset';

=head3 byMonthDetailTitle (month : string) => string

The by month detail title

Parameters:

=over

=item* month => the formatted month string

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* MRs during the month January, 2004.

=back

=cut
sub byMonthDetailTitle {
	my $month = shift;
	
	return "MRs during the month $month";
}

=head3 byAuthorDetailTitle (author : string) => string

The by author detail title

Parameters:

=over

=item* author => the name of the author

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* MRs authored by joe.

=back

=cut
sub byAuthorDetailTitle {
	my $author = shift;
	
	return "MRs authored by '$author'";
}

=head3 byFileDetailTitle (file : string) => string

The by file detail title

Parameters:

=over

=item* file => the name of the selected file

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* MRs for the file 'art/bybug.png'.

=back

=cut
sub byFileDetailTitle {
	my $file = shift;
	
	return "MRs for the file '$file'";
}

=head3 byBugzillaMRIDTitle (mrid : string) => string

The by bugzilla mrid details title

Parameters:

=over

=item* mrid => the selected mrid

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* Details for MR ID rodrigo:1997/01/01 09:56:14.

=back

=cut
sub byBugzillaMRIDTitle {
	my $mrid = shift;
	
	return "Details for MR ID $mrid.";
}

=head3 The search results title

=over

=item* constant searchResultsTitle : string

=back

=cut
use constant searchResultsTitle => 'Search Results';

=head3 searchMRIDTitle (mrid : string) => string

The bysearch mrid details title

Parameters:

=over

=item* mrid => the selected mrid

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* Details for MR ID rodrigo:1997/01/01 09:56:14.

=back

=cut
sub searchMRIDTitle {
	my $mrid = shift;
	
	return "Details for MR ID $mrid.";
}

=head3 The MRID title

=over

=item* constant MRIDTitle : string

=back

=cut
use constant MRIDTitle => 'Files in MR';

=head3 The MRID stats title

=over

=item* constant MRIDStatsTitle : string

=back

=cut
use constant MRIDStatsTitle => 'MR Statistics';

=head3 revisionDetailsTitle (revid : string) => string

The revision details title

Parameters:

=over

=item* revid => the id of the selected revision

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* Details for the Revision '1.18'.

=back

=cut
sub revisionDetailsTitle {
	my $revid = shift;
	
	return "Details for the Revision '$revid'";
}

=head3 The definition differences title

=over

=item* constant revisionDefsTitle : string

=back

=cut
use constant revisionDefsTitle => 'Differences in the Definitions';

=head2 Search form interface text

=cut

=head3 The explanatory phrase at the beginning

=over

=item* constant searchExplainPhrase : string

=back

=cut
use constant searchExplainPhrase => 
	'Enter your search criteria below. '.
	'You may use POSIX regular expressions in any of the boxes. '.
	'The {exact phrase} box is case-sensitive, '.
	'the rest of the boxes are case-insensitive. '.
	'Some characters are stored as sequences of characters, as follows:'.
	'Newlines (\'\n\') are stored as NEWLINE. '.
	'Semicolons (\';\') are stored as SEMICOLON. '.
	'Backslashes (\'\\\') are stored as BACKSLASH.';

=head3 The titles for the boxes to enter data into

=over

=item* constant searchTextPhrases : array

=back

=head4 Note: curly braces delimit bold text

=cut
use constant searchTextPhrases => (
	'with {all} of the words',
	'with the {exact phrase}',
	'with {at least one} of the words',
	'{without} any of the words'
);

=head3 The titles for the Search URL

=over

=item* constant titleURLDoSearch : string

=back

=cut
use constant titleURLDoSearch => 'Search';

=head2 Preferences form interface text

=cut

=head3 The phrase explaining there are more details when a project has been chosen

=over

=item* constant prefsMoreDetailsText : string

=back

=cut
use constant prefsMoreDetailsText =>
	'There are more preferences available after a project has been chosen.';

=head3 The phrase explaining some preferences are forgotten

=over

=item* constant prefsShortTermText : string

=back

=cut
use constant prefsShortTermText =>
	'The following preferences will NOT be remembered when you quit your browser:';

=head3 Select one or more authors text

=over

=item* constant prefsDeveloperListText : string

=back

=cut
use constant prefsDeveloperListText => 'Select one or more authors:';

=head3 Select a date range text

=over

=item* constant prefsDateRangeText : string

=back

=cut
use constant prefsDateRangeText => 'Select a date range:';

=head3 Word for From

=over

=item* constant prefsDateFromText : string

=back

=cut
use constant prefsDateFromText => 'From:';

=head3 Word for To

=over

=item* constant prefsDateToText : string

=back

=cut
use constant prefsDateToText => 'To:';

=head3 Phrase explaining some preferences are remembered

=over

=item* constant prefsLongTermText : string

=back

=cut
use constant prefsLongTermText =>
	'The following preferences WILL be remembered when you quit your browser:';

=head3 Max Rows text

=over

=item* constant prefsMaxRowsText : string

=back

=cut
use constant prefsMaxRowsText => 'Maximum Rows:';

=head3 Date Format text

=over

=item* constant prefsDateFormatText : string

=back

=cut
use constant prefsDateFormatText => 'Date Format:';

=head3 The following constants are submit button texts, they have to NOT have accents

=over

=item* constant titleButtonCancel : string

=item* constant titleButtonSetPreferences : string

=back

=cut
use constant titleButtonCancel => 'Cancel';
use constant titleButtonSetPreferences => 'Set Preferences';

=head2 Success page text

=cut

=head3 Successfully updated phrase

=over

=item* constant prefsUpdated : string

=back

=cut
use constant prefsUpdated => 'The preferences have been updated.';

=head3 Start date phrase

=over

=item* constant prefsStartDate : string

=back

=cut
use constant prefsStartDate => 'Starting Date: ';

=head3 End date phrase

=over

=item* constant prefsEndDate : string

=back

=cut
use constant prefsEndDate => 'Ending Date: ';

=head3 booleanText (flag : bool) => text : string

Convert a boolean true/false value into text

Parameters:

=over

=item* flag => a boolean value to convert

=back

Returns:

=over

=item* text => the boolean value as text

=back

=cut
sub booleanText {
	my $flag = shift;
	
	return $flag ? "true" : "false";
}

1;
