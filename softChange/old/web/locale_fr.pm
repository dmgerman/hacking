#!/usr/bin/perl -w

package locale_fr;
use strict;

=head1 French localization package : C<locale_fr.pm>

=head2 Uses: C<none>

=head2 Requires: C<none>

=head2 Pragmas: C<constant>, C<strict>

This package provides the French localized strings and phrases
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
	'' => 'D&eacute;faut',
	'en' => 'Anglais',
	'fr' => 'Fran&ccedil;ais'
};

=head3 The terms for the different documentations that may be available

=over 

=item* constant termUserManual : string

=item* constant termProgManual : string

=item* constant termPOD : string

=back

=cut
use constant termUserManual => "Manuel d'Utilisateur";
use constant termProgManual => 'Manuels de Programmeurs';
use constant termPOD => 'Documentation DE COSSE';

=head3 The word to use to refer to databases

=over

=item* constant termDatabase : string

=back

=cut
use constant termDatabase => 'Projet';

=head3 The word to use to refer to developers

=over

=item* constant termAllDevelopers : string

=item* constant termDeveloperPlural : string

=back

=cut
use constant termAllDevelopers => 'Tous les Auteurs';
use constant termDeveloperPlural => 'Auteurs';

=head3 The word to use for dates

=over

=item* constant termAllDates : string

=back

=cut
use constant termAllDates => 'Toutes les Dates';

=head3 The words for long and short date formats

=over

=item* constant termLong : string

=item* constant termShort : string

=back

=cut
use constant termLong => 'Long';
use constant termShort => 'Court';

=head3 The word to use for continue

=over

=item* constant termContinue : string

=back

=cut
use constant termContinue => 'Continuer';

=head3 The words for lines

=over

=item* constant termLine : string

=item* constant termLinePlural : string

=back

=cut
use constant termLine => 'Ligne';

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
use constant termPrevious => 'Pr&eacute;c&eacute;dent';
use constant termNext => 'Prochain';

=head3 The word to use for rows

=over

=item* constant termRowPlural : string

=back

=cut
use constant termRowPlural => 'Rang&eacute;es';

=head3 The word to use for None

=over

=item* constant termNone : string

=back

=cut
use constant termNone => 'Aucun';

=head2 Date formatting text

=cut

=head3 The words to use for month names. These DO have accents.

=over

=item* constant termMonthNames : hash ref

=back

=cut
use constant termMonthNames => {
	'Janvier' => 1,
	'F&eacute;vrier' => 2,
	'Mars' => 3,
	'Avril' => 4,
	'Mai' => 5,
	'Juin' => 6,
	'Juillet' => 7,
	'Ao&ucirc;t' => 8,
	'Septembre' => 9,
	'Octobre' => 10,
	'Novembre' => 11,
	'D&eacute;cembre' => 12
};

=head3 The month names for ui elements. These do NOT have accents.

=over

=item* constant uiMonthNames : hash ref

=back

=cut
use constant uiMonthNames => {
	'Janvier' => 1,
	'Fevrier' => 2,
	'Mars' => 3,
	'Avril' => 4,
	'Mai' => 5,
	'Juin' => 6,
	'Juillet' => 7,
	'Aout' => 8,
	'Septembre' => 9,
	'Octobre' => 10,
	'Novembre' => 11,
	'Decembre' => 12
};

=head3 The textual name of each element

=over

=item* constant dateTexts : array

=back

=cut
use constant dateTexts => (
	'Mois',
	'Jour',
	'Ann&eacute;e'
);

=head3 The order of the date elements

=over

=item* constant dateOrder : array

=back

=head4 Note: 0 is month, 1 is day, 2 is year

=head4 Note: French order is day, month, year

