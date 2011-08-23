

* So we start with:

  - Extracting files that are source code only

     -- sourceFiles as a view to Files


     -- create an index in the extension, hash?

create index filesextidx on files using HASH (extension);


create table sourceFiles as select * from files where extension in ('.cpp', '.h', '.c', '.java');

create index sourceFilesidx on sourceFiles(filename);

create table sourceMRsFiles as select * from mrsfiles as m where exists (select filename from sourcefiles as s where m.filename = s.filename);

create index sourceMRsFilesidx on sourceMRsFiles(filename, revisionid);

----------------------------------------------------------------------

alter table mrstats

update mrstats   set codefilesCount = (select count(filename) from  sourcemrsfiles m where m.mrid = mrstats.mrid); 

----------------------------------------------------------------------

create table interestingmrs as select mrid from mrstats where codefilescount < 25 and codefilescount > 0; 

--

-- This table will have files and mrs that 
-- have changes made to something different than comments
-- be between 1 and 25 files long

drop table interestingmrsfiles ; 


create table interestingmrsfiles as select mrid, filename, revisionid  from interestingmrs natural join mrstats natural join mrsfiles natural join revisiondiffs where length(diffclean) <> 0 and code ;

--
create table friends as select i.mrid, i.filename, j. friend from interestingmrsfiles i, interestingmrsfiles j where i.mrid = j.mrid and i.filename <> j.filename;
