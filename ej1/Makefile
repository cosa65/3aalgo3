CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej1 

.PHONY: ej1 

all: $(BINARIES)

ej1: ej1.cpp  
	$(CC) ej1.cpp ../grafo/digrafo.cpp ../grafo/grafo.cpp ../grafo/vertice_digrafo.cpp ../grafo/vertice.cpp $(CFLAGS) ej1 

clean:
	rm -f *.o ej1 
