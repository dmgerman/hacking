drop table mAddStats;
drop table mAddBugsStats;
drop table mRmStats;
drop table mRmBugsStats;



create table mAddBugsStats as
 select methodsadded, count(*) from  mrstats natural join workingset  where methodsadded is not null and mrid ~ '1998/' and bugzilla and code and not branch and filescount< 20 group by methodsadded order by methodsadded;

create table mAddStats as
 select methodsadded, count(*) from  mrstats natural join workingset  where methodsadded is not null and mrid ~ '1998/' and code and not branch and filescount< 20 group by methodsadded order by methodsadded;


create table mRmBugsStats as
 select methodsremoved, count(*) from  mrstats natural join workingset  where methodsremoved is not null and mrid ~ '1998/' and bugzilla and code and not branch and filescount< 20 group by methodsremoved order by methodsremoved;

create table mRmStats as
 select methodsremoved, count(*) from  mrstats natural join workingset  where methodsremoved is not null and mrid ~ '1998/' and code and not branch and filescount< 20 group by methodsremoved order by methodsremoved;


