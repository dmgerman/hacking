drop table functions;

create table functions (
    filename   character(150),
    revisionid character(10),
    datetime   timestamp,
    definition character(150),
    index      integer, --used to avoid duplicates
    body       text,
    diff       text,
    typedef    character(20),
    prevchangedrevisionid character(150),
    prevchangedfilename character(10),
    constraint functionskey primary key (filename,revisionid,definition,index)
);

