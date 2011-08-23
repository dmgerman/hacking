default: myresample

tessel:tessel.cpp
	g++ -I /sw/include -L/sw/lib  -o tessel tessel.cpp  -lvigraimpex -ltiff -lpng -ljpeg -lm -lboost_program_options

myresample:myresample.cpp
	g++ -I /sw/include -L/sw/lib  -o myresample myresample.cpp  -lvigraimpex -ltiff -lpng -ljpeg -lm -lboost_program_options


copy:
	chmod go+r *
	rsync -a -v index.html Makefile COPYING tessel.cpp distribution dmg@w.cs.uvic.ca:~/www/tlalli/

