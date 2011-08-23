default: none

all: meta filesmod files summaries log

meta:
	printf "drop table metadata;create table metadata(cid char(40), author varchar(100), dateauthor timestamp, committer varchar(100), datecomm timestamp, merge boolean);" | psql ${DB}
	cp meta.txt /tmp/rip.txt 
	chmod 0644 /tmp/rip.txt
	printf "SET CLIENT_ENCODING TO 'LATIN1';copy metadata from '/tmp/rip.txt' with delimiter ';';" | psql ${DB}
	printf "create index metacididx on metadata(cid);" | psql ${DB}

parents:
	printf "drop table parents;create table parents(cid char(40), parent char(40));" | psql ${DB}
	cp parents.txt /tmp/rip.txt
	chmod 0644 /tmp/rip.txt
	printf "SET CLIENT_ENCODING TO 'LATIN1';copy parents from '/tmp/rip.txt' with delimiter ';';" | psql ${DB}
	printf "create index parentsidx on parents(cid);" | psql ${DB}
	printf "create index parentsidx2 on parents(parent);" | psql linux


filesmod:
	printf "drop table filesmod;create table filesmod(cid char(40), filename varchar(150), linesadd integer, linesrem integer);" | psql ${DB}
	cp files.txt /tmp/rip.txt 
	chmod 0644 /tmp/rip.txt
	printf "copy filesmod from '/tmp/rip.txt' with delimiter ';' null as '';" | psql ${DB}

files:
	printf "drop table files;create table files(filename varchar(150), basename varchar(100), ext char(20), source boolean);" | psql ${DB}
	cut -d ';' -f 2 files.txt | sort -u | perl ../pg/filetypes.pl > /tmp/rip.txt
	chmod 0644 /tmp/rip.txt
	printf "copy files from '/tmp/rip.txt' with delimiter ';' null as '';" | psql ${DB}
	printf "create index filesidx on files(filename);" | psql ${DB}

summaries:
	printf "drop table commitsum;" | psql ${DB}
	printf "create table commitsum as select cid, sum(linesadd) as sumadd, sum(linesrem) as sumrem, count(*) as countfiles from filesmod  natural join files where source group by cid;" | psql ${DB}


log:
	printf "drop table log;" | psql ${DB}
	printf "create table log(cid char(40), log text);" | psql ${DB}
	cp logs.txt /tmp/rip.txt 
	chmod 0644 /tmp/rip.txt
	printf "SET CLIENT_ENCODING TO 'LATIN1';copy log from '/tmp/rip.txt' with delimiter ';' null as '';" | psql ${DB}
	printf "create index logindex on log(cid);" | psql ${DB}

egos:
	printf "drop table egos;" | psql ${DB}
	printf "create table egos(email varchar(100),ego varchar(100));" | psql ${DB}
	perl -pe 's/\\//g' egos.txt > /tmp/rip.txt 
	printf "SET CLIENT_ENCODING TO 'UTF-8';copy egos from '/tmp/rip.txt' with delimiter ';' null as '';" | psql ${DB}
	printf "create index egosidx on egos(email);" | psql ${DB}

temp:
	printf "create index metacididx on metadata(cid);" | psql ${DB}

