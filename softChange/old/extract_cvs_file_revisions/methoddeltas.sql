
--How to know how many things have been added in a given delta


--This is the count of things of type method

drop table temp;

create table temp as
select filename, revisionid, typedef, count(*) from revdefs 
where typedef in ('method', 'function')
group by
filename, revisionid, typedef ;


-- this creates a table with the previous and new values

drop table methoddeltas;


create table methoddeltas (
       filename char(120),
       revisionid char(30),
       datetime timestamp,
       prevrevisionid char(30),
       methodsafter  integer,
       methodsbefore integer,
       methodsadded   integer,
       methodsdeleted integer
);

--

insert into methoddeltas(filename, revisionid, datetime, prevrevisionid, 
                         methodsafter, 
                         methodsbefore) 
select r.filename, r.revisionid, datetime, 
      prevrevisionid, t1.count as after, 
      t2.count as before 
from revisiondiffs as r, 
       temp as t1, temp as t2
where prevrevisionid is not null and 
      t1.filename = r.filename and
      t1.revisionid = r.revisionid and 
      r.filename = t2.filename and 
      r.prevrevisionid = t2.revisionid 

UNION 

select r.filename, r.revisionid, datetime, NULL, t1.count as after, 0 as before
from revisiondiffs as r, temp as t1 
where prevrevisionid is null and
     t1.filename = r.filename and t1.revisionid = r.revisionid 

;

-- Now we have to add the number of methods added

update methoddeltas  set methodsadded = (select count(*) from 
   (select distinct definition from revdefs r
    where methoddeltas.filename = r.filename and
          methoddeltas.revisionid = r.revisionid and
          r.typedef in ('method','function')
    EXCEPT
    select distinct definition from revdefs r
    where methoddeltas.filename = r.filename and
          methoddeltas.prevrevisionid = r.revisionid and
          r.typedef in ('method','function')
    ) as rip )
;

-- ANd then removed


update methoddeltas  set methodsdeleted = (select count(*) from 
   (select distinct definition from revdefs r
    where methoddeltas.filename = r.filename and
          methoddeltas.prevrevisionid = r.revisionid and
          r.typedef in ('method','function')
    EXCEPT
    select distinct definition from revdefs r
    where methoddeltas.filename = r.filename and
          methoddeltas.revisionid = r.revisionid and
          r.typedef in ('method','function')
    ) as rip )
;




--A need a table with the filename, revisionid, author

drop table revisionauthor;

create table revisionauthor as select filename, revisionid, author from mrsfiles, mrs2 where mrs2.mrid = mrsfiles.mrid;


--

----------------------------------------------------------------------
--select sum(m.after-m.before) as diff, author 
--from methoddeltas as  m,
--    revisionauthor where revisionauthor.filename = m.filename and
--    m.revisionid = revisionauthor.revisionid  group by author;
----------------------------------------------------------------------

