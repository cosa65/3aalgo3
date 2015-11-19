CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej3 

.PHONY: ej3 

all: $(BINARIES)

ej3:
	$(CC) src/conflictos.cpp $(CFLAGS) conflictos 
	$(CC) src/ej3Confs.cpp ../../grafo/grafo.cpp ../../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej3Conf 

clean:
	rm -f *.o ej3Conf conflictos mini

clear:
	rm -f resultados/confs.out resultados/confs.in