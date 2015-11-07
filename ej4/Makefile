CC = g++
CFLAGS = -std=c++11 -o
EFLAGS = -g

BINARIES = ej4 

.PHONY: ej4 

all: $(BINARIES)

ej4: ej4.cpp  
	$(CC) ej4.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(CFLAGS) ej4 

clean:
	rm -f *.o ej4 

run:
	./ej4 tests/testEj4.in tests/testEj4.txt tests/testEj4.out $(arg1)

runclean:
	rm -f tests/testEj4.out
	./ej4 tests/testEj4.in tests/testEj4.txt tests/testEj4.out $(arg1)

test:
	$(CC) ej4.cpp ../grafo/grafo.cpp ../grafo/vertice.cpp $(EFLAGS) $(CFLAGS) ej4
	gdb --args ej4 tests/testEj4.in tests/testEj4.txt tests/testEj4.out $(arg1)