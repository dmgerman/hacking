drop view filesalive;
create view filesalive as select * from files where inattic = 0;


drop view filesdead;
create view filesdead as select * from files where inattic = 1;


