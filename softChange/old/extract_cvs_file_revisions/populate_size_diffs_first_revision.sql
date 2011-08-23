-- we already have the revisiondiffs table, with all the records


update revisiondiffs set diff = (select newfile from filerevisions f where f.revisionid = '1.1' and f.filename = revisiondiffs.filename) where revisionid = '1.1';


update revisiondiffs set diffclean = (select cleanfile from filerevisions f where f.revisionid = '1.1' and f.filename = revisiondiffs.filename) where revisionid = '1.1';





