drop table if exists clonechanges;

create table clonechanges (
       revid    integer,
       cloneset integer,
       filename varchar(80),
       tokenbegin integer,
       typemod   char
       );

       
