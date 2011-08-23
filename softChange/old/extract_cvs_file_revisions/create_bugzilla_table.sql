
drop table tempBugs;

create temp table tempBugs (
    mrid    char(60)
);



insert into tempBugs
    select mrid from mrs2 where log ~* 'bugs? +[0-9]+'
	union
    select mrid from mrs2 where log ~* 'bugs? *# *[0-9]+'
	union
    select mrid from mrs2 where log ~ 'NEWLINE *# *[0-9]+'
	union
    select mrid from mrs2 where log ~ '# *[0-9]+'
;

create index tempbugix on tempBugs(mrid);

update mrstats set bugzilla = false;
update mrstats set bugzilla = true where mrid in (select mrid from tempBugs);
