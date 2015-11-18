#make N=10 M=0 C=2 arg1=individual

CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej4 

.PHONY: ej4 

all: time

time:
	$(CC) src/ej4Conf.cpp ../../grafo/grafo.cpp ../../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej4Conf
	$(CC) src/conflictos.cpp $(CFLAGS) conflictos
	./conflictos $(N) $(M) $(C) time.in
	./ej4Conf time.in test.txt resultados/confs.out individual
	./ej4Conf time.in test.txt resultados/confs.out intercambiar
	rm -f conflictos ej4Conf

clean:
	rm -f conflictos ej4Conf

clear: 
	rm -f resultados/confs.out

build:
	$(CC) src/ej4Conf.cpp ../../grafo/grafo.cpp ../../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej4Conf
	$(CC) src/conflictos.cpp $(CFLAGS) conflictos