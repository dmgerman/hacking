drop table if exists clonesets;

create table clonesets (
       revid    integer,
       cloneset integer,
       filename varchar(80),
       tokenbegin integer,
       md5      char(32)
       );

       
