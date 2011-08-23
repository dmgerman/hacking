drop table foo cascade;
create table foo(trank integer);

CREATE OR REPLACE FUNCTION getAllR() RETURNS SETOF foo AS
'
DECLARE
    r foo%rowtype;
    i integer;
BEGIN
    FOR i IN 1..10
    LOOP
        r.trank = i;
        RETURN NEXT r; -- return current row of SELECT
    END LOOP;
    RETURN;
END
'
LANGUAGE 'plpgsql' ;

--
-- 
select * from getAllR();

select * from getAllR()  natural full join rtypes;
