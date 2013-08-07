#!/bin/bash

grep ';"RGPIN";' 2009/nserc2009.csv | perl -pe 's/$/;2009/' > /tmp/2009.txt
grep ';"RGPIN";' 2010/nserc2010.csv | perl -pe 's/$/;2010/' > /tmp/2010.txt
grep ';"RGPIN";' 2011/nserc2011.csv | perl -pe 's/$/;2011/' > /tmp/2011.txt
grep ';"RGPIN";' 2012/nserc2012.csv | perl -pe 's/$/;2012/' > /tmp/2012.txt
grep ';"RGPIN";' 2013/nserc2013.csv | perl -pe 's/$/;2013/' > /tmp/2013.txt
head -1 2013/nserc2013.csv > /tmp/2000.txt
cat /tmp/20??.txt > all.csv

