

# Run the commands in the following order

extractFilesRevisionsFromCVS.pl ${1}.log

normalizeFiles.pl cvs.files

extractMRs.pl cvs.revisions

normalizeMRs.pl cvs.mrs 
normalizeRevisions.pl cvs.revisions

#load_data_into_database.pl $1

