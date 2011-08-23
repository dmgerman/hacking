#!/usr/bin/perl -w

package cookie;
use strict;
use CGI;
use hardcode;

=head1 cookie class : C<cookie.pm>

=head2 Requires: C<none>

=head2 Uses: C<CGI.pm>, C<hardcode.pm>

=head2 Pragmas: C<strict>

This class reads and writes cookies.

A single instance of cookie is enough to manage all
the cookies for a site. The cookie values are automatically
read in when the cookie object is constructed.

The string used to set all cookies is returned by the
C<getHTML()> method. The C<html> class calls this
function automatically when the C<writeHTML()> method is
called.

As a result, cookie management is as simple as constructing
a cookie object, passing the cookie to an html object in its
constructor, reading or writing the cookies as
code progresses, and calling C<writeHTML()> at the end.

=cut

=head2 Constructors

=cut

=head3 cookie (cgi : CGI)

This method queries the CGI object for cookies and ignores
all cookies except the ones hard-coded. A new cookie object
is returned with all the relevant cookie values.

Parameters:

=over

=item* cgi => CGI object

=back

=cut
sub new {
	my $class = shift;
	my $q = shift;
	
	# NOTE: Any new parameters added here also need to be
	# added to resetCookie().
	my $this = {
		'q' => $q,
		'developers' => [hardcode->cookieDefaultValue],
		'start_month' => '',
		'start_day' => '',
		'start_year' => '',
		'end_month' => '',
		'end_day' => '',
		'end_year' => ''
	};
	
	# Search the list of cookies for the ones we want
	# unless the reset operation has been chosen.
	if (! $q->param(hardcode->cgiParmResetCookie)) {
		foreach my $i ($q->cookie()) {
			$this->{$i} = $q->cookie($i)
				if (
					$i eq 'start_month' ||
					$i eq 'start_day' ||
					$i eq 'start_year' ||
					$i eq 'end_month' ||
					$i eq 'end_day' ||
					$i eq 'end_year'
				);
			@{$this->{$i}} = $q->cookie($i)
				if $i eq 'developers';
		}
	}

	# The max rows and date format should not be reset.
	$this->{'maxRows'} =
		$q->cookie('maxRows') || hardcode->cgiMaxRowsDefault;
		
	$this->{'dateFormat'} = 
		$q->cookie('dateFormat') || hardcode->dateDefaultFormat;
	
	bless $this, $class;
	return $this;
}

=head2 Accessor methods to get or set cookie properties

=cut

=head3 startMonth ([ month : int ]) => month : int

Get/Set starting month

Parameters:

=over

=item* month => The starting month number

=back

Returns:

=over

=item* month => The starting month number

=back

=cut
sub startMonth {
	my $this = shift;
	my $start = shift;
	
	$this->{'start_month'} = $start if (defined $start);
	
	return $this->{'start_month'};
}

=head3 startDay ([ day : int ]) => day : int

Get/Set starting day

Parameters:

=over

=item* day => The starting day number

=back

Returns:

=over

=item* day => The starting day number

=back

=cut
sub startDay {
	my $this = shift;
	my $start = shift;
	
	$this->{'start_day'} = $start if (defined $start);
	
	return $this->{'start_day'};
}

=head3 startYear ([ year : int ]) => year : int

Get/Set starting year

Parameters:

=over

=item* year => The starting four-digit year number

=back

Returns:

=over

=item* year => The starting four-digit year number

=back

=cut
sub startYear {
	my $this = shift;
	my $start = shift;
	
	$this->{'start_year'} = $start if (defined $start);
	
	return $this->{'start_year'};
}

=head3 endMonth ([ month : int ]) : month => int

Get/Set ending month

Parameters:

=over

=item* month => The ending month number

=back

Returns:

=over

=item* month => The ending month number

=back

=cut
sub endMonth {
	my $this = shift;
	my $end = shift;
	
	$this->{'end_month'} = $end if (defined $end);
	
	return $this->{'end_month'};
}

=head3 endDay ([ day : int ]) => day : int

Get/Set ending day

Parameters:

