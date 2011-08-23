#!/usr/bin/perl -w

package htmlrevisiondiffs;
use strict;
use hardcode;
use Exporter;

our (@ISA, @EXPORT);
@ISA = 'Exporter';

@EXPORT = (
	'revisionDiffs'
);

=head1 html class : C<htmlrevisiondiffs.pm>

=head2 Uses: C<Exporter.pm>, C<hardcode.pm>

=head2 Requires: C<none>

=head2 Pragmas: C<strict>

=head3 revisionDiffs (clean : bool, previd : string, revid : string, results : [[rownum : int, rowType : string, rest : (beforeLine : int, beforeType : string, beforeName : string, afterLine : int, afterType : string, afterName : string) | (beforeText : string,  afterText : string)]]) => table : string

Add the side by side revision diffs to the body

Parameters:

=over

=item* clean => true if this is the clean source code, false if it is the original source code

=item* previd => the previous revision id

=item* revid => the current revision id

=item* results => the rowType, rownum, and rest of the information for the side by side comparison

=item* rest (rowType == line) => before and after line numbers, type (method or function or false if neither), and name

=item* rest (rowType != line) => before and after text

=back

=head4 Note: The rows are in pairs, with a row of line numbers before each row of type, name, and text

These pairs share the same line number. This is for compatibility with the C<generateHTML()> method, which can
only accept one row of data at a time.

Returns:

=over

=item* table => the table to add to the body

=back

=cut
sub revisionDiffs {
	my $this = shift;
	my $clean = shift;
	my $previd = shift;
	my $revid = shift;
	my $results = shift;
	
	# The mapping of row types to HTML classes
	my %rowClassMap = (
		'line' => 'backlines',
		'add' => 'backadded',
		'change' => 'backchange',
		'delete' => 'backdelete'
	);
	
	return $this->generateHTML(
		-results => $results,
		-columnTexts => [hardcode::colsRevisionDiffs($previd, $revid)],
		-columnClass => "backtitle$clean",
		-getRowClass => sub {
			my $row = shift;
			
			# Map the type of the row to an HTML class
			return $rowClassMap{$row->[0]};
		},
		-getRow => sub {
			(my $q, my $c, my $row) = @_;
			
			# The new row to return
			my @newRow;
			
			# If this is the 'line' type of row, then display the
			# row number, func names, etc
			if ($row->[0] eq 'line') {
				@newRow = (
					hardcode->nonBreakingSpace.
					htmlSpace($row->[1]).
					hardcode->nonBreakingSpace,
					
					# Line: <lineNum> [ Method | Function: <funcname> ]
					$q->b(
						hardcode->termLine.':&nbsp;'.
						htmlSpace($row->[2])
					).
					hardcode->nonBreakingSpace.
					($row->[3] ?
					htmlSpace(ucfirst($row->[3])).':&nbsp;'.
					$q->b(htmlSpace($row->[4])).
					hardcode->nonBreakingSpace :
					""),
					
					# Line: <lineNum> [ Method | Function: <funcname> ]
					$q->b(
						hardcode->termLine.':&nbsp;'.
						htmlSpace($row->[5])
					).
					hardcode->nonBreakingSpace.
					($row->[6] ?
					htmlSpace(ucfirst($row->[6])).':&nbsp;'.
					$q->b(htmlSpace($row->[7])).
					hardcode->nonBreakingSpace :
					"")
				);
			
			} else {
				# If this is not the 'line' type, then it must be
				# 'add', 'change', or 'delete' and the text of the change.
				# Don't display the row number, just the text.
				
				# Format the text for display in HTML
    				my $beforeText = $row->[2];
				$beforeText =~ s/\n>/\n/gm;
				$beforeText =~ s/\n</\n/gm;
				$beforeText =~ s/</&lt;/gm;
				$beforeText =~ s/>/&gt;/gm;
				
    				my $afterText = $row->[3];
				$afterText =~ s/\n>/\n/gm;
				$afterText =~ s/\n</\n/gm;
				$afterText =~ s/</&lt;/gm;
				$afterText =~ s/>/&gt;/gm;
				
				@newRow = (
					'&nbsp;',
					
					# Previous revision text
					$q->pre($beforeText),
					
					# Current revision text
					$q->pre($afterText)
				);
			}
			
			return @newRow;
		}
	);
}

1;
