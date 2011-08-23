#!/usr/bin/Rscript

library(RdbiPgSQL)


conn <- dbConnect(PgSQL(), host="localhost", dbname="ruby", user="dmg", password="patito32")

#res <- dbSendQuery(conn, "select date, avg(churn) from (
#select extract(year from datecomm) * 12 + extract(month from datecomm) as date, sumadd-sumrem as churn  from commitsum natural join metadata 
#) as rip group by date;");
#

res <- dbSendQuery(conn, "select extract(year from datecomm) * 12 + extract(month from datecomm) as date, sumadd-sumrem as churn  from commitsum natural join metadata ;");



bydate <- dbGetResult(res)