=over

=item* day => The ending day number

=back

Returns:

=over

=item* day => The ending day number

=back

=cut
sub endDay {
	my $this = shift;
	my $end = shift;
	
	$this->{'end_day'} = $end if (defined $end);
	
	return $this->{'end_day'};
}

=head3 endYear ([ year : int ]) => year : int

Get/Set ending year

Parameters:

=over

=item* year => The ending four-digit year number

=back

Returns:

=over

=item* year => The ending four-digit year number

=back

=cut
sub endYear {
	my $this = shift;
	my $end = shift;
	
	$this->{'end_year'} = $end if (defined $end);
	
	return $this->{'end_year'};
}

=head3 developers ([ authors : (string) ]) => authors : (string)

Get/Set list of developers

Parameters:

=over

=item* authors => An array of author names

=back

Returns:

=over

=item* authors => An array of author names

=back

=head4 Note: If there are no developers, the result will be C<('any')>

=cut
sub developers {
	my $this = shift;
	
	$this->{'developers'} = [@_] if (scalar(@_) > 0);
	$this->{'developers'} = [hardcode->cookieDefaultValue]
		if (! defined $this->{'developers'});
	
	return @{$this->{'developers'}};
}

=head3 maximumRows ([ max : int ]) => max : int

Get/Set maximum number of rows to return from queries

Parameters:

=over

=item* max => The maximum value to use

=back

Returns:

=over

=item* max => The current maximum value

=back

=cut
sub maximumRows {
	my $this = shift;
	my $max = shift;
	
	# Get the max if it isn't being set
	if (! $max) {
		$max = $this->{'maxRows'};
	}
	
	# Test against known good values for security purposes.
	# This will test both values being written, as well
	# as values being read.
	$max =~ s/://g;
	my $str = join ':', (hardcode->cgiMaxRowsValues);
	$max = hardcode->cgiMaxRowsDefault if (index $str, $max) == -1;
	
	# Always set the value to a good one
	$this->{'maxRows'} = $max;
	
	# Return the result
	return $this->{'maxRows'};
}

=head3 dateFormat ([ format : string ]) => format : string

Get/Set the date format (long or short)

Parameters:

=over

=item* format => The date format to use

=back

Returns:

=over

=item* format => The current date format

=back

=cut
sub dateFormat {
	my $this = shift;
	my $format = shift;
	
	# Set the format if it is specified
	$this->{'dateFormat'} = $format
		if defined($format);
	
	# Always return the format
	return $this->{'dateFormat'};
}

=head2 Utility functions

=cut

=head3 resetCookie ()

Reset the cookie parameters

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut

sub resetCookie {
	my $this = shift;
	
	# Don't reset the date formatting or max rows
	my @defaults = (
		{},
		[hardcode->cookieDefaultValue],
		'',
		'',
		'',
		'',
		'',
		''
	);
	
	map {$this->{$_} = shift @defaults} (
		'supported_tables',
		'developers',
		'start_month',
		'start_day',
		'start_year',
		'end_month',
		'end_day',
		'end_year'
	);
}

=head2 Utility function to convert a date into a string

=cut

=head3 getFormattedDate (date : (int)) => date : string

=head3 getFormattedDate (date : string) => date : string

Convert the given date into a properly formatted
date according to the preferences.

The first form accepts an array of integers which
represent the month, day, and year, respectively.

The second form accepts a string suitable for an
SQL query.

Parameters:

=over

=item* date => the set of integers or SQL string to format

=back

Returns:

=over

=item* date => the formatted date string

=back