=cut
use constant dateOrder => (
	1,
	0,
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
	' '
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

=head4 Note: French order is hour, minute, second

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
	"Erreur de Date : La date commen&ccedil;ante doit avoir lieu ou avant la date de fin.";

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
	
	my $shortFormat = $startDate =~ /\d\d\/\d\d\/\d\d/;
	
	return
		"Erreur de Date: La date ".
		($startOrEnd ? "commen&ccedil;ante " : "de fin ").
		"doit ".
		($shortFormat ? "&eacute;tre " : "avoir lieu ").
		"entre $startDate et $endDate.";
}

=head3 Error to report when an unimplemented page is displayed

=over

=item* constant notImplementedPhrase : string

=back

=head4 Note: This message is in three parts, separated by newlines.

=cut
use constant notImplementedPhrase =>
	"Page Unimplemented\n".
	"Cette page repr&eacute;sente un &eacute;tat inadmissible.\n".
	"Si vous ne changiez pas le URL manuellement, alors il y a une erreur dans le softChange.";	

=head2 Formatting constants and functions for html query results

=cut

=head3 Database list

=over

=item* constant colsQueryDBList : array

=back

=cut
use constant colsQueryDBList => (
	'#',
	'Projet'
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
	$server = $server ? " sur $server" : "";
	
	return "Il n'y a aucun commencer disponible de bases de donn&eacute;es &agrave; ".
	"l'excentrage $server accessible par l'utilisateur $user cela peut &ecirc;tre ".
	"employ&eacute; par le softChange."
}

=head3 Column titles for By Month

=over

=item* constant colsQueryMonth : array

=back

=cut
use constant colsQueryMonth => (
	'#',
	'Mois',
	'Compte'
);

=head3 emptyQueryMonth (offset : string, dateStart : string, dateEnd : string, devList : (string)) => string

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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune DDMs commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
}

=head3 Column titles for MR Detail

=over

=item* constant colsQueryMRDetail : array

=back

=cut
use constant colsQueryMRDetail => (
	'#',
	'DDM ID',
	'Auteur',
	'Dossiers Modifi&eacute;s',
	'Date',
	'Temps',
	'Notation'
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
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune DDMs pendant le mois $month ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
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
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune DDMs &egrave;crit par $author ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
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
		'Nom de Dossier',
		'ID de R&eacute;vision',
		'Lignes Suppl&eacute;mentaires',
		'Lignes Enlev&eacute;es',
		'Lignes Total',
		'&Eacute;tat'
	);
	
	push @columns,
		'M&eacute;thodes Suppl&eacute;mentaires',
		'M&eacute;thodes Enlev&eacute;es',
		'M&eacute;thodes Ensuite',
		'M&eacute;thodes Avant'
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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucun dossier dans n'importe quel DDM avec le $mrid d'identification ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
}

=head3 Column titles for MR ID Statictics

=over

=item* constant colsQueryMRIDStats : array

=back

=cut
use constant colsQueryMRIDStats => (
	'#',
	'Code Source?',
	'Dossiers',
	'Dossiers Suppl&eacute;mentaires',
	'Dossiers Enlev&eacute;s',
	'M&eacute;thodes Suppl&eacute;mentaires',
	'M&eacute;thodes Enlev&eacute;es'
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

=item* There are no stats for any MR with the id jill:2003/03/23 03:10:21 starting at offset 1.

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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune statistique pour n'importe quelle DDM avec le $mrid d'identification$endPhrase.";
}

=head3 Column titles for By Author

=over

=item* constant colsQueryAuthor : array

=back

=cut
use constant colsQueryAuthor => (
	'#',
	'Auteur',
	'Compte',
	'Premi&agrave;re Date',
	'Derni&egrave;re Date'
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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucun auteur ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
}

=head3 Column titles for By File

=over

=item* constant colsQueryFile : array

=back

=cut
use constant colsQueryFile => (
	'#',
	'Nom de Dossier',
	'R&eacute;visions',
	'Auteur',
	'Premi&egrave;re Date',
	'Derni&egrave;re Date'
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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucun dossier ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
}

=head3 Column titles for By File Name

=over

=item* constant colsQueryFileName : array

=back

