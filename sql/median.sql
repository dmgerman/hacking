install the PSQL-R thing



execute this in the corresponding database

/usr/share/postgresql/9.3/extension/plr.sql 
test:

SELECT * FROM plr_environ();
SELECT load_r_typenames();
SELECT * FROM r_typenames();
SELECT plr_array_accum('{23,35}', 42);

add function

CREATE or REPLACE FUNCTION r_median(_float8) 
	returns float as 'median(arg1)' language 'plr';

CREATE AGGREGATE median (
  sfunc = plr_array_accum,
  basetype = float8,
  stype = _float8,
  finalfunc = r_median
);

CREATE OR REPLACE FUNCTION f_graph() RETURNS text AS
$BODY$

mov <- pg.spi.exec ("select rank  from roles natural join productions natural join ratings where votes > 10 order by rank;");
pdf("/tmp/myplot.pdf",width=4, height=8);
boxplot(mov$rank)
dev.off();
print("done");
$BODY$
LANGUAGE plr;

lines(d1,col="red");
boxplot(mov$rank,epi$rank,tvm$rank,main="Distribution");
#


* For interval



CREATE OR REPLACE FUNCTION _final_median_i(interval[])
   RETURNS interval AS
$$
   SELECT AVG(val)
   FROM (
     SELECT val
     FROM unnest($1) val
     ORDER BY 1
     LIMIT  2 - MOD(array_upper($1, 1), 2)
     OFFSET CEIL(array_upper($1, 1) / 2.0) - 1
   ) sub;
$$
LANGUAGE 'sql' IMMUTABLE;
 
CREATE AGGREGATE median_i(interval) (
  SFUNC=array_append,
  STYPE=interval[],
  FINALFUNC=_final_median_i,
  INITCOND='{}'
);
