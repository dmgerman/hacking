-- these are mrs that are source code and include new file

drop table ripmrs;
drop table friends;
drop table friends2;
drop table rip2;


create temp table ripmrs as 

   select mrid from mrsfiles natural join files where (extension = '.c' or extension = '.h' or extension = '.java') and revisionid = '1.1'

   union
-- these are mrs that are source code and include new file

   select mrid from mrsfiles natural join files natural join revisions where (extension = '.c' or extension = '.h' or extension = '.java' and revisionid = '1.1') and state = 'dead'
;


create temp table rip2 as
 select mrid from mrstats where code and (not branch) and (not comment) and (filescount <= 20)
   EXCEPT
 select mrid from ripmrs ;

create table workingset as select * from rip2;

create table friends2 as 
     select f1. mrid, 
        substring(f1.filename, '^src/(.*)') as filename, 
        substring(f2.filename, '^src/(.*)') as friend from mrsfiles f1, mrsfiles f2, rip2 as r where f1.mrid = r.mrid and f1.mrid = f2.mrid and f1.filename <> f2.filename and trim(f1.filename) ~ '\\.[ch]$' and trim(f2.filename) ~ '\\.[hc]$';



create table friends as 
     select f1. mrid, 
 	f1.filename as filename, 
        fi1.basename as basename,
        fi1.extension as extension,
        f2.filename as friend,
        fi2.basename as friendbase,
        fi2.extension as friendext
    from mrsfiles f1, mrsfiles f2, rip2 as r, files as fi1, files as fi2
    where 
        f1.mrid = r.mrid and f1.mrid = f2.mrid and 
        f1.filename = fi1.filename and f2.filename = fi2.filename and
        f1.filename <> f2.filename and trim(f1.filename) ~ '\\.[ch]$' and trim(f2.filename) ~ '\\.[hc]$';

