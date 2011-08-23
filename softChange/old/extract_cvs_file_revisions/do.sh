#!//bin/bash

create_schema.sh ${1}


populate_revisions.pl --database=${1} --moduleDir=${1}

add-linesadded-to-first-revision.pl --database=${1}

add-cleanlocs-to-filerevisions.pl --database=${1}

populate_diffs.pl --database=${1}

psql ${1} < populate_size_diffs_first_revision.sql

add-definitions.pl ${1}

add-length-of-definition.pl ${1}


psql ${1} < methoddeltas.sql

psql ${1} < mrs_stats.sql
