create temp table month as select date_trunc('month', daterev) as month, sizecleandiffs from mrs2 where mrid in (select mrid from mrstats where not branch and code and defectfix );