=cut
sub getFormattedDate {
	my $this = shift;
	my $month;
	my $day;
	my $year;
	
	if (@_ == 1) {
		# SQL string form.
		# Leading zeroes are included in string.
		my $date = shift;
		$date =~ /(\d\d\d\d)-(\d\d)-(\d\d)/;
		($year, $month, $day) = ($1, $2, $3);
	} else {
		# Array form.
		# Have to add leading zeroes.
		($month, $day, $year) = @_;
		
		$month = "0".$month if $month < 10;
		$day = "0".$day if $day < 10;
	}
	
	my $longFormat = $this->dateFormat() == hardcode->dateLongFormat;
	my @pieces = (
		$longFormat ?
		monthName([$month]) :
		$month,
		$day,
		$longFormat ?
		$year :
		substr($year, 2, 2)
	);
	my @seps = 
		$longFormat ?
		hardcode->dateLongSeparators() :
		hardcode->dateShortSeparators();
		
	my $result = '';
	map {
		$result .= $pieces[$_].(shift @seps || '');
	} hardcode->dateOrder;
	
	return $result;
}

=head2 Get methods to convert dates into strings

=cut

=head3 getStartDate () => start : string

Parameters:

=over

=item* none

=back

Returns:

=over

=item* start => start date

=back

=head4 Note: Date string is formatted according to date format of locale

=cut
sub getStartDate {
	my $this = shift;
	
	return
		$this->startMonth() ?
		$this->getFormattedDate(
			$this->startMonth(),
			$this->startDay(),
			$this->startYear()
		) :
		hardcode->cookieDefaultValue;
}

=head3 getEndDate () => end : string

Parameters:

=over

=item* none

=back

Returns:

=over

=item* end => end date

=back

=head4 Note: Date string is formatted according to date format of locale

=cut
sub getEndDate {
	my $this = shift;
	
	return
		$this->endMonth() ?
		$this->getFormattedDate(
			$this->endMonth(),
			$this->endDay(),
			$this->endYear()
		) :
		hardcode->cookieDefaultValue;
}

=head3 getDateRange () => range : string

Parameters:

=over

=item* none

=back

Returns:

=over

=item* range => the current range of dates

=back

=head4 Note 1: Date range is formatted according to date format of locale, in C<start - end> format

=head4 Note 2: If the start and end dates are the same, then formatted as a single date

=cut
sub getDateRange {
	my $this = shift;
	
	my $start = $this->getStartDate();
	my $end = $this->getEndDate();
	
	my $result =
		$start ne $end ?
		$start.' &minus; '.$end :
		$start;
	
	return $result;
}

=head3 getSQLStartDate () => date : string

The start date in SQL-compatible format.
Leading zeroes are used for months and days that
are less than 10, so that the string is precisely
identical to what an SQL query would return.

This makes it possible to compare two such strings
in a lexicographically identical way to non-numeric
strings and get correct results.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* date => SQL date string

=back

=cut
sub getSQLStartDate {
	my $this = shift;
	
	my $month = $this->startMonth();
	$month = "0".$month if $month < 10;
	
	my $day = $this->startDay();
	$day = "0".$day if $day < 10;
	
	return
		$this->startYear().'-'.
		$month.'-'.
		$day;
}

=head3 getSQLEndDate () => date : string

The end date in SQL-compatible format.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* date => SQL date string

=back

=cut
sub getSQLEndDate {
	my $this = shift;
	
	my $month = $this->endMonth();
	$month = "0".$month if $month < 10;
	
	my $day = $this->endDay();
	$day = "0".$day if $day < 10;
	
	return
		$this->endYear().'-'.
		$month.'-'.
		$day;
}

=head2 HTML conversion functions

=cut

=head3 getHTML () => html : [string]

Function to convert all the cookies into html data

Parameters:

=over

=item* none

=back

Returns:

=over

=item* html => cookie strings

=back

=head4 Note: An array reference is returned for C<CGI.pm::header()> as the C<-cookie> parameter.

=cut
sub getHTML {
	my $this = shift;
	my $q = $this->{'q'};
	
	my $result;
	while ((my $k, my $v) = each %{$this}) {
		# Ignore the 'q' key, it is the only key
		# that refers to non-cookie data.
		# All cookies are set to expire in 1 year.
		# The main indexing page resets short term cookies
		# when it is loaded, while the long term cookies
		# remain unchanged.
		push @{$result}, $q->cookie(
			{-name => $k, 
			-value => $v,
			-expires => '+1y'
			}
		) if ($k ne 'q');
	}
	
	return $result;
}

# Return true
1;
