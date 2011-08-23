
-- We need to create some stats about each mr
--
drop table extensions ;

create table extensions (
     extension char(10),
     code      boolean
);

insert into extensions values ('.c', true);
--insert into extensions values ('.pl', true);
--insert into extensions values ('.cpp', true);
insert into extensions values ('.h', true);
insert into extensions values ('.java', true);


drop table mrstats;

create table mrstats (
	mrid char(60),
	code boolean,
        branch boolean,
	comment boolean,
	filesCount integer,
	sourceFilesCount integer,
	filesAdded   integer,
	filesRemoved integer,
	methodsadded integer,
	methodsremoved integer,
	methodsmodified integer,
	sizeDiffs     integer,
	sizeCleanDiffs     integer,
	linesadded    integer,
	linesremoved  integer,
	linesnet  integer,
	bugzilla  boolean,
	defectFix  boolean
);


--
-- Populate the table first

insert into mrstats(mrid) select mrid from mrs2;

-- recompute stats
--vacuum full analyze;

-- Determine if it is code

update mrstats set code = true where mrid in (select distinct mrid from mrsfiles m, files f where m.filename = f.filename and f.extension in (
	select extension from extensions where code));

-- Count files

update mrstats   set filesCount = (select count(filename) from  mrsfiles m where m.mrid = mrstats.mrid);

-- Find out hoe many files were added

update mrstats   set filesAdded = (select count(filename) from  mrsfiles m where m.mrid = mrstats.mrid and m.revisionid = '1.1');

-- Find out how many files were killed

update mrstats   set filesRemoved = (select count(*) from mrsfiles m, files f where m.filename = f.filename and m.revisionid = f.latestversion and f.inattic = 1 and m.mrid = mrstats.mrid);


-- Find out how many methods were added in the revision

update mrstats   set methodsAdded = (select sum(methodsadded) from  mrsfiles f, methoddeltas d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid);

-- Find out how many methods were removed in the revision

update mrstats   set methodsremoved = (select sum(methodsdeleted) from  mrsfiles f, methoddeltas d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid);


-- diffs

update mrstats   set sizeDiffs = (select sum(length(diff)) from  mrsfiles f, revisiondiffs d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid);

-- diffclean

update mrstats   set sizeCleanDiffs = (select sum(length(diffclean)) from  mrsfiles f, revisiondiffs d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid);

-- find out how many source files are involved

update mrstats   set sourcefilesCount = (select count(m.filename) from  mrsfiles m, files f, extensions e where m.filename = f.filename and f.extension = e.extension and e.code and m.mrid = mrstats.mrid);



-- branch

update mrstats set branch = false;

update mrstats set branch = true where exists  (select * from mrsfiles where mrsfiles.mrid = mrstats.mrid and  revisionid ~  '[0-9]\\.[0-9]+\\.');

--lines added

--update mrstats   set linesadded = (select sum(linesadd) from  mrsfiles f, revisions d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid group by f.mrid);

--update mrstats   set linesremoved = (select sum(linesrm) from  mrsfiles f, revisions d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid group by f.mrid);

--update mrstats   set linesnet = (select sum(linesadd+linesrm) from  mrsfiles f, revisions d where f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid);

--update mrstats   set linesremoved = (select sum(linesrm) from  mrsfiles f, revisions d, files f2, extensions e where f.filename = f2.filename and f2.extension  = e.extension and e.code  and f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid group by f.mrid);


-- ONLY C and H

-- update mrstats   set linesremoved = (select sum(linesrm) from  mrsfiles f, revisions d where trim(f.filename)  ~ '\\.[ch]' and f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid group by f.mrid); 


update mrstats   set linesremoved = (select sum(linesrm) from  mrsfiles f, revisions d, files f2, extensions e where f.filename = f2.filename and f2.extension  = e.extension and e.code  and f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid group by f.mrid);

update mrstats   set linesadded = (select sum(linesadd) from  mrsfiles f, revisions d, files f2, extensions e where f.filename = f2.filename and f2.extension  = e.extension and e.code  and f.filename = d.filename and f.revisionid = d.revisionid and mrid = mrstats.mrid group by f.mrid);

update mrstats set linesnet = linesadded + linesremoved;


--- Add comment MRS

-- Create table with clean revisions

create temp table cleancoderevisions as 
	select filename, revisionid from revisiondiffs natural join files natural join extensions where length(diffclean) = 0 and code ;

-- create an index
create index clrevidx on cleancoderevisions(filename, revisionid);

-- find mrs that are code, and  not comment
create temp table mrscodenotcomment as
select distinct mrid from mrstats m natural join mrsfiles f natural join files natural join extensions e where e.code and  code and not exists (select * from cleancoderevisions c where f.filename = c.filename and f.revisionid = c.revisionid);


update mrstats set comment = false where code;
update mrstats set comment = true where code and not mrid in (select mrid from mrscodenotcomment);




