

sub Report_Cloned_Sections
{
    my ($file, $ref) = @_;

    
    # count the number of tokens in the list
    my $count;
    foreach my $i (0..scalar(@$ref)/2-1) {
        $count +=$$ref[2*$i+1] - $$ref[2*$i] + 1;
    }
    print "$file;$count;";
        
    print join(':', @$ref);
}



sub Insert_In_Section
{
    my ($ref, $begin, $end) = @_;
#    print "Value [$begin:$end]\n";
    foreach my $i (0..scalar(@$ref)/2-1) {
#        print "Trying to insert: $i -> ", $$ref[2*$i], ";", $$ref[2*$i+1], "\n";
        if ($$ref[2*$i] > $begin ) {
            # current record is before than one to insert
            if ($$ref[2*$i] > $end) {
                # we must insert before this one
                splice(@$ref, 2*$i, 0, ($begin, $end));
            } else {
                # we must expand the current one
                $$ref[$2*$i] = $begin;
            }
            return;
        } else {
            # the only thing we have to worry about is expanding the length of the current record
            # does it begin inside it?
            if ($begin <  $$ref[2*$i+1] ) {
                # does it end outside it
 #               printf("it begins within it it\n");
                if ($end > $$ref[2*$i+1]) {
                    # then expand it
                    $$ref[2*$i+1] = $end;
                    # and now we have to check that the next one is not overlapping
                    while (defined($$ref[2*$i+2]) && $$ref[2*$i+2] < $$ref[$2*$i+1]) {
                        # the next one is overlapping
                        if ($$ref[2*$i+3] > $$ref[2*$i+1]) {
                            $$ref[2*$i+1] = $$ref[2*$i+3];
                        }
                        splice(@$ref, 2*$i+2, 2);
                    }

                } else {
                    # otherwise it is inside it
 #                   print "It is inside it\n";
                }
                return;

            }
        }
    }
    ## not found, insert at the end
    push(@$ref, ($begin, $end));
}


sub Report
{
    print join(';', @_), "\n";
}

1;
