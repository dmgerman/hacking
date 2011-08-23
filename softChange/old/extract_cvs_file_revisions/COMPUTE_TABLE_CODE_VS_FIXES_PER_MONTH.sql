

create temp table monthfixes as select date_trunc('month', daterev) as month from mrs2 where mrid in (select mrid from mrstats where not branch and code and defectfix );

create temp table monthbugs as select date_trunc('month', daterev) as month from mrs2 where mrid in (select mrid from mrstats where not branch and code and bugzilla );

create temp table monthmrs as select date_trunc('month', daterev) as month from mrs2 natural join mrstats mrstats where code and not branch; 

select month, bugzillas, fixes, codemrs, bugzillas/(codemrs*1.0), fixes/(codemrs*1.0) as buggy  from (select month, count(*) as bugzillas from monthbugs group by month) as rip0 natural full outer join (select month, count(*) as fixes from monthfixes group by month) as rip1 natural join (select month, count(*) as codemrs from monthmrs group by month) as rip2 order by month;


drop table monthfixes;
drop table monthbugs;
drop table monthmrs;


--create temp table monthfixes as select date_trunc('week', daterev timestamp without time zone 'UTC') as month from mrs2 where mrid in (select mrid from mrstats where not branch and code and defectfix );

--create temp table monthbugs as select date_trunc('year', daterev) as month from mrs2 where mrid in (select mrid from mrstats where not branch and code and bugzilla );

--create temp table monthmrs as select date_trunc('year', daterev) as month from mrs2 natural join mrstats mrstats where code and not branch; 


--select month, bugzillas, fixes, codemrs, bugzillas/(codemrs*1.0), fixes/(codemrs*1.0)  from (select month, count(*) as bugzillas from monthbugs group by month) as rip0 natural full outer join (select month, count(*) as fixes from monthfixes group by month) as rip1 natural join (select month, count(*) as codemrs from monthmrs group by month) as rip2 order by month;



