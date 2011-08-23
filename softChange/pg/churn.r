#!/usr/bin/Rscript


library(RdbiPgSQL)
#conn <- dbConnect(PgSQL(), host="localhost", dbname="linuxmeta", user="dmg", password="patito32")
#conn <- dbConnect(PgSQL(), host="localhost", dbname="pg", user="dmg", password="patito32")
conn <- dbConnect(PgSQL(), host="localhost", dbname="ruby", user="dmg", password="patito32")

res <- dbSendQuery(conn, "select sumadd, sumrem,sumadd+sumrem as total from commitsum natural join metadata natural join log where not merge and  log !~ 'indent' and datecomm > '2008-04-01' and datecomm < '2009-04-01' order by sumadd + sumrem");
after <- dbGetResult(res)

print("Summary after")

summary (after);

res2 <- dbSendQuery(conn, "select sumadd, sumrem,sumadd+sumrem as total from commitsum natural join metadata natural join log where not merge and  log !~ 'indent' and datecomm < '2008-04-01' and datecomm > '2007-04-01' order by sumadd + sumrem");
before <- dbGetResult(res2)

print("Summary before")
summary(before)


ks.test(jitter(before$sumadd), jitter(after$sumadd))
ks.test(jitter(before$sumrem), jitter(after$sumrem))
ks.test(jitter(before$total),  jitter(after$total))

exit()


ks.test((before$sumadd), (after$sumadd))
ks.test((before$sumrem), (after$sumrem))
ks.test((before$total),  (after$total))

exit()


b2 <- before[which(before$sumadd>0 & before$sumrem > 0),1:3]
a2 <- after[which(after$sumadd>0 & after$sumrem > 0),1:3]

both<-c(b2, a2)

pdf("churnBoxplot.pdf", width = 5.0, height=5.0, onefile = FALSE, paper = "special")

plot(b2$sumadd,log="y",frame.plot=TRUE,main="Size of Churn")

dev.off()



# compute the accumulated density for sumadd + sumrem


res <- dbSendQuery(conn, "select sumadd+sumrem as churn, sum(sumadd+sumrem) as sum from commitsum natural join metadata natural join log where not merge and  log !~ 'indent' and datecomm > '2010-03-01' group by sumadd+sumrem order by sumadd+sumrem;")
after <- dbGetResult(res)
summary (after);

res <- dbSendQuery(conn, "select sumadd+sumrem as churn, sum(sumadd+sumrem) as sum from commitsum natural join metadata natural join log where not merge and log !~ 'indent' and datecomm <= '2010-03-01' and datecomm > '2009-03-01' group by sumadd+sumrem order by sumadd+sumrem;")
before <- dbGetResult(res)
summary (before);


afterCumSum <- cumsum(after$sum)/sum(after$sum)
beforeCumSum <- cumsum(before$sum)/sum(before$sum)


pdf("churnAccum.pdf", width = 5.0, height=5.0, onefile = FALSE, paper = "special")
plot(before$churn, beforeCumSum, log="x",frame.plot=TRUE,xlab="Accumulated", ylab="Density of Churn", main="Churn") 
lines(after$churn, afterCumSum)
dev.off()

