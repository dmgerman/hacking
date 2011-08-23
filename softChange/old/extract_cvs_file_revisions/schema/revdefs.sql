drop table revdefs;

create table revdefs (
    filename character(150),
    revisionid character(10),
    line      integer,
    cleanline integer,
    length    integer,
    definition character(150),
    index    integer, --used to avoid duplicates
    typedef character(20),
    constraint revdefskey primary key (filename,revisionid,definition,index)
);

