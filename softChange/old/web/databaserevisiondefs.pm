#!/usr/bin/perl -w

package databaserevisiondefs;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getRevisionDefsRemoved',
	'getRevisionDefsAdded',
	'getRevisionDefsModified',
);

=head1 databaseAccess class : C<databaserevisiondefs.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getRevisionDefsRemoved (previd : string) => results : [more : bool, rows : [rownum : int, name : string, type : string]]

Get the definitions that were removed in the selected revision.

Parameters:

=over

=item* previd => the previous revision id

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, name, and type of definitions that were removed by the selected revision

=back

=cut
sub getRevisionDefsRemoved {
	my $this = shift;
	my $previd = shift;
	
	# If there is no previous revision id, then there cannot possibly be
	# anything removed, so just return the more flag. Otherwise, do the query.
	return
		$previd ?
		$this->databaseQuery(
			-getQuery => sub {
				my %parms = @_;
				my $file = $parms{-fileselect};
				my $rev = $parms{-revisionselect};

				return "
				SELECT
					definition,
					typedef,
					index
				FROM
					revdefs
        			WHERE
					filename = '$file' AND
					revisionid = '$previd'
				EXCEPT
				SELECT
					definition,
					typedef,
					index
				FROM
					revdefs
        			WHERE
					filename = '$file' AND
					revisionid = '$rev'
				ORDER BY
					".hardcode->cgiQueryRevisionDefsDefaultSort."
				;"
			},
			-queryDebugFlag => hardcode->dbQueryRevisionDefsDebug,
			-queryDebugMsg => 'get revision defs removed',
		) :
		[0];
}

=head3 getRevisionDefsAdded (previd : string) => results : [more : bool, rows : [rownum : int, name : string, type : string]]

Get the definitions that were added in the selected revision.

Parameters:

=over

=item* previd => the previous revision id

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, name, and type of definitions that were added by the selected revision

=back

=cut
sub getRevisionDefsAdded {
	my $this = shift;
	my $previd = shift || "";
	
	return $this->databaseQuery(
		-getQuery => sub {
			my %parms = @_;
			my $file = $parms{-fileselect};
			my $rev = $parms{-revisionselect};
			
			# Don't bother with the except clause if there is no
			# previous revision.
			return "
			SELECT
				definition,
				typedef,
				index
			FROM
				revdefs
        		WHERE
				filename = '$file' AND
				revisionid = '$rev'".
			($previd ? "
			EXCEPT
			SELECT
				definition,
				typedef,
				index
			FROM
				revdefs
        		WHERE
				filename = '$file' AND
				revisionid = '$previd'
			" :
			"")."
			ORDER BY
				".hardcode->cgiQueryRevisionDefsDefaultSort."
			;"
		},
		-queryDebugFlag => hardcode->dbQueryRevisionDefsDebug,
		-queryDebugMsg => 'get revision defs added',
	);
}


=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getRevisionDefsModified (previd : string) => results : [more : bool, rows : [rownum : int, name : string, type : string]]

Get the definitions that were removed in the selected revision.

Parameters:

=over

=item* previd => the previous revision id

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, name, and type of definitions that were removed by the selected revision

=back

=cut
sub getRevisionDefsModified {
	my $this = shift;
	my $previd = shift;
	
	# If there is no previous revision id, then there cannot possibly be
	# anything removed, so just return the more flag. Otherwise, do the query.
	return
	    $this->databaseQuery(
		-getQuery => sub {
		    my %parms = @_;
		    my $file = $parms{-fileselect};
		    my $rev = $parms{-revisionselect};
		    
		    return "
				SELECT
					definition,
					'function',
					index
				FROM
					functions
        			WHERE
					filename = '$file' AND
					revisionid = '$rev'
                                ORDER BY
					".hardcode->cgiQueryRevisionDefsDefaultSort."
				;"
			    },
		-queryDebugFlag => hardcode->dbQueryRevisionDefsDebug,
		-queryDebugMsg => 'get revision defs modified',
	    );
    }

1;
