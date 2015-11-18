CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = grafo digrafo vertice tests

.PHONY: grafo digrafo vertice tests

all: $(BINARIES)

grafo: grafo.cpp 
	$(CC) grafo.cpp vertice.cpp $(CFLAGS) grafo 

vertice: vertice.cpp
	$(CC) vertice.cpp $(CFLAGS) vertice 

digrafo: digrafo.cpp 
	$(CC) digrafo.cpp grafo.cpp vertice.cpp vertice_digrafo.cpp $(CFLAGS) digrafo 

tests: tests.cpp
	$(CC) grafo.cpp digrafo.cpp vertice.cpp vertice_digrafo.cpp tests.cpp $(CFLAGS) tests

clean:
	rm -f *.o grafo 
	rm -f *.o digrafo 
	rm -f *.o tests 
