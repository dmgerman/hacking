
drop table tempBugs;

create temp table tempBugs (
    mrid    char(60)
);



insert into tempBugs
    select mrid from mrs2 where log ~* 'fix'
	union
    select mrid from mrs2 where (log ~* '[^a-z]bug')
;

create index tempbugix on tempBugs(mrid);

update mrstats set defectfix = false;
update mrstats set defectfix = true where mrid in (select mrid from tempBugs);
