#!/usr/bin/perl -w

package htmlpreferences;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'preferencesHeader',
	'developerListForm',
	'applyDatesCheckBox',
	'dateRangeForm',
	'maxRowSelection',
	'dateFormatSelection',
	'preferencesFooter',
	'preferencesSuccess'
);

=head1 html class : C<htmlpreferences.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 Methods used for creating the preferences

=cut

=head3 preferencesHeader (name : string, query : string)

Start the preferences form.

Parameters:

=over

=item* name => the name of the current database

=item* query => the type of query being performed

=back

Returns:

=over

=item* none

=back

=head4 Note: The query is not used by the preferences form

The database is needed to extract the set of developers and
the date ranges, but the query is not used. The name and query
represent state information needed to return to the previous
page after setting the preferences.

=cut
sub preferencesHeader {
	my $this = shift;
	my $q = $this->{'q'};

	$this->addBody($q->startform({
			-name => hardcode->prefsFormName,
			-method => hardcode->formMethod,
			-action => hardcode->prefsURL
		}),
		$this->getHiddenElements(),
		$this->hidden(
			hardcode->cgiParmReferer,
			$q->param(hardcode->cgiParmReferer)
		)."\n"
	)."\n";
}

=head3 developerListForm (alldev : [[line : int, dev : string]], seldev : [string])

Add the developer list to the body

Parameters:

=over

=item* alldev => all developer names

=item* seldev => selected developer names

=back

Returns:

=over

=item* none

=back

=cut
sub developerListForm {
	my $this = shift;
	my $q = $this->{'q'};

	# Get the list of developers, pulling each
	# developer name out from the array refs of each row.
	my $devList = [map {$_->[1]} @{(shift)}];
	my $selList = shift;
	my $checkIt = '';
	
	# If the first selected developer is 'any', then
	# select the first one, and uncheck the checkbox.
	if ($selList->[0] eq hardcode->cookieDefaultValue) {
		$selList = [$devList->[0]];
		$checkIt = 'checked';
	}
	
	$this->addBody(
		$q->p($q->b(hardcode->prefsDeveloperListText)."\n"),
		$q->p($q->checkbox({
			-name => hardcode->cgiParmApplyDevelopers,
			-checked => $checkIt,
			-value => hardcode->termNone,
			-label => hardcode->termNone
		}))."\n",
		$q->p($q->scrolling_list({
			-name => hardcode->cgiParmSetDevelopers,
			-values => $devList,
			-default => $selList,
			-multiple => 'true',
			-size => hardcode->prefsDeveloperListSize
		}))."\n"
	);
}

=head3 applyDatesCheckBox ()

Add the apply dates checkbox to the body

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub applyDatesCheckBox {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	# Whether or not to apply the date range
	my $checkIt = '';

	# Deselect the checkbox is there is no month selected
	$checkIt = 'checked' if ! $c->startMonth();

	# Add the checkbox to the form
	$this->addBody(
		$q->p($q->b(hardcode->prefsDateRangeText))."\n",
		$q->p($q->checkbox({
			-name => hardcode->cgiParmApplyDates,
			-checked => $checkIt,
			-value => hardcode->termNone,
			-label => hardcode->termNone
		}))."\n"
	);
}

=head3 dateRangeForm (text : [string], first : bool, sel : [month : int, day : int, year : int], ranges : [int])

Add the range of dates to the body.

If the currently selected date is empty strings rather than ints, then the earliest
and latest dates are preselected instead, as a convenience for the user.

Parameters:

=over

=item* text => the text to describe each date part

=item* first => whether to select the first or last date as default

=item* sel => the currently selected date

=item* ranges => the ranges of the date pieces

=back

Returns:

=over

=item* none

=back

=cut
sub dateRangeForm {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	my $text = shift;
	my $select = shift;
	my $currentDate = shift;
	my @range = @{(shift)};
	my @names;
	my @texts = hardcode->dateTexts;
	my @order = hardcode->dateOrder;
	my $dateElements;
	my $default;
	
	# The logical names to use for the form
	@names =
		$select == hardcode->prefsDateFirst ?
		hardcode->cgiParmDateFrom :
		hardcode->cgiParmDateTo;
	
	# Loop through all 3 pieces of the date arrays passed
	for(my $i = 0; $i < 3; $i++) {
		# The order specifies how the date pieces are arranged
		my $which = shift @order;
		
		# Convert the min and max into a range from min to max for the year.
		# For the rest use a range that is the full set of possible values.
		my @r;
		CASE: {
			($which eq  hardcode->dateYearOrder) && do {
				@r = ($range[$which * 2] .. $range[$which * 2 + 1]);
				
				last CASE;
			};
			
			($which eq  hardcode->dateMonthOrder) && do {
				@r = (1 .. 12);
				
				last CASE;
			};
			
			($which eq  hardcode->dateDayOrder) && do {
				@r = (1 .. 31);
				
				last CASE;
			};
		};
		
		# Get the current or default value for this date piece,
		# the default being the earliest or latest date piece.
		$default = $currentDate->[$which];
		$default =
			$select == hardcode->prefsDateFirst ?
			$range[$which * 2] :
			$range[$which * 2 + 1]
				if ! $default;		
		
		# If this piece is the month, convert the range to name range,
		# and convert the current date element to a name.
		if ($which == hardcode->dateMonthOrder) {
			@r = monthName([@r], 1);
			$default = monthName([$default], 1);
		}
		
		# Add the textual name for the piece
		$dateElements.= $texts[$which].":".hardcode->nonBreakingSpace."\n";
		$dateElements.= $q->popup_menu({
			-name => $names[$which],
			-values => \@r,
			-default => $default
		})."\n"
	}
	
	# Add the form elements to the body
	$this->addBody($q->p(
		$q->b($text),
		$q->br(),
		$dateElements)
	);
}