=cut	
use constant colsQueryFileName => (
	'#',
	'DDM ID',
	'Auteur',
	'ID de R&eacute;vision',
	'Lignes Suppl&eacute;mentaire',
	'Lignes Enlev&eacute;',
	'Lignes Abs',
	'&Eacute;tat',
	'Date',
	'Temps',
	'Notation'
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
		$dateStart ne hardcode->cookieDefaultValue ?
		($dateStart eq $dateEnd ?
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune DDMs pour n'importe quel dossier appel&eacute; $file ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
}

=head3 Column titles for By Bugzilla

=over

=item* constant colsQueryBugzilla : array

=back

=cut
use constant colsQueryBugzilla => (
	'#',
	'DDM ID',
	'Bogues',
	'Date',
	'Notation'
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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune difficult&eacute; de bogue de Bugzilla ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
}


=head3 Column titles for Search

=over

=item* constant colsQuerySearch : array

=back

=cut
use constant colsQuerySearch => (
	'#',
	'DDM ID',
	'Auteur',
	'Date',
	'Temps',
	'Notation'
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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
	
	return "Il n'y a aucune DDMs qui satisfont votre question ".
	"commen&ccedil;ant &aacute; l'excentrage $offset$endPhrase.";
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
	
	return "Le projet $dbname ne soutient pas des questions de r&eacute;vision.";
}

=head3 emptyQueryRevision (mrid : string) => string

The phrase for an empty revision query

Parameters:

=over

=item* mrid => the mrid the query failed on

=back

Returns:

=over

=item* the localized phrase

=back

Locale Variations:

=over

=item* There are no revisions with the file name ally/init.c and revision id 1.1.

=item* There are no revisions with the file name ally/init.c and revision id 1.1 on January 1, 2004.

=item* There are no revisions with the file name ally/init.c and revision id 1.1 between January 1, 2004 and January 2, 2004.

=item* There are no revisions with the file name ally/init.c and revision id 1.1 authored by joe.

=item* There are no revisions with the file name ally/init.c and revision id 1.1 authored by any of (joe, jack).

=item* There are no revisions with the file name ally/init.c and revision id 1.1 on January 1, 2004 authored by joe.

=item* There are no revisions with the file name ally/init.c and revision id 1.1 on January 1, 2004 authored by any of (joe, jack).

=item* There are no revisions with the file name ally/init.c and revision id 1.1 between January 1, 2004 and January 2, 2004 authored by joe.

=item* There are no revisions with the file name ally/init.c and revision id 1.1 between January 1, 2004 and January 2, 2004 authored by any of (joe, jack).

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
		"sur $dateStart" :
		"entre $dateStart et $dateEnd") :
		"";
	
	my $devStr = join ", ", @devList;
	
	my $devPhrase =
		$devList[0] ne hardcode->cookieDefaultValue ?
		"&egrave;crit par ".
		(@devList > 1 ? "quels de ($devStr)" : "$devStr") :
		"";
		
	my $endPhrase =
		($datePhrase ? " $datePhrase" : "").
		($devPhrase ? " $devPhrase" : "");
		
	return "Il n'y a aucune r&eacute;vision avec le nom de dossier $file et ".
	"l'identification $revid de r&eacute;vision$endPhrase.";
}

=head3 Column titles for Revision Details

=over

=item* constant colsRevisionDetails : array

=back

=cut
use constant colsRevisionDetails => (
	'#',
	'Nom de Dossier',
	'R&eacute;vision',
	'R&eacute;vision Pr&eacute;c&eacute;dente',
	'Prochaine R&eacute;vision',
	'Lignes Suppl&eacute;mentaires',
	'Lignes Enlev&eacute;es',
	'Longueur de Diff'
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
		
	return "Il n'y a aucune r&eacute;vision pour n'importe quelle DDM avec le nom de dossier $filename et l'identification $revid de r&eacute;vision.";
}

=head3 Column titles for Revision Definitions outer table

=over

