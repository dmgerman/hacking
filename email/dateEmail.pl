use strict; 

use DateTime::Format::Mail;


while (<>) {
    chomp;
    next unless -f $_;
    my $fname = $_;
    my $date = Extract_Date($fname);

    $date =~ s/\(PST\)$//;

    my $datetime;

    eval {$datetime =  DateTime::Format::Mail->parse_datetime($date); };
    
    if (defined($datetime)) {
	print $datetime->ymd(';'), ";$fname\n"; 
    }

}

# my $datetime = DateTime::Format::Mail->parse_datetime(

# 


sub Extract_Date
{
    my ($f) = @_;
    open(IN, "<$f") || die "Unable to open [$f]";
    while (<IN>) {
	chomp;
	if (/^Date: (.+)$/i) {
	    return $1;
	}
    }
    close IN;
    return undef;
}
