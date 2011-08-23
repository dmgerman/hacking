#!/usr/bin/perl -w

use strict;
use File::Basename;

my $dir = $0;
my $debug = 1;

my $distDir = dirname($dir);

my $baseDir = `pwd`;
chomp $baseDir;

print "Current directory [$baseDir]\n";

my $exec = $0;

my $saveDir = `pwd`;
chomp $saveDir;

my $base = dirname($exec);

chdir($base)  or die "Unable to change to directory [$base]\n";

die "Illegal parameters $0 <databasename> \n" unless $ARGV[0] ne "";

my $db = $ARGV[0];

#`dropdb $db`;

#`createdb $db`;

# create databases


`psql $db < ${distDir}/schema/schema_files.sql`;


`psql $db < ${distDir}/schema/schema_revisions.sql`;


`psql $db < ${distDir}/schema/schema_mrs.sql`;


`psql $db < ${distDir}/schema/schema_filemrs.sql`;

chdir($saveDir)  or die "Unable to change back to directory [$saveDir]\n";


`psql $db <  cvsNORM.files > /dev/null`;
`psql $db <  cvsNORM.revisions > /dev/null`;
`psql $db <  cvsNORM.mrs > /dev/null`;
`psql $db <  cvsNORM.filesmrs > /dev/null`;


# First create tables


