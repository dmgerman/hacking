--
--drop table mrs2;
--create table mrs2 (
--   	mrid char (60),
--	daterev    date,
--	timerev    time,
--	author     char(50),
--	log        text,
--	primary key (mrid)
--);
--


drop table mrs;

create table mrs (
	mrid  integer NOT NULL,
	datemr timestamp NOT NULL,
	author varchar(50) NOT NULL,
	log text,
	primary key (mrid)
	);
