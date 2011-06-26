drop table if exists clones;

create table clones (
       revid    integer,
       cloneset integer,
       filename varchar(80),
       tokenbegin integer,
       tokenend   integer,
       tokenlen   integer,
       linebegin  integer,
       lineend    integer,
       columnbegin integer,
       columnend   integer,
       bytebegin   integer,
       byteend     integer
       );

       