=head3 maxRowSelection ()

Add the radio group to select the limit on the database results
to the body

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub maxRowSelection {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	$this->addBody($q->p(
		$q->b(hardcode->prefsMaxRowsText).$q->br()."\n",
		$q->radio_group({
			-name => hardcode->cgiParmMaxRows,
			-values => [hardcode->cgiMaxRowsValues],
			-default => $c->maximumRows()
		})."\n"
	)."\n");
}

=head3 dateFormatSelection ()

Add the menu to select the long or short date format.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub dateFormatSelection {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	$this->addBody(
		$q->table(
			{-cellpadding => 0,
			-cellspacing => 0,
			-border => 0
			},
			$q->td(
				{-valign => "top"},
				$q->b(hardcode->prefsDateFormatText).
				hardcode->nonBreakingSpace.
				$q->br()."\n",
				$q->radio_group({
					-name => hardcode->cgiParmDateFormat,
					-values => [
						hardcode->termLong, 
						hardcode->termShort
					],
					-default =>
						$c->dateFormat() == hardcode->dateLongFormat ?
						hardcode->termLong :
						hardcode->termShort
				}).hardcode->nonBreakingSpace."\n"
			)."\n"
		)."\n"
	);
}

=head3 preferencesFooter ()

End the preferences form

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub preferencesFooter {
	my $this = shift;
	my $q = $this->{'q'};
	
	# Add the write prefs and cancel buttons to the bottom
	$this->addBody(
		"\n".$q->submit({
			-name => hardcode->cgiParmWritePrefs,
			-value => hardcode->titleButtonSetPreferences
		})."\n",
		$q->endform(),
		"\n".$q->startform({
			-name => hardcode->prefsCancelFormName,
			-method => hardcode->formMethod,
			-action => $q->param(hardcode->cgiParmReferer)
		}),
		$this->getHiddenElements(),
		$q->submit({
			-name => hardcode->cgiParmCancelPrefs,
			-value => hardcode->titleButtonCancel
		})."\n",
		$q->endform()
	);
}

=head3 preferencesSuccess ()

Add a success message to the body, indicating what the preferences
were set to.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub preferencesSuccess {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	my $query = $this->getQuery();
	my $devHead = "";
	my $devRows = "";
	my $startTime = "";
	my $endTime = "";
	
	# Don't show database-specific stuff for the initial page
	if ($query ne hardcode->cgiQueryList) {	
		$devHead = hardcode->termDeveloperPlural.':';
		my @devList = $c->developers();
		if ($devList[0] eq hardcode->cookieDefaultValue) {
			$devHead = $q->p(
				$devHead,
				hardcode->nonBreakingSpace,
				hardcode->cookieDefaultValue
			)."\n";
		} else {
			$devHead .= "\n";
			foreach my $dev (@devList) {
				$devRows .= "\n".$q->li($dev);
			}
			$devRows = $q->ul($devRows."\n")."\n";
		}
		
		$startTime = $q->p(
				hardcode->prefsStartDate,
				hardcode->nonBreakingSpace,
				$c->getStartDate()
			)."\n";
		
		$endTime = $q->p(
			hardcode->prefsEndDate,
			hardcode->nonBreakingSpace,
			$c->getEndDate()
		)."\n"
	}
	
	# Add the success message, describing what each setting was set to.
	# Add a continue link to go back to whatever the user was doing.
	$this->addBody(
		$q->p(hardcode->prefsUpdated)."\n",
		$devHead,
		$devRows,
		$startTime,
		$endTime,
		$q->p(
			hardcode->prefsMaxRowsText,
			hardcode->nonBreakingSpace,
			$c->maximumRows()
		)."\n",
		$q->p(
			hardcode->prefsDateFormatText,
			hardcode->nonBreakingSpace,
			($c->dateFormat() ?
			hardcode->termShort :
			hardcode->termLong)
		)."\n",
		$q->a({
			-href => $this->getURL(
				$q->param(hardcode->cgiParmReferer),
				{hardcode->cgiParmQueryOffset => 0}
			)},
			hardcode->termContinue
		)."\n"
	);
}

1;
