-- This is the old schema
--drop table files;
--create table files (
--   	filename char (140),
--   	basename char (100),
--	extension char(10),
--	directory char(110),
--	latestversion char(10),
--
--	branchversion char(10),
--	totalrevisions integer,
--        selectedrevisions integer,
--	inattic        integer,
--	rcsFileName    char(200),
--        module    char(20),
--	primary key (filename)
--);
--
--

drop table files CASCADE;

create table files(
       	filename varchar(140) not null,
       	basename varchar(80),
       	extension varchar(10),
       	directory varchar(140),
       	inattic   boolean,
	primary key (filename)
       );