=item* constant colsRevisionDefsOuter : array

=back

=cut
use constant colsRevisionDefsOuter => (
	'Enlev&eacute;',
	'Suppl&eacute;mentaire'
);

=head3 Column titles for Revision Definitions

=over

=item* constant colsRevisionDefs : array

=back

=cut
use constant colsRevisionDefs => (
	'#',
	'Nom',
	'Type'
);

=head3 Table titles for clean and original Revision Differences

=over

=item* constant cleanDiffsTitle : string

=item* constant originalDiffsTitle : string

=back

=cut
use constant cleanDiffsTitle => "Diff&eacute;rences en code source propre";
use constant originalDiffsTitle => "Diff&eacute;rences en code source original";

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
	my $previd = shift;
	my $revid = shift;
		
	return (
		"#",
		"Avant ($previd)",
		"Apr&egrave;s ($revid)"
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
	'project' => 'Choisissez Un Projet',
	'byMonth' => 'Demandes de Modification Par Month',
	'byAuthor' => 'Modification Requests By Author',
	'byFileName' => 'Demandes de Modification Par Author',
	'byBugzilla' => 'Demandes de Modification Par Nombre de Bogue de Bugzilla',
	'search' => 'Demandes de Modification de Recherche',
	'revision' => 'D&eacute;tails de R&eacute;vision'
};

=head3 The url text to use for the By Month, By Author, etc. links

=over

=item* constant titleURLTexts : hash ref

=back

=cut
use constant titleURLTexts => {
	'project' => 'Changer Projet',
	'byMonth' => 'Par Mois',
	'byAuthor' => 'Par Auteur',
	'byFileName' => 'Par Nom de Dossier',
	'byBugzilla' => 'Par le Nombre de Bogue de Bugzilla',
	'search' => 'Rechercher'
};

=head3 The text to use for the time range and author list

=over

=item* constant textTimeRange : string

=item* constant textAuthorList : string

=back

=cut
use constant textTimeRange => 'La Cha&icirc;ne de Temps Est:';
use constant textAuthorList => 'Les Auteurs Sont:';

=head3 The preferences title

=over

=item* constant prefsTitle : string

=back

=cut
use constant prefsTitle => 'Pr&eacute;f&eacute;rences';

=head3 The reset title

=over

=item* constant resetTitle : string

=back

=cut
use constant resetTitle => 'Remise';

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
	
	return "DDMs pendant le mois $month.";
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
	
	return "DDMs &egrave;crit par '$author'";
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
	
	return "DDMs pour le dossier '$file'";
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
	
	return "D&eacute;tails pour l'ID $mrid de DDM.";
}

=head3 The search results title

=over

=item* constant searchResultsTitle : string

=back

=cut
use constant searchResultsTitle => 'R&eacute;sultats De Recherche';

=head3 searchMRIDTitle (mrid : string) => string

The search mrid details title

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
	
	return "D&eacute;tails pour l'ID $mrid de DDM.";
}

=head3 The MRID title

=over

=item* constant MRIDTitle : string

=back

=cut
use constant MRIDTitle => 'dossiers dans DDM';

=head3 The MRID stats title

=over

=item* constant MRIDStatsTitle : string

=back

=cut
use constant MRIDStatsTitle => 'Statistiques de DDM';

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
	
	return "D&eacute;tails pour la r&eacute;vision '$revid'";
}

=head3 The definition differences title

=over

=item* constant revisionDefsTitle : string

=back

=cut
use constant revisionDefsTitle => 'Diff&eacute;rences dans les D&eacute;finitions';

=head2 Search form interface text

=cut

=head3 The explanatory phrase at the beginning

=over

=item* constant searchExplainPhrase : string

=back

