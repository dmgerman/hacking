#!/usr/bin/perl

#$p = perMRdiff->new('/tmp/save', "", "AnyMod", "lcms");
#$p->process();
#$p->destroy();
#exit;
#print "--------------------------------------------------\n";

$p = perMRdiff->new('/tmp/save', "", "CodeMod", "lcms");
$p->process();
$p->destroy();

exit;

package perMRdiff;              #This class is called Person::Male

#use strict;


BEGIN{@ISA = qw ( perMR );}       #Declare this a child of the Person class

sub Per_MR
{
    my ($self, $mr)  = @_;    
    print "childMR -> [$mr]\n";
}

sub insert_hunk
{
    my ($self, $filename, $mr, $prevMr, $from, $sizeFrom, $to, $sizeTo)  = @_;    

    my $sth = $self->{dbh}->prepare("
    insert into filediffs(filename, revid, prevrev, beforeFrom, beforeSize, afterFrom, afterSize) values
        (?,?,?,?,?,?,?);");
    my $rc = $sth->execute($filename, $mr,$prevMr, $from, $sizeFrom, $to, $sizeTo) ;
}



sub process_file
{

    my ($self, $mr, $filename, $prevMr)  = @_;    
    die "MR file does not exist [$mr/$filename]" unless -f "$mr/$filename";
    die "MR file does not exist [$prevMr/$filename]" unless $prevMr eq "" or -f "$prevMr/$filename";
    print "Filename: [$filename] prev [$prevMr]\n";
    if ($prevMr ne "") {
        my $diffCmd = "diff -d -U0 '$prevMr/$filename'  '$mr/$filename' | grep '^\@\@' ";
        open(IN, "$diffCmd | ");
        while (<IN>) {
            # match @@ -39,6 +42,4... or @@ -39 +42...
            die unless /^@@\ -([0-9]+)(?:,([0-9]+))?\ \+([0-9]+)(?:,([0-9]+))?\ @@$/x;
            my $from = $1;
            my $sizeFrom = $2;
            $sizeFrom = 1 if ($sizeFrom eq "") ;
            my $to = $3;
            my $sizeTo = $4;
            $sizeTo = 1 if ($sizeTo eq "") ;
            $self->insert_hunk($filename, $mr, $prevMr, $from, $sizeFrom, $to, $sizeTo);
        }
        close IN;
    }
    
}



package  perMR;

use  DBI;
use strict;


sub connect
{
    my ($self) = @_;
    my $dbName = $self->{db};
    my $userName = "dmg";
    my $password = "";
    $self->{dbh} = DBI->connect("dbi:Pg:dbname=$dbName", 
                           $userName, $password,
                           { RaiseError => 1});
    if (not defined($self->{dbh})) {
        die;
    }
}

sub new
{
    my ($class, $dir, $filesRegExp,$doEachFile,$db) = @_;

    my $self;
    $self->{dir}= $dir;
    $self->{db} = $db;

    if (!-d $dir) {
        die "directory with source [$dir] does not exist";
    }
    chdir $dir;

    $self->{eachFile} = $doEachFile;


    $self->{filesRegExp} = $filesRegExp;
    die "No database specified [$db]" if $db eq "";


    # Open databases

    bless $self, $class;
    $self->connect();
    return $self;
}


sub destroy
{
    #    close  connection to database
    my ($self)  = @_;    

    $self->{dbh}->disconnect;
}

sub Per_MR
{
    my ($self, $mr)  = @_;    
    
    print "MR -> [$mr]\n";

}

sub do_query_mrs
{
    my ($self)  = @_;    

    # set the query for mrs
    my $sth = $self->{dbh}->prepare("select distinct revid from funcmod order by revid ;");

    my $rc = $sth->execute;
    return $sth;
}

sub expr_types_changes
{
    my ($self)  = @_;    

    my $restExpr = "";
    
    if ($self->{eachFile} eq "AnyMod") {
        ;
    } elsif ($self->{eachFile} eq "CodeMod") {
        $restExpr = " and (typemod <> 'I')";
    } else {
        die "Invalid spec for what to do [" . $self->{eachFile} . "]";
    }
    return $restExpr;

}


sub do_query_mrs_files
{
    my ($self, $mr)  = @_;    


    my $restExpr = $self->expr_types_changes();

    # set the query for mrs
    my $sth = $self->{dbh}->prepare("select distinct filename from funcmod where revid = ?  $restExpr order by filename;");

    my $rc = $sth->execute($mr);
    return $sth;
}

sub process_file_find_prev
{
    my ($self, $mr, $filename)  = @_;    

    my $restExpr = $self->expr_types_changes();
    
    # set the query for mrs
    my $sth = $self->{dbh}->prepare("select distinct revid from funcmod where revid < ? and filename = ? $restExpr order by revid desc limit 1");
    my $rc = $sth->execute($mr, $filename);
    my @row  = $sth->fetchrow_array();
    return $row[0];
}

sub process_file
{
    my ($self, $mr, $filename, $prev)  = @_;    

     print "Filename: [$filename] prev [$prev]\n";
}


sub process_files
{
    my ($self, $mr)  = @_;    
    my $sth = $self->do_query_mrs_files($mr);
    my @row;
    while (@row = $sth->fetchrow_array) {# there are mrs
        if (($self->{filesRegExp} eq "") or #if no expression given
            ($row[0] =~ /$self->{filesRegExp}/)) {
            my $prev = $self-> process_file_find_prev($mr, $row[0]);
            $self->process_file($mr,$row[0], $prev);            
        }
    }
}


sub process
{
    my ($self)  = @_;    
    #query MRs
    
    my $sth = $self->do_query_mrs();
    my @row;
    while (@row = $sth->fetchrow_array) {# there are mrs
        #change current directory to where the MR is
        $self->Per_MR($row[0]);

        if ($self->{eachFile} ne "") {
            $self->process_files($row[0]);
        }
    }
}
