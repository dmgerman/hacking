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

CREATE OR REPLACE FUNCTION f_graph() RETURNS text AS
$BODY$
mov <<- pg.spi.exec ("select rank  from roles natural join productions natural join ratings where votes > 100 and attr is null order by rank;");
epi <<- pg.spi.exec ("select rank  from roles natural join productions natural join ratings where votes > 100 and attr = 'TVEpisode' order by rank;");
tvm <<- pg.spi.exec ("select rank  from roles natural join productions natural join ratings where votes > 100 and attr = 'TV' order by rank;");
mov2 <<- as.numeric(mov$rank)
epi2 <<- as.numeric(epi$rank)
movies<-density(mov$rank)
episodes<-density(epi$rank)
pdf("/tmp/myplot.pdf");
hist(mov2,col="blue");
hist(epi2,add=T,col="red");
line
dev.off();
print("done");
$BODY$
LANGUAGE plr;

lines(d1,col="red");
boxplot(mov$rank,epi$rank,tvm$rank,main="Distribution");
#

