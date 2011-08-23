#!/usr/bin/perl -w

package databaseList;
use strict;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getDatabaseList'
);

=head1 databaseAccess class : C<databaseList.pm>

=head2 Uses: C<Exporter.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getDatabaseList () => results : [more : bool, rows : [rownum : int, databasename : string]]

Get the list of databases that contain the neccessary tables.

The queries contained in the code are based on the output that C<psql>
generates with the C<\l> and C<\d> commands.

Parameters:

=over

=item* none

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum and database name of each database that is probably compatible with softChange

=back

=cut
sub getDatabaseList {
	my $this = shift;
	
	return $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryDBListDefaultSort,
		-sortValues => [hardcode->cgiQueryDBListSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $sort = $parms{-sort};
			my $sortDir = $parms{-sortDir};
			
			return "
			SELECT
				d.datname
			FROM
				pg_catalog.pg_database d
  				LEFT JOIN pg_catalog.pg_user u ON d.datdba = u.usesysid
			ORDER BY
				$sort $sortDir
			;"
		},
		-queryDebugFlag => hardcode->dbQueryDBListDebug,
		-queryDebugMsg => 'list all databases',
		-getRow => sub {
			my %parms = @_;
			my $row = $parms{-row};
			
			# $row refers to a row of [database name]
			# the query is not complete yet, so there are no
			# more flag or line numbers.
			my $dbname = $row->[0];
			my $bad = (join ':', hardcode->dbBadDatabases);
			my $result = [];
			
			if ((index $bad, $dbname) == -1) {
				# The system isn't designed to have more than
				# one open database at a time, and our subqeueries
				# require connecting to the database names from the
				# main query. Save the old information and restore it.
				my $old_dbh = $this->{'connect'};
				my $old_dbname = $this->{'currentDatabase'};
				
				# Connect to the database so we can check its tables
				$this->database($dbname);
				
				$result = $this->databaseQuery(
					-getQuery => sub {
						return "
						SELECT
			        			c.relname
		        			FROM 
			        			pg_catalog.pg_class c
     			        			LEFT JOIN pg_catalog.pg_user u ON u.usesysid = c.relowner
     			        			LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace
		        			WHERE 
			        			c.relkind = 'r'
      			        			AND n.nspname NOT IN ('pg_catalog', 'pg_toast')
							AND c.relname IN ('mrs2', 'mrsfiles', 'revisions', 'files', 'info', 'methoddeltas', 'mrstats', 'revisiondiffs', 'revdefs')
      			        			AND pg_catalog.pg_table_is_visible(c.oid)
						;"
					},
					-queryDebugFlag => hardcode->dbQueryDBListDebug,
					-queryDebugMsg => "check tables of database $dbname"
				);
				
				# Disconnect from the database
				$this->disconnect();
				
				# Restore old database connectionn data
				$this->{'connect'} = $old_dbh;
				$this->{'currentDatabase'} = $old_dbname;
			}
			
			# By this time, the subquery has completed, so the more flag
			# has been added to the result. The subquery contains one row per
			# table we are looking for. If the result contains more than one
			# row, then the database contains at least some of the tables we
			# are interested in.
			#
			# Change the set of tables to a single row listing all tables,
			# and add that to the result as another column in an array ref.
			#
			# So the result is [database name, [table names]].
			
			if (@{$result} > 1) {
				# Dump the more flag
				shift @{$result};
				
				# The new list of table names
				my %tableList;
				
				# Make a hash of all table names
				map {$tableList{$_->[1]} = 1} @{$result};
				
				# Make sure we have the basic set of tables required
				# to do anything : mrs2, mrsfiles, revisions, files, info.
				# If so, add this hash to the row to return as a hash ref.
				# Otherwise, reject the row.
				if (
					$tableList{'mrs2'} && 
					$tableList{'mrsfiles'} &&
					$tableList{'revisions'} &&
					$tableList{'files'} &&
					$tableList{'info'}
				) {
					push @{$row}, {%tableList};
				} else {
					undef $row;
				}
			} else {
				undef $row;
			}
			
			return $row;
		},
		-getManualLimitFlag => sub {
			# Since this code rejects some of the rows of the main
			# query, we must always do manual limit and offset.
			return 1;
		}
	);
}

1;
