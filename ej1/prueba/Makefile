CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = test grafo digrafo

all: $(BINARIES)

grafo: grafo.cpp 
	$(CC) grafo.cpp $(CFLAGS) grafo 

digrafo: digrafo.cpp 
	$(CC) digrafo.cpp $(CFLAGS) digrafo 

test: test.cpp
	$(CC) grafo.cpp digrafo.cpp test.cpp $(CFLAGS) test

clean:
	rm -f *.o grafo 
	rm -f *.o digrafo 
	rm -f *.o test 
