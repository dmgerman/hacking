DROP TABLE IF EXISTS rests;
CREATE TABLE rests(
       name VARCHAR(200),
       rhash CHAR(32),
       address VARCHAR(200),
       code  bigint,
       rtype  CHAR(20),
       whenopen VARCHAR(20),
       rwhenupdated date,
       primary key (name,address,code,rhash)
);

DROP TABLE IF EXISTS visits;
CREATE TABLE visits(
   code  bigint,
   vhash CHAR(32),
   vtype CHAR(50),
   vwhen date,
   vwhenupdated date,
   primary key (code, vwhen)
);
CREATE TABLE addrs(
  address varchar(200), 
  apt varchar(50), 
  number bigint, 
  street varchar(100),
  zone char(5),
  lat real,
  long real,
  primary key (address)
);
