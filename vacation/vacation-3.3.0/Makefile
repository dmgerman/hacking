OPTS=-O2
LIBS=-ldb
CFLAGS=-DHAVE_PATHS_H

all: antivacation

antivacation: antivacation.c
	$(CC) $(OPTS) $(CFLAGS) $< -o $@ $(LIBS)

distclean: clean

clean:
	-rm -f antivacation
