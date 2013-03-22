#!/usr/bin/Rscript

require("ggplot2")

uvic<-read.csv("./uvic.data",sep=";")
uvic<-uvic[order(uvic$Amount),]
uvic$Year <- as.factor(uvic$Year)
uvic$Years <- as.factor(uvic$Years)


uvicH<-read.csv("./uvic.data.hist",sep=";")
uvicH$Year <- as.factor(uvicH$Year)
uvicH$Years <- as.factor(uvicH$Years)

uvicA <- rbind(uvicH,uvic)
uvicA <-uvicA[order(as.numeric(uvicA$Year)),]

uvicA

row.names(uvicA)=1:nrow(uvicA)
uvicA$Length<-factor(uvicA$Years)

pdf("uvic.pdf",width=12)

p<-ggplot(uvic,aes(order(Amount),sort(Amount),label=Name))

p + geom_point(aes(color=Year,shape=Years),size=3) +
    geom_text(hjust=0, vjust=0,size=5,angle=90)+
    annotate("text", x=3.2, y=5000, label="Prepared by Daniel German dmg@uvic.ca",size=3,hjust=0, vjust=0) +
    opts(title=" Current NSERC Discovery Grants UVic Dept of Computer Science")+   scale_x_continuous("Individuals") +   scale_y_continuous("Amount") +
    coord_cartesian(ylim=c(0, 60000))
dev.off()


pdf("uvicYear.pdf",width=12)

p<-ggplot(uvicA,aes(order(Year),Amount,label=Name))

p + geom_point(aes(color=Year,shape=Length),size=3) +
    geom_vline(xintercept = c(6.3,10.3,15.3,20.3,32.3),color='white',alpha=0.5,size=2.5) +
    geom_text(hjust=0, vjust=0,size=5,angle=90)+
    annotate("text", x=24.2, y=55000, label="Prepared by Daniel German dmg@uvic.ca",size=3,hjust=0, vjust=0) +
    annotate("text", x=3, y=10000, label="2007",size=4, vjust=0) +
    annotate("text", x=8, y=10000, label="2008",size=4, vjust=0) +
    annotate("text", x=12.5, y=10000, label="2009",size=4, vjust=0) +
    annotate("text", x=17.5, y=10000, label="2010",size=4, vjust=0) +
    annotate("text", x=26.5, y=10000, label="2011",size=4, vjust=0) +
    annotate("text", x=34.5, y=10000, label="2012",size=4, vjust=0) +
    opts(title=" Historical NSERC Discovery Grants UVic Dept of Computer Science")+   scale_x_continuous("Individuals") +   scale_y_continuous("Amount") +
    coord_cartesian(ylim=c(0, 60000)) 

dev.off()

