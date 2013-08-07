default:

tovisit.txt: visited.txt restaurants.txt
	grep '^:' visited.txt | \cut -d ':' -f 2 > tmp.tmp
	cut -d ';' -f 1 restaurants.txt > tmp.tmp2
	cat tmp.tmp tmp.tmp2 | sort   | uniq -u > tovisit.txt
	rm -f tmp.tmp tmp.tmp2

www:
	perl ~/bin/myjoin.pl  restaurants.txt type.txt |  perl extractDataForMaps.pl > /tmp/rip.rip
	cat part1.html /tmp/rip.rip part2.html > rest.html
	chmod go+r rest.html
	cp -p rest.html /tmp/
#	rsync -a -v rest.html dmg@w:~/public_html/temp/


bytype:
	cut -d ';' -f 5 type.txt | sort | uniq -c


grepbytype:
	grep ';Japanese' type.txt | sort 

visited:
	egrep '^:' visited.txt 
