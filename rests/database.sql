create table restaurant(
       rid       integer   UNIQUE,
       rname     char(100) UNIQUE,
       rtype     char(100),
       ropen     char(100),
       rurl      char(20)  UNIQUE,
       seen      TIMESTAMP,
       primary key (rid)
       );

       
