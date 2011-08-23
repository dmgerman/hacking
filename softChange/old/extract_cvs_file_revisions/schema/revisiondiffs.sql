drop table revisiondiffs;

create table  revisiondiffs (
    filename character(150),
    revisionid character(40),
    datetime   timestamp,
    prevfilename character(150),
    prevrevisionid character(10),
    pluslines      integer,
    minuslines     integer,
    changedLines   integer,
    diff           text,
    diffClean      text
);

