#!/usr/bin/perl -w

package databaserevisiondiffs;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'getMethodName',
	'getRevisionDiffs'
);

=head1 databaseAccess class : C<databaserevisiondiffs.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 getMethodName (clean : bool, revid : string, line : int) => results : [more : bool, rows : [rownum : int, type : string, methodName : string]]

Get the method or function name for a given line.

There may not be a method or function name for the given line, in which case the result
will be false.

Parameters:

=over

=item* clean => true if this is the clean source diff, false if it is the original source diff

=item* revid => the revision id

=item* line => the line number

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rownum, type (method or function) and the method name

=back

=cut
sub getMethodName {
	my $this = shift;
	my $clean = shift;
	my $revid = shift;
	my $lineNum = shift;
	
	my $result = $this->databaseQuery(
		-sortDefault => hardcode->cgiQueryMonthDefaultSort,
		-sortValues => [hardcode->cgiQueryMonthSortBy],
		-getQuery => sub {
			my %parms = @_;
			my $file = $parms{-fileselect};
	
			# Depending on whether this is a clean or original source
			# query, we shd query either the cleanline or line column.
			my $column = $clean ? "cleanline" : "line";
			
			return "
			SELECT
				typedef,
				trim(both from definition)
			FROM
				revdefs
			WHERE
				filename = '$file' AND
				revisionid = '$revid' AND
				$column = (
					SELECT
						max($column)
					FROM
						revdefs
					WHERE
						filename = '$file' AND
						revisionid = '$revid' AND
						$column <= $lineNum AND
						typedef in ('method', 'function')
					GROUP BY
						filename, revisionid
				)
			;";
		},
		-queryDebugFlag => hardcode->dbQueryRevisionDiffs,
		-queryDebugMsg => 'get method name'
	);
	
	# If there was no such method or function, return false
	@{$result} == 1 && ($result = 0);
	
	return $result;
}

=head3 getRevisionDiffs (clean : bool, previd : string, diff : string) => rows : [more : bool, rows : [rownum : int, rowType : string, rest : (beforeLine : int, beforeType : string, beforeName : string, afterLine : int, afterType : string, afterName : string) | (beforeText : string,  afterText : string)]]

Get the side by side revision diffs between previous and selected revision.

The rowType identifies the type of each row, as follows:

=over

=item* line => a row of line numbers

=item* add => a row of text additions

=item* change => a row of text changes

=item* delete => a row of text deletions

=back

Parameters:

=over

=item* clean => true if this is the clean source code, false if it is the original source code

=item* previd => the revision id of the previous revision

=item* diff => the diff text

=back

Returns:

=over

=item* more => true if there are more results, false if there are not

=item* rows => the rowType, rownum, and rest of the information for the side by side comparison

=item* rest (rowType == line) => before and after line numbers, type (method or function or false if neither), and name

=item* rest (rowType != line) => before and after text

=back

=head4 Note: The rows are in pairs, with a row of line numbers before each row of type, name, and text

These pairs share the same line number. This is for compatibility with the C<generateHTML()> method, which can
only accept one row of data at a time.

=cut
sub getRevisionDiffs {
	my $this = shift;
	my $clean = shift;
	my $previd = shift;
	my $diff = shift;
	
	my $h = $this->{'h'};
	my $q = $this->{'q'};
	
	my $revid = $h->getRevisionSelect();
	
	# The result to return
	my $results = [0];
	
	# The current row number
	my $rowNum = 1;
	
	# $h->addBody($q->p("DIFF BEFORE WHILE: |$diff|"));

	# Displaying all diffs side by side
	while ($diff =~ /(^[0-9,]+)([a-z])([0-9,]+)/) {
		# Snag the number(s) before, type, and number(s) after
		my $beforeLineNum = $1;
		my $type = $2;
		my $afterLineNum = $3;
		my $match = $&;

		# If the number before or after is a pair, we
		# really only care about the first one.
		$beforeLineNum =~ /(^[0-9]+)/ && ($beforeLineNum = $1);
		$afterLineNum =~ /(^[0-9]+)/ && ($afterLineNum = $1);

		# Move the diff ahead past the before, type, and after
		$diff = substr $diff, length($match);
		my $body = "";
		if ($diff =~ /^[0-9]+/m) {
			# There are more records, so snag the body of
			# this record and move the diff to the next one.
			my $idx = index $diff, $&;
			$body = substr $diff, 0, $idx;
			$diff = substr $diff, $idx;
		} else {
			# This is the last record, so the body is the
			# whole diff, and the diff becomes empty to
			# stop the while loop
			$body = $diff;
			$diff = "";
		}

		# $h->addBody($q->p("BODY: |$body|"), $q->p("DIFF: |$diff|"));

		# Get the before method type and name, if there is one
		my $beforeMethodType = "";
		my $beforeMethodName = "";
		if ($beforeLineNum =~ /^[0-9]+$/) {
			my $methodResults = $this->getMethodName($clean, $previd, $beforeLineNum);
			if ($methodResults) {
				$beforeMethodType = $methodResults->[1]->[1];
				$beforeMethodName = $methodResults->[1]->[2];
			}
		}

		# $h->addBody($q->p("BEFORE METHOD/FUNC: '$beforeMethodType', '$beforeMethodName'"));

		# Get the after method type and name, if there is one
		my $afterMethodType = "";
		my $afterMethodName = "";
		if ($afterLineNum =~ /^[0-9]+$/) {
			my $methodResults = $this->getMethodName($clean, $revid, $afterLineNum);
			if ($methodResults) {
				$afterMethodType = $methodResults->[1]->[1];
				$afterMethodName = $methodResults->[1]->[2];
			}
		}

		# $h->addBody($q->p("AFTER METHOD/FUNC: '$afterMethodType', '$afterMethodName'"));
		
		# Handle the type of the diff - add, change, or delete
		my $beforeText = "";
		my $afterText = "";
		my $typeName;
		CASE: {
			# For an addition, there is only an after part
			($type eq 'a') && do {
				$afterText = $body;
				
				$typeName = 'add';
				
				last CASE;
			};
			
			# For a change, there is both a before and an after part
			($type eq 'c') && do {
				# Locate the separator between the before and after part
				my $sep = index $body, "\n---";
				
				# The before part is before the separator
				$beforeText = substr $body, 0, $sep;
				
				# The after part if after the separator.
				# Remember to skip the separator itself.
				$afterText = substr $body, $sep + 4;
				
				$typeName = 'change';
				
				last CASE;
			};
			
			# For a deletion, there is only a before part
			($type eq 'd') && do {
				$beforeText = $body;
				
				$typeName = 'delete';
				
				last CASE;
			};
		};
		
		# $h->addBody($q->p("BEFORE PART: |$beforeText|"), $q->p("AFTER PART: |$afterText|"));
		
		# Add a row for the line numbers, keep the same row number for the next row
		push @{$results}, [
			'line',
			$rowNum,
			$beforeLineNum,
			$beforeMethodType,
			$beforeMethodName,
			$afterLineNum,
			$afterMethodType,
			$afterMethodName
		];
		
		# Add a row for the side by side comparison
		push @{$results}, [
			$typeName,
			$rowNum++,
			$beforeText,
			$afterText
		];
	}
	
	# Return the side by side table
	return $results;
}

1;
