drop table FileRevisions;

create table FileRevisions (
	filename char(256),
	revisionid char(20),
	state    integer,
	cleanLines integer,
	newfile  text,
	syntaxerror integer,
	cleanfile  text,
	CONSTRAINT FileRevisionsKey PRIMARY KEY (filename,revisionid)
);






