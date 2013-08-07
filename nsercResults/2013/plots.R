#!/usr/bin/Rscript

require(ggplot2)

pl <- function(varname, plotTitle) {
  varname$Institution <- factor(varname$Institution)
  p <- ggplot(varname,aes(order(amount), sort(amount),label=Name))
  p + geom_point(aes(color=Color)) +
      geom_text(hjust=0, vjust=0,aes(size=1.0),angle=270)+
      annotate("text", x=0.5, y=26000, label="Prepared by Daniel German dmg@uvic.ca",size=3,hjust=0, vjust=0) +
      opts(title=plotTitle)+
      scale_x_continuous("Individuals") +   scale_y_continuous("Amount", limits=c(-20000,max(varname$amount)))

}

allG <- function(varname) {
#  pdf(paste(province, ".pdf", sep=""),width=15)
  varname$Color <- factor(varname$Province)
  pl(varname, " NSERC Discovery Grants 2013")
#  dev.off()
}


cg <- function(var, province, Institution) {
#  pdf(paste(province, ".pdf", sep=""),width=15)
  varname<-var[var$Province == province,]
  varname$Color <- factor(varname$Institution)
  pl(varname, paste(province, " NSERC Discovery Grants 2013",sep=""))
#  dev.off()
}
 

#x<-readHTMLTable("./nsercCS2011.html")
#names(nserc)[6]<-"amount"
#nserc$amount<-as.numeric(as.character(gsub(',', '', nserc$amount)))

x<-read.csv("nserc2013.csv", sep=";")
nserc<-x
nserc$Term <- as.factor(nserc$Term)
#join province
prov<-read.csv("../byProvince.csv",sep=';')
nserc2<-merge(nserc,prov,ALL=TRUE)
nserc2<-nserc2[order(nserc2$Province),]

disc<-nserc2[nserc2$Program=='RGPIN',]

# order factor
x<-as.character(prov[order(prov$Province),]$Institution)
disc$inst<-factor(disc$Institution,levels=x,ordered=TRUE)
disc2<-disc[order(disc$amount),]

pdf("on2013.pdf",width=24)
cg(disc2, "Ontario")
dev.off()

pdf("bc2013.pdf",width=15)
cg(disc2, "British Columbia")
dev.off()

pdf("qc2013.pdf",width=15)
cg(disc2, "Quebec")
dev.off()

pdf("ab2013.pdf",width=15)
cg(disc2, "Alberta")
dev.off()

pdf("nserc2013all.pdf",width=40)
allG(disc2)
dev.off()



pdf("nserc2013byInd.pdf",width=15,heigh=7)
p <- ggplot(disc2,aes(order(amount), sort(amount)))
p + geom_point(aes(color=Province)) +
  annotate("text", x=0.5, y=26000, label="Prepared by Daniel German dmg@uvic.ca",size=3,hjust=0)+
  scale_x_continuous("Individuals") +
  scale_y_continuous("Amount") 
dev.off()


#plot(amount ~ Institution, data=nserc[nserc$Program=='RGPIN',],las=2)
#geom_text(hjust=0, vjust=0,aes(size=amount),angle=45)+
pdf("nserc2013byInstLabels.pdf",width=15,heigh=7)
p<-ggplot(disc,aes(inst, amount,label=Name))
p+geom_hline(yintercept=median(disc$amount),linetype=2,size=0.25)+
  geom_boxplot(color="black",outlier.size=0.1) +
  geom_jitter(aes(color=Term),size=2.5,alpha=0.7)+
  opts(axis.text.x=theme_text(angle=-90, hjust=0),title="NSERC Discovery Grants 2013, Computer Science (Evaluation Group 1507)")+
  geom_vline(xintercept = c(3.5,6.5,7.5,8.5,9.5,12.5,27.5,38.5),color='black',alpha=0.5) +
  annotate("text", x=5, y=150000, label="Prepared by Daniel German dmg@uvic.ca",size=3) +
  geom_text(hjust=0, vjust=0,aes(size=amount),angle=45)+
  scale_x_discrete("Institution (ordered by Province)") +
  scale_y_continuous("Amount")
dev.off()


pdf("nserc2013byInst.pdf",width=15)
p<-ggplot(disc,aes(inst, amount,label=Name))
p+geom_hline(yintercept=median(disc$amount),linetype=2,size=0.25)+
  geom_boxplot(color="black",outlier.size=0.1) +
  geom_jitter(aes(color=Term),size=2.5,alpha=0.7)+
  opts(axis.text.x=theme_text(angle=-90, hjust=0),title="NSERC Discovery Grants 2013, Computer Science (Evaluation Group 1507)")+
  geom_vline(xintercept = c(3.5,6.5,7.5,8.5,9.5,12.5,27.5,38.5),color='black',alpha=0.5) +
  annotate("text", x=10, y=122000, label="Prepared by Daniel German dmg@uvic.ca",size=3) +
#  geom_text(hjust=0, vjust=0,aes(size=amount),angle=45)+
  scale_x_discrete("Institution (ordered by Province)") +
  scale_y_continuous("Amount")


exit()

dev.off()
