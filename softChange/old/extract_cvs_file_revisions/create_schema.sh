#!/bin/bash

BASE='/Users/dmg/local/softChange/extract_cvs_file_revisions/schema/';

psql ${1} < ${BASE}/FileRevisions.sql

psql ${1} < ${BASE}/revdefs.sql

psql ${1} < ${BASE}/revisiondiffs.sql

psql ${1} < ${BASE}/cleanseddiffs.sql


