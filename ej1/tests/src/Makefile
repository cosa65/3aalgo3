CC = g++
CFLAGS = -std=c++11 -ggdb -o
EFLAGS = -g

BINARIES = ej1Timed

.PHONY: ej1Timed 

all: $(BINARIES)

ej1Timed: ej1Timed.cpp
	echo -e '\0033\0143'
	$(CC) ej1Timed.cpp ../grafo/digrafo.cpp ../grafo/grafo.cpp ../grafo/vertice_digrafo.cpp ../grafo/vertice.cpp $(CFLAGS) ej1Timed 
	echo -e '\0033\0143'
clean:
	rm -f *.o ej1Timed 
