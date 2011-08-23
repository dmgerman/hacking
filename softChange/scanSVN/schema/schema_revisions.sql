--drop table revisions;
--create table revisions (
--   	filename char (140),
--	revisionid char(40),
--	daterev    date,
--	timerev    time,
--	state      char(13),
--	linesAdd integer,
--	linesRm  integer,
--	primary key (filename, revisionid),
--	foreign key (FILENAME) references files
--);


drop table revisions CASCADE;

create table revisions(
       filename   varchar(200) not null,
       revid      integer  not null,
       daterev    timestamp,
       inTrunk    boolean,
       trunkRevId integer,
       deleted    boolean,
       primary key (filename, revid),
       foreign key (FILENAME) references files
);


create index revcontents_idx2 on revisions(filename);
create index revisions_idx3 on revisions(daterev);

