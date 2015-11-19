CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej3 

.PHONY: ej3 

all: $(BINARIES)

ej3: ej3.cpp  
	$(CC) ej3.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(CFLAGS) ej3 

clean:
	rm -f *.o ej3 
