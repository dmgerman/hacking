drop table filediffs;

create table filediffs (
        filename varchar(140),
        revid integer,
        prevrev integer,
        beforeFrom integer,
        beforeSize integer,
        afterFrom integer,
        afterSize integer
);
