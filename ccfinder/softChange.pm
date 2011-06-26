#!/usr/bin/perl

package softChange;


use strict;
use DBI;

sub new
{
    my ($class,$dbName) = @_;
    my $userName = 'dmg';
    
    my $dbh = DBI->connect("dbi:Pg:dbname=$dbName", "$userName", "",
		       { RaiseError => 1});

    my $self = {
        _db => $dbName,
        _dbh => $dbh,
    };
    
    bless $self, $class;
    
    return $self;
}

sub Get_Files_in_MR_FuncMod
{
    my ($self, $rev,$typeModExpr) = @_;

    if ($typeModExpr eq "") {
        $typeModExpr = "typemod <> 'I'";
    }

    my $sth = $self->{_dbh}->prepare("select distinct filename from funcmod where revid = ? and $typeModExpr;");
    my $rc = $sth->execute($rev);
    my @row;
    my @result;
    while ( @row = $sth->fetchrow_array ) {
#	print"File in MR: $row[0]\n";
	push @result, $row[0];
    }
    return @result;
}

sub Get_MRs_FuncMod
{
    my ($self) = @_;
    my $sth = $self->{_dbh}->prepare("select distinct revid from funcmod where filename ~ 'src/backend/optimizer' order by revid ;");

    my $rc = $sth->execute;

    my @row;
    my @revs;
    while ( @row = $sth->fetchrow_array ) {
#    print "$row[0]\n";
        push @revs, $row[0];
    }
    return @revs;
}


sub Get_File_Previous_Revision
{
    my ($self, $file, $rev) = @_;
    my @row;

#    print "File [$file][$rev]\n";

    my $sth = $self->{_dbh}->prepare("select distinct filename, revid from funcmod where filename = ? and revid < ?");
    my $rc = $sth->execute($file,$rev);
    if ( @row = $sth->fetchrow_array ) {
        return $row[1];
    } else {
        return undef;
    }
}



sub Close
{
    my ($self) = @_;
    $self->{_dbh}->disconnect();
}


1;

