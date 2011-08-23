drop table friendshcstats;
drop table friendsstats;
drop table friendsratio;
drop table friendshipgraph;
drop table temp5;


create table friendshcstats as
  select filename, count(distinct mrid) from friends where mrid ~ '1997/' and basename = friendbase and extension = '.h' and  friendext = '.c' group by filename
;

create table friendsstats as
  select filename, count(distinct mrid) from friends where mrid ~ '1997/' and extension = '.h' group by filename;


create table friendsratio as 
   select trim(f.filename), h.count as h, f.count as total, (1.0 *  h.count)/f.count as ratio from friendshcstats h, friendsstats f where f.filename = h.filename order by ratio;

create temp table  temp5 as select ratio, count(*) from (select round(5 * round(ratio*20)/1) as ratio from friendsratio ) as rip group by ratio;

create table friendshipgraph as
   select ratio, sum, total, (sum*1.0/total) as accum from (select ratio, sum(c2) from (select t1.ratio, t2.ratio as t2, t1.count, t2.count as c2 from temp5 t1, temp5 t2 where t2.ratio <= t1.ratio order by t1.ratio) as rip  group by ratio) as rip3, (select sum(count) as total from temp5) as rip33;
