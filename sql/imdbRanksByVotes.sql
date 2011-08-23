drop table ranksbyvotes cascade;
drop table rankhist cascade;

create table ranksbyvotes (rank float, count  integer);
create table rankhist (rank float, count integer, accum bigint, prop numeric, propacum numeric);


CREATE OR REPLACE FUNCTION imdbranksbyvotes(integer)
RETURNS SETOF ranksbyvotes
AS
$$
select rank, cast(count(*) as integer) as count 
FROM imdbratings as i NATURAL JOIN productions 
WHERE type is null and votes >= $1 
GROUP BY rank;
$$
LANGUAGE SQL;


CREATE OR REPLACE FUNCTION imdbrankhis(integer)
RETURNS SETOF rankhist
AS
$$

select r.*,round(r.count*100.0/r3.all,2) as prop, round(r.acum*100.0/r3.all,2) as propacum 
from 
    (select r1.rank, r1.count, sum(r2.count) as acum from 
         (select * from imdbranksbyvotes($1)) as r1, 
         (select * from imdbranksbyvotes($1)) as r2  
        where r1.rank >= r2.rank group by r1.rank, r1.count) as r, 
    (select sum(count) as all  from imdbranksbyvotes($1)) as r3 order by rank;
$$
LANGUAGE SQL;
