#!/usr/bin/perl -w

package htmlutility;
use strict;
use hardcode;
use htmlbody;
use htmlurl;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getSQLMonth',
	'getFormattedMonth',
	'getFormattedTime',
	'compareDates',
	'getSortDirString',
	'noResults',
	'offsetLinks'
);

=head1 html class : C<htmlutility.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>, C<htmlbody.pm>, C<htmlurl.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 Utility functions

=cut

=head3 getSQLMonth ([ date : string ]) => month : string

Convert the current mr selection into an SQL month, or an empty string if the
current selection is not an SQL date.

EG:

=over

=item* 1997-01-05 => 1997-01

=item* junk => ''

=back

If the optional date is provided, then the provided date is returned
as an SQL month instead of the selection.

Parameters:

=over

=item* date => a date to format instead of the current selection

=back

Returns:

=over

=item* month => SQL month

=back

=cut
sub getSQLMonth {
	my $this = shift;
	my $date = shift;
	
	my $result = $date || $this->getMRSelect();
	
	if ($result =~ /^\d\d\d\d-\d\d-\d\d$/) {
		$result =~ s/-\d\d$//;
	} else {
		$result = "";
	}
	
	return $result;
}

=head3 getFormattedMonth ([ month : string ]) => month : string

Convert the current selection into a formatted month, or an empty string if the
current selection is not an SQL date.

EG:

=over

=item* 1997-01-05 => January, 1997

=item* 1997-01-05 -> 01/97

=item* junk => ''

=back

Parameters:

=over

=item* month => the month to be formatted instead of the current selection

=back

Returns:

=over

=item* month => The formatted month

=back

=cut
sub getFormattedMonth {
	my $this = shift;
	my $c = $this->{'c'};
	
	# The potential SQL month for the selected data
	my $result = shift || $this->getMRSelect();
	
	if ($result =~ /^(\d\d)(\d\d)-(\d\d)-\d\d$/) {
		# Is it a long format?
		my $long = $c->dateFormat() == hardcode->dateLongFormat;
		
		# Get the month and the year
		my $month = 
			$long ?
			monthName([$3]) :
			$3;
			
		my $year =
			$long ?
			"$1$2" :
			$2;
		
		# Get the formatting order and separator
		my @order = hardcode->dateOrder;
		my @sepList = 
			$long ?
			hardcode->dateLongSeparators :
			hardcode->dateShortSeparators;
		
		# Figure out what position month and year occupy
		my $monthPos;
		my $yearPos;
		for (my $i = 0; $i < @order; $i++) {
			$monthPos = $i if $order[$i] eq hardcode->dateMonthOrder;
			$yearPos = $i if $order[$i] eq hardcode->dateYearOrder;
		}
		
		# Figure out which comes later, month or year
		my $later =
			$monthPos < $yearPos ?
			$yearPos :
			$monthPos;
		
		# The separator to use is the one that comes just
		# before the later piece.
		my $sep =
			$later == 1 ?
			$sepList[0] :
			$sepList[1];
			
		# Format the date
		$result =
			$monthPos < $yearPos ?
			$month.$sep.$year :
			$year.$sep.$month;
	} else {
		$result = "";
	}
	
	return $result;
}

=head3 getFormattedTime (time : string) => time : string

Convert the given time suitable for an SQL query into a properly formatted
time according to the locale.

Parameters:

=over

=item* time => the SQL time string to format

=back

Returns:

=over

=item* time => the formatted time

=back

=cut
sub getFormattedTime {
	my $this = shift;
	my $hour;
	my $minute;
	my $second;
	
	# SQL string form.
	# Leading zeroes are included in string.
	my $time = shift;
	$time =~ /(\d\d):(\d\d):(\d\d)/;
	($hour, $minute, $second) = ($1, $2, $3);
	
	my @pieces = (
		$hour,
		$minute,
		$second
	);
	my @seps = hardcode->timeSeparators;
		
	my $result = '';
	map {
		$result .= $pieces[$_].(shift @seps || '');
	} hardcode->timeOrder;
	
	return $result;
}

=head3 compareDates (date1 : [month : int, day : int, year : int], date2 : [month : int, day : int, year : int]) => compare : int

Trinary comparison of date1 against date2.

Parameters:

=over

=item* date1 => the first date

=item* date2 => the second date

=back

Returns:

=over

=item* compare => -1 if date1 < date2, 0 if date1 == date2, 1 if date1 > date2

=back

=cut
sub compareDates {
	my $this = shift;
	my $date1 = shift;
	my $date2 = shift;
	
	(my $m1, my $d1, my $y1) = @{$date1};
	(my $m2, my $d2, my $y2) = @{$date2};
	
	# Result to return
	my $result;
	
	# Use up to three trinary comparisons as necessary
	$result = $y1 <=> $y2;
	! $result && ($result = $m1 <=> $m2);
	! $result && ($result = $d1 <=> $d2);
	
	return $result;
}

=head3 getSortDirString (goodValues : [string], col : string) => dirstr : string

The string used to indicate the current sorting direction.
There are three possible direction strings:

=over

=item* C<'/\'> = ascending order

=item* C<'\/'> = descending order

=item* C<''> = the provided column is not the current sorting column

=back

Parameters:

=over

=item* goodValues => The acceptable sorting field names

=item* col => The name of the column to get the string for

=back

Returns:

=over

=item* the sorting direction string

=back

=cut
sub getSortDirString {
	my $this = shift;
	my $sortValues = shift;
	my $col = shift || "";
	
	my $sort = $this->getSort($sortValues);
	my $sortDir = $this->getSortDir($sortValues);
		
	my $result = "";
	$result = ($sortDir eq hardcode->cgiQuerySortDirAsc) ? '  /\\' : '  \\/'
		if $col eq $sort;
		
	return $result;
}

=head3 offsetLinks (more : bool)

Add the links referring to the previous X items and the
next X items, where X is the current limit.

Parameters:

=over

=item* more => true if there are more results, false if there are not

=back

Returns:

=over

=item* none

=back

=cut
sub offsetLinks {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	my $more = shift;
		
	# The current offset
	my $offset = $this->getOffset();
	
	# Create the previous link, or just text if the
	# current offset is 0.
	my $previous = htmlSpace('&lt;&lt; '.hardcode->termPrevious);
	if ($offset) {
		# Make it a link
		$previous = $q->a(
			{-href => $this->getSelfURL({
				hardcode->cgiParmQueryOffset =>
					$offset - 1
			})},
			$q->b($previous)
		);
	}
	
	# Create the next link, or just text if there
	# are certainly not more results
	my $next = htmlSpace(hardcode->termNext.' &gt;&gt;');
	if ($more) {
		# Make it a link
		$next = $q->a(
			{-href => $this->getSelfURL({
				hardcode->cgiParmQueryOffset =>
					$offset + 1
			})},
			$q->b($next)
		);
	}
	
	# Add the links in a separate paragraph at the bottom
	$this->addBody($q->p(
		$previous.
		hardcode->nonBreakingSpace.
		$next."\n"
	)."\n");
}

1;
