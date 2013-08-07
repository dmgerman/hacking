#!/usr/bin/Rscript

require(ggplot2)

cg <- function(var, province) {
#  pdf(paste(province, ".pdf", sep=""),width=15)
  varname<-var[var$Province == province,]
  varname$Institution <- factor(varname$Institution)
  p <- ggplot(varname,aes(order(amount), sort(amount),label=Name))
  p + geom_point(aes(color=Institution)) +
    geom_text(hjust=0, vjust=0,aes(size=1.0),angle=90)+
      annotate("text", x=3.2, y=5000, label="Prepared by Daniel German dmg@uvic.ca",size=3,hjust=0, vjust=0) +
    opts(title=paste(province, " NSERC Discovery Grants 2012",sep=""))+   scale_x_continuous("Individuals") +   scale_y_continuous("Amount")
#  dev.off()
}
 

#x<-readHTMLTable("./nsercCS2011.html")
#names(nserc)[6]<-"amount"
#nserc$amount<-as.numeric(as.character(gsub(',', '', nserc$amount)))

x<-read.csv("nserc2012.csv", sep=";")
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

pdf("on2012.pdf",width=18)
cg(disc2, "Ontario")
dev.off()

pdf("bc2012.pdf",width=15)
cg(disc2, "British Columbia")
dev.off()

pdf("qc2012.pdf",width=15)
cg(disc2, "Quebec")
dev.off()

pdf("ab2012.pdf",width=15)
cg(disc2, "Alberta")
dev.off()



pdf("nserc2012byInd.pdf",width=15,heigh=7)
p <- ggplot(disc2,aes(order(amount), sort(amount)))
p + geom_point(aes(color=Province)) +
  scale_x_continuous("Individuals") +
  scale_y_continuous("Amount") 
dev.off()


#plot(amount ~ Institution, data=nserc[nserc$Program=='RGPIN',],las=2)
#geom_text(hjust=0, vjust=0,aes(size=amount),angle=45)+
pdf("nserc2012byInstLabels.pdf",width=15,heigh=7)
p<-ggplot(disc,aes(inst, amount,label=Name))
p+geom_hline(yintercept=24000,linetype=2,size=0.25)+
  geom_boxplot(color="black",outlier.size=0.1) +
  geom_jitter(aes(color=Term),size=2.5,alpha=0.7)+
  opts(axis.text.x=theme_text(angle=-90, hjust=0),title="NSERC Discovery Grants 2012, Computer Science (Evaluation Group 1507)")+
  geom_vline(xintercept = c(4.5,8.5,10.5,11.5,12.5,14.5,29.5,38.5),color='black',alpha=0.5) +
  annotate("text", x=5, y=150000, label="Prepared by Daniel German dmg@uvic.ca",size=3) +
  geom_text(hjust=0, vjust=0,aes(size=amount),angle=45)+
  scale_x_discrete("Institution (ordered by Province)") +
  scale_y_continuous("Amount")
dev.off()


pdf("nserc2012byInst.pdf",width=15)
p<-ggplot(disc,aes(inst, amount,label=Name))
p+geom_hline(yintercept=24000,linetype=2,size=0.25)+
  geom_boxplot(color="black",outlier.size=0.1) +
  geom_jitter(aes(color=Term),size=2.5,alpha=0.7)+
  opts(axis.text.x=theme_text(angle=-90, hjust=0),title="NSERC Discovery Grants 2012, Computer Science (Evaluation Group 1507)")+
  geom_vline(xintercept = c(4.5, 8.5,10.5,11.5,12.5,14.5,29.5,38.5),color='black',alpha=0.5) +
  annotate("text", x=10, y=122000, label="Prepared by Daniel German dmg@uvic.ca",size=3) +
#  geom_text(hjust=0, vjust=0,aes(size=amount),angle=45)+
  scale_x_discrete("Institution (ordered by Province)") +
  scale_y_continuous("Amount")


exit()

dev.off()
