OPTS=-O2
LIBS=-ldb
CFLAGS=-DHAVE_PATHS_H

all: vacation

vacation: vacation.c
	$(CC) $(OPTS) $(CFLAGS) $< -o $@ $(LIBS)

distclean: clean

clean:
	-rm -f vacation