=cut
use constant searchExplainPhrase => 
	'&Eacute;crivez vos crit&egrave;res de recherche ci-dessous. '.
	'Vous pouvez employer des expressions r&eacute;guli&egrave;res de POSIX dans '.
	'n\'importe laquelle de ces bo&icirc;tes. '.
	'La {bo&icirc;te d\'expression exacte} est cas-sensible, '.
	'le reste des bo&icirc;tes sont cas-peu sensible. '.
	'Quelques caract&egrave;res sont stock&eacute;s comme ordres des caract&egrave;res, comme suit: '.
	'Caract&eacute;res NL (\'\n\') sont stock&eacute;s comme NEWLINE. '.
	'Points-virgule (\';\') sont stock&eacute;s comme SEMICOLON. '.
	'Antislashs (\'\\\') sont stock&eacute;s comme BACKSLASH.';

=head3 The titles for the boxes to enter data into

=over

=item* constant searchTextPhrases : array

=back

=head4 Note: curly braces delimit bold text

=cut
use constant searchTextPhrases => (
	'avec {tous} des mots',
	'avec {expression exacte}',
	'avec {au moins un} des mots',
	'{en dehors} quels des mots'
);

=head3 The titles for the Search URL

=over

=item* constant titleURLDoSearch : string

=back

=cut
use constant titleURLDoSearch => 'Recherche';

=head2 Preferences form interface text

=cut

=head3 The phrase explaining there are more details when a project has been chosen

=over

=item* constant prefsMoreDetailsText : string

=back

=cut
use constant prefsMoreDetailsText =>
	"Il y a plus de pr&eacute;f&eacute;rences disponibles apr&egrave;s ".
	"qu'un projet ait &eacute;t&eacute; choisi.";

=head3 The phrase explaining some preferences are forgotten

=over

=item* constant prefsShortTermText : string

=back

=cut
use constant prefsShortTermText =>
	'On NE se rappellera pas les pr&eacute;f&eacute;rences suivantes '.
	'quand vous stoppez votre browser:';

=head3 Select one or more authors text

=over

=item* constant prefsDeveloperListText : string

=back

=cut
use constant prefsDeveloperListText => 'Choisissez un ou plusieurs auteurs:';

=head3 Select a date range text

=over

=item* constant prefsDateRangeText : string

=back

=cut
use constant prefsDateRangeText => 'Choisissez une gamme de date:';

=head3 Word for From

=over

=item* constant prefsDateFromText : string

=back

=cut
use constant prefsDateFromText => 'De:';

=head3 Word for To

=over

=item* constant prefsDateToText : string

=back

=cut
use constant prefsDateToText => '&Agrave;:';

=head3 Phrase explaining some preferences are remembered

=over

=item* constant prefsLongTermText : string

=back

=cut
use constant prefsLongTermText =>
	'On se RAPPELLERA les pr&eacute;f&eacute;rences suivantes quand '.
	'vous stoppez votre browser:';

=head3 Max Rows text

=over

=item* constant prefsMaxRowsText : string

=back

=cut
use constant prefsMaxRowsText => 'Rang&eacute;es Maximum:';

=head3 Date Format text

=over

=item* constant prefsDateFormatText : string

=back

=cut
use constant prefsDateFormatText => 'Format de Date:';

=head3 The following constants are submit button texts, they have to NOT have accents

=over

=item* constant titleButtonCancel : string

=item* constant titleButtonSetPreferences : string

=back

=cut
use constant titleButtonCancel => 'Annuler';
use constant titleButtonSetPreferences => 'Placez les Preferences';

=head2 Success page text

=cut

=head3 Successfully updated phrase

=over

=item* constant prefsUpdated : string

=back

=cut
use constant prefsUpdated => 'Les pr&eacute;f&eacute;rences ont &eacute;t&eacute; mises &agrave; jour.';

=head3 Start date phrase

=over

=item* constant prefsStartDate : string

=back

=cut
use constant prefsStartDate => 'Commen&ccedil;ant Date: ';

=head3 End date phrase

=over

=item* constant prefsEndDate : string

=back

=cut
use constant prefsEndDate => 'Date de Fin: ';

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
	
	return $flag ? "vrai" : "faux";
}

1;
