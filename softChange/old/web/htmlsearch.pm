#!/usr/bin/perl -w

package htmlsearch;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'searchForm',
	'searchResults'
);

=head1 html class : C<htmlsearch.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 searchForm ()

Add the search form to the body. The form contains an explanation of how to use the form,
followed by Google-like boxes to eneter words or phrases in.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub searchForm {
	my $this = shift;
	my $q = $this->{'q'};
	
	# Massage the phrase
	my $phrase = hardcode->searchExplainPhrase;
	$phrase =~ /(^[^:]*:)(.*)$/;
	my $explain = $1;
	my $list = $2;
	$explain =~ s/\{/<b>/g;
	$explain =~ s/\}/<\/b>/g;
	$explain =~ s/\.(.)/\.<br \/>\n$1/g;
	$list =~ s/([^\.]*\.)/<li>$1\n/g;
	$phrase = "$explain</b>\n<ul>$list</ul>";

	# Make form elements out of them
	my $queryForms;
	my @names = (hardcode->searchPhraseNames);
	map {
		my $text = $_;
		$text =~ s/\{/<b>/g;
		$text =~ s/\}/<\/b>/g;

		$queryForms.= getTabs(SET, 0).$q->TR(
			getTabs(IN).$q->td(
				htmlSpace("$text: ")
			),
			getTabs().$q->td($q->textfield({
				-name => shift @names,
				-value => '',
				-size => 40,
				-maxlength => 40
			})).getTabs(OUT)
		);
	} (hardcode->searchTextPhrases);

	# Add the form to the body
	$this->addBody(
		$q->p($phrase)."\n",
		$q->startform({
		-name => hardcode->searchFormName,
		-method => hardcode->formMethod,
		-action => $q->script_name()
		})."\n",
		$this->hidden(
			hardcode->cgiParmDB,
			$this->getDatabase()
		)."\n",
		$this->hidden(
			hardcode->cgiParmQuery,
			hardcode->cgiQuerySearch
		)."\n",
		$this->hidden(
			hardcode->cgiParmSupportedTables,
			[keys %{$this->supportedTables()}]
		)."\n",
		$q->table(
			{-border => 0,
			-cellpadding => 0,
			-cellspacing => 0
			},
			$queryForms."\n",
		)."\n",
		$q->p($q->submit({
			-name => hardcode->cgiParmQueryDetail,
			-value => hardcode->titleURLDoSearch
		}))."\n",
		$q->endform()."\n"
	);
}

=head3 searchResults (results : [[rownum : int, mrid : string, author : string, date : string, time : string, log : string]]) => body : string

Add the search results to the body

Parameters:

=over

=item* results => the rownum, mrid, author, date, time, and log of each MR that matches

=back

Returns:

=over

=item* body => the string table to add to the body

=back

=cut
sub searchResults {
	my $this = shift;
	my $results = shift;
	
	return $this->generateHTML(
		-results => $results,
		-tableTitle => hardcode->searchResultsTitle,
		-columnTexts => [hardcode->colsQuerySearch],
		-sortValues => [hardcode->cgiQuerySearchSortBy],
		-sortDefault => hardcode->cgiQuerySearchDefaultSort,
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			return (
				hardcode->nonBreakingSpace.
				htmlSpace($row->[0]).
				hardcode->nonBreakingSpace,
				
				# MRID
				$q->a({
					-href => $this->getSelfURL({
						hardcode->cgiParmQueryOffset => 0,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMRID,
						hardcode->cgiParmQueryMRIDSelect => $row->[1],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRIDDefaultSort,
						hardcode->cgiParmQuerySortDir =>
							hardcode->cgiQuerySortDefaultDir,
						hardcode->cgiParmQueryDeveloper =>
							hardcode->cookieDefaultValue,
						hardcode->cgiParmQueryDate =>
							hardcode->cookieDefaultValue
					})},
					htmlSpace($row->[1])
				).hardcode->nonBreakingSpace,

				# Author
				$q->a({
					-href => $this->getSelfURL(
						{hardcode->cgiParmDB =>
							$this->getDatabase(),
						hardcode->cgiParmSupportedTables =>
							$this->supportedTables(),
						hardcode->cgiParmQuery =>
							hardcode->cgiQueryAuthor,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMR,
						hardcode->cgiParmQueryMRSelect => $row->[2],
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort
						},
						1
					)},
					htmlSpace($row->[2])
				).hardcode->nonBreakingSpace,
					
				# Date
				$q->a({
					-href => $this->getSelfURL(
						{hardcode->cgiParmDB =>
							$this->getDatabase(),
						hardcode->cgiParmSupportedTables =>
							$this->supportedTables(),
						hardcode->cgiParmQuery =>
							hardcode->cgiQueryMonth,
						hardcode->cgiParmQueryDetail =>
							hardcode->cgiQueryDetailByMR,
						hardcode->cgiParmQueryMRSelect =>
							$this->getSQLMonth($row->[3])."-01",
						hardcode->cgiParmQuerySortBy =>
							hardcode->cgiQueryMRDefaultSort,
						hardcode->cgiParmQueryDate => $row->[3]
						},
						1
					)},
					htmlSpace($c->getFormattedDate($row->[3]))
				).hardcode->nonBreakingSpace,

				# Time
				htmlSpace($this->getFormattedTime($row->[4])).
				hardcode->nonBreakingSpace,
				
				# Description
				$q->pre(formatLog($row->[5]))
			);
		}
	);
}

1;
