

vicRest.html: 
	lynx --source --dump 'http://www.healthspace.ca/Clients/VIHA/VIHA_Website.nsf/Food-List-ByName?OpenView&RestrictToCategory=0c8f6f469d6a3e56964b3a748cb4dd94&count=1000&start=1' > vicRest.html
	lynx --source --dump 'http://www.healthspace.ca/Clients/VIHA/VIHA_Website.nsf/Food-List-ByName?OpenView&RestrictToCategory=0c8f6f469d6a3e56964b3a748cb4dd94&count=1000&start=1001' > vicRest2.html

# this file has to be edited by hand to remove headers and footers
restaurantsVictoria.txt: vicRest.html	scripts/extract.pl
	perl scripts/extract.pl vicRest.html > /tmp/part1.txt
	perl scripts/extract.pl vicRest2.html > /tmp/part2.txt
	sort /tmp/part1.txt /tmp/part2.txt > restaurantsVictoria.txt

sortedRestaurantsVictoria.txt: restaurantsVictoria.txt
	sort restaurantsVictoria.txt > sortedRestaurantsVictoria.txt



