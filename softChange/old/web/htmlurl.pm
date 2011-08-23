#!/usr/bin/perl -w

package htmlurl;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getURL',
	'getSelfURL',
	'getLocaleURL'
);

=head1 html class : C<htmlurl.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 URL methods

=cut

=head3 getURL (loc : string, [ table : {keys => values} ], [ onlyTable : bool ]) => url : string

Get the URL for the specified page, setting the specified parameters to
their specified values. The url will have all state parameters set, whether
or not they appear in the provided table. The table specifies which of the
state parameters to change for this url, as well as any non-state parameters
that are necessary.

If the optional onlyTable parameter is true, then only the parameters specified
in the table will be set, all other parameters will not be included in the
URL, and the page that loads will return default values for them thru their
respective get functions.

Each call to getURL goes through the following steps to ensure correctness:

=over

=item* if onlyTable is false: copy all state parameters from the state table, using get functions

=item* set all parameters specified in provided table

=item* get the url for the given page, killing all parameters

=item* change the base url to the one provided

=back

This process ensures that the order in which URLs are created is irrelevant.

Parameters:

=over

=item* loc => the base url

=item* table => a hash ref of (key => value) pairs to set for the url

=item* onlyTable => true if only the parameters in the table should be set by the URL, false if all state parameters should be set by the URL

=back

Returns:

=over

=item* url => the base url with the parameters set as indicated

=back

=head4 Note: Parameters can be set to arrays by supplying array references in the hash

=cut
sub getURL {
	my $this = shift;
	my $q = $this->{'q'};
	
	# The location and parameters passed
	my $loc = shift;
	my $table = shift;
	my $onlyTable = shift;
	
	# Copy the state table to a new table, using the
	# get functions, which may not return the same
	# value as the table. Only do this if onlyTable
	# is false.
	my %parms;
	if (! $onlyTable) {
		while ((my $k, my $f) = each %{$this->{'get'}}) {
			$parms{$k} = &$f($this);
		}
	}
	
	# Change all specified parameters in the new table
	if (ref($table) eq "HASH") {
		while ((my $k, my $v) = each %{$table}) {
			$parms{$k} = $v;
		}
	}
	
	# Kill any parameters in the base URL to be safe
	$loc =~ s/\?.*$//;
	
	# Add the parameters from the new table to the URL
	while ((my $k, my $v) = each %parms) {
		# The parameter may be set to an array reference
		if (ref($v) eq "ARRAY") {
			map {$loc .= "&$k=".$q->escapeHTML($_)} @{$v};
		
		# The parameter may be set to a hash reference
		} elsif (ref($v) eq "HASH") {
			map {$loc .= "&$k=".$q->escapeHTML($_)} keys %{$v};
		
		# The parameter may be an empty string
		} elsif ($v) {
			$loc .= "&$k=".$q->escapeHTML($v);
		}
	}
	$loc =~ s/&/\?/;
	
	# Return the resulting url
	return $loc;
}

=head3 getSelfURL ([ table : {keys => values} ], [ onlyTable : bool ]) => url : string

Get this url, setting the specified parameters.

Alter the URL so that the .pl.?? suffix is replaced by .html, so that Apache type
maps are used to set the language for every page load.

See getURL() above.

Parameters:

=over

=item* table => a hash ref of (key => value) pairs to set for the url

=item* onlyTable => true if only the parameters in the table should be set by the URL, false if all state parameters should be set by the URL

=back

Returns:

=over

=item* url => the self url with the parameters set as indicated

=back

=cut
sub getSelfURL {
	my $this = shift;
	my $q = $this->{'q'};
	
	# Change the .pl.?? to .html if present
	my $base = $q->script_name();
	$base =~ s/\.pl\.../\.html/;
	
	return $this->getURL($base, shift, shift);
}

=head3 getLocaleURL (code : string) => url : string

Get this url, changing the language to the specified two character
code, or removing the language code if the code passed is ''.

The language code baing changed or removed is the directory prefix
portion of the URL, EG the ?? in C</softChange/??/....>.

Alter the URL so that the .pl.?? suffix is replaced by .html, so that Apache type
maps are used to set the language for every page load.

The URLs produced are of one of the following two forms:

=over

=item* C</softChange/page.html>

=item* C/softChange/??/page.html>

=back

These URLs have their language code set or removed, and they end in .html so they
also use Apache type maps. This is necessary to make language switching work on the fly.

Parameters:

=over

=item* code => the two character language code to use or '' for default

=back

Returns:

=over

=item* url => the self url with the language set as indicated

=back

=cut
sub getLocaleURL {
	my $this = shift;
	my $q = $this->{'q'};
	my $code = shift;
	
	# Get the current url with state information
	my $result = $q->self_url();
	
	# Strip the language code, if there is one
	# (this hapens to be the default)
	my $soft = hardcode->termSoftChange;
	$result =~ s/(^.*$soft\/)\w\w\//$1/;
	
	# Replace any .pl.?? with .html so that the original
	# html file is loaded, which can use the type mapping.
	$result =~ s/\.pl\.../\.html/;
	
	# Set the language to the specified code if one was given
	$result =~ s/(^.*$soft\/)/$1$code\//
		if $code;
	
	# Return the resulting URL
	return $result;
}

1;
