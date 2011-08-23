#!/usr/bin/perl -w

package htmlbody;
use strict;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'addBody',
	'blankParagraph',
	'smallSpace',
	'unimplementedPage',
	'writeHTML'
);

=head1 html class : C<htmlbody.pm>

=head2 Uses: C<Exporter.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 Methods to create the body of html and write it out

=cut

=head3 addBody ([ info : (string) ])

Accumulate body information

Parameters:

=over

=item* info => array of strings to add to the body

=back

Returns:

=over

=item* none

=back

=cut
sub addBody {
	my $this = shift;
	
	map {$this->{'body'} .= $_} @_;
}

=head3 blankParagraph ()

Write out a blank paragarph to the body of the page

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub blankParagraph {
	my $this = shift;
	my $q = $this->{'q'};
	
	$this->addBody($q->p('&nbsp;'));
}

=head3 smallSpace ()

Write out a small blank space to the body of the page,
less than a paragraph in size.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub smallSpace {
	my $this = shift;
	my $q = $this->{'q'};
	
	$this->addBody("<table cellspacing=0 cellpadding=0><tr><td>&nbsp;</td></tr></table>\n");
}

=head3 unimplementedPage ()

Write out the message indicating that this page is unimplemented.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub unimplementedPage {
	my $this = shift;
	# The phrase is in three parts, separated by newlines.
	# The first part shd be in h3 tags, the other two are
	# separate paragraphs.
	my $start = "<h3>";
	my $end = "</h3>";
	
	$this->addBody(
		map {
			my $r = "$start$_$end\n";
			$start = "<p>";
			$end = "</p>";
			$r;
		} split '\n', hardcode->notImplementedPhrase
	);
}

=head3 writeHTML ()

Write out all the HTML code at once, including the cookies

Parameters:

=over

=item* none

=back

Returns:

=over

=item* none

=back

=cut
sub writeHTML {
	my $this = shift;
	my $q = $this->{'q'};
	my $c = $this->{'c'};
	
	# Get the GMT time in the format the browser needs
	# I get www mmm dd hh:mm:ss yyyy
	# I need www, dd mmm yyyy hh:mm:ss GMT
	my $time = gmtime();
	$time =~ /^(...) (...) (..) (..:..:..) (....)$/;
	$time = "$1, $3 $2 $5 $4 GMT";
	
	# Print out the content type and cookie.
	# Include headers to prevent caching of the page.
	# Include Pragma header for old browsers
	print $q->header({
		-type => hardcode->htmlType,
		-cookie => $c->getHTML(),
		-expires => 'now',
		"Last-Modified" => $time,
		"Cache-Control" => 'no-cache, must-revalidate',
		-Pragma => 'no-cache'
	});
	
	# Print out the dtd, html, header and body tags, and stylesheet name
	print $q->start_html({
		-dtd => hardcode->htmlDTD,
		-title => $this->title(),
		-bgcolor => hardcode->styleBackColor,
		-style => {-src => hardcode->styleSheet}
	})."\n";
	
	# Print out the content of the page
	print $this->{'body'};
	
	# Print out the closing body and html tags
	print $q->end_html()."\n";
}

1;
