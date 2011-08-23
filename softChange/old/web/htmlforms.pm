#!/usr/bin/perl -w

package htmlforms;
use strict;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'hidden',
	'getHiddenElements'
);

=head1 html class : C<htmlforms.pm>

=head2 Uses: C<Exporter.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head2 Methods for creating forms

=cut

=head3 hidden (parm : string, value : string) => form : string

Create a hidden form element with the desired parameter value.
For whatever reason, C<CGI-E<gt>hidden()> ignores any supplied value
if the name matches a parameter in the hash maintained by
C<CGI-E<gt>param()>. So you have to set the parameter first, then
create the hidden element with the new value.

The value may be an array reference to multiple values.

Parameters:

=over

item* parm => the name of the parameter to set

=item* value => the value to set the named parameter to

=back

Returns:

=over

=item* form => a hidden form element that sets the named parameter to the value

=back

=cut
sub hidden {
	my $this = shift;
	my $q = $this->{'q'};
	
	my $parm = shift;
	my $value = shift;
	$value = [$value] if ref($value) ne "ARRAY";
	$q->param({-name => $parm, -values => $value});
	return $q->hidden({-name => $parm});
}

=head3 getHiddenElements ([ tab : string, name : string ]) => form : string

Get hidden form elements for all parameters
we care about. This is all the elements contained
in the 'state' hash ref of this object except the one optionally passed.
The optional tabbing string is used to format the html nicely.

Parameters:

=over

=item* tab => a string of tab characters

=item* name => the name of a parameter to be excluded from the result

=back

Returns:

=over

=item* form => the set of hidden form elements as a string

=back

=cut
sub getHiddenElements {
	my $this = shift;
	
	my $tab = shift || "";
	my $ignore = shift || "";
	my $results;
	
	while ((my $k, my $v) = each %{$this->{'get'}}) {
		$results .= $tab.$this->hidden($k, &$v($this))."\n"
			if $k ne $ignore;
	}
	
	return $results;
}

1;
