install the PSQL-R thing



execute this in the corresponding database

/usr/share/postgresql/8.4/plr.sql

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
