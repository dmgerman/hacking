drop table clonesets;
drop table clones;
drop table ccparse;
create table ccparse (
       filename varchar(140),
       revision varchar(60),
       parsing  text,
       primary key (filename, revision),
       foreign key (filename, revision) references revisions
       );

drop table ccraw;
create table ccraw (
       mrid      varchar(60),
       clonesCount integer,
       ccrawdata text,	
       ccpretty  text,
       primary key (mrid),	
       foreign key (mrid) references mrs
);


create table clonesets (
       mrid varchar(60),
       cloneset integer,
       primary key (mrid,cloneset)
);

create table clones (
       mrid varchar(60),
       cloneno integer,
-- location
       begline integer,
       begcol  integer,
       begtok  integer,
       endline integer,
       endcol  integer,
       endtok  integer,
-- where
       filename varchar(140),
       cloneset integer,
       deleted boolean,
       primary key (mrid, cloneno),
       foreign key (mrid, cloneset) references clonesets,	
       foreign key (filename) references files,
       foreign key (mrid)  references mrs
);
