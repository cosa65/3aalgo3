CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej4 

.PHONY: ej4 

all: $(BINARIES)

ej5: src/ej5.cpp  
	$(CC) src/ej5.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(CFLAGS) ej5 
	$(CC) src/random.cpp $(CFLAGS) random
	$(CC) src/conflictos.cpp $(CFLAGS) conflictos

clean:
	rm -f *.o ej5 random conflictos

clear:
	rm -f resultados/test.out

test:
	$(CC) src/ej5.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej5
	$(CC) src/random.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej5
	$(CC) src/conflictos.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej5