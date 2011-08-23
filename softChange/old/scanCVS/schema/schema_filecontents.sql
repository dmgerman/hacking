--
drop table revcontents;

create table revcontents(
	filename varchar(140) NOT NULL,
	revid    varchar(40) NOT NULL,
	contents TEXT,
	clean    TEXT,
	primary key (filename, revid),
	foreign key (filename,revid) references revisions,
	foreign key (filename) references files
);

