CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = grafo digrafo tests

.PHONY: grafo digrafo tests

all: $(BINARIES)

grafo: grafo.cpp 
	$(CC) grafo.cpp $(CFLAGS) grafo 

digrafo: digrafo.cpp 
	$(CC) digrafo.cpp $(CFLAGS) digrafo 

tests: tests.cpp
	$(CC) grafo.cpp digrafo.cpp tests.cpp $(CFLAGS) tests

clean:
	rm -f *.o grafo 
	rm -f *.o digrafo 
	rm -f *.o tests 
