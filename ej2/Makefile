CC = g++
CFLAGS = -std=c++11 -o 
EFLAGS = -g

BINARIES = ej2 

.PHONY: ej2 

all: $(BINARIES)

ej2: ej2.cpp  
	$(CC) $(EFLAGS) ej2.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp ../grafo/digrafo.cpp ../grafo/vertice_digrafo.cpp $(CFLAGS) ej2 

clean:
	rm -f *.o ej2 
