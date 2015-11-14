#make N=10 M=0 C=2 arg1=individual

CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej4 

.PHONY: ej4 

all: time

time:
	$(CC) src/ej4Time.cpp ../../grafo/grafo.cpp ../../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej4Time
	$(CC) src/random.cpp $(CFLAGS) random
	./random $(N) $(M) $(C) time.in
	./ej4Time time.in test.txt resultados/time.out individual
	./ej4Time time.in test.txt resultados/time.out intercambiar
	rm -f random ej4Time

clean: 
	rm -f resultados/time.out

build:
	$(CC) src/ej4Time.cpp ../../grafo/grafo.cpp ../../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej4Time
	$(CC) src/random.cpp $(CFLAGS) random

timeRep:
	$(CC) src/ej4Time.cpp ../../grafo/grafo.cpp ../../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej4Time
	$(CC) src/random.cpp $(CFLAGS) random
	i=1
	for i in 1 .. 10
	do
		./random $(N) $(M) $(C) time.in
		./ej4Time time.in test.txt resultados/time.out individual
		./ej4Time time.in test.txt resultados/time.out intercambiar
	done
	rm -f random ej4Time
