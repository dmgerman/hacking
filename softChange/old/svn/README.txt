
First create svn log

svn log --xml -verbose > log.xml

#then process it

processSVNxmlLog.pl  /mirror/apache log.xml

# create db

create apache13

#then import it

load_data_into_database.pl apache13
