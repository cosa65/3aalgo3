CC=g++
CFLAGS=-std=c++11 -ggdb
# CFLAGS=-std=c++11 -Wall -Wextra -pedantic -O0 -ggdb -lm
SOURCE=test.cpp grafo.cpp digrafo.cpp
TARGET=test

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	echo -e '\0033\0143'

clean:
	rm -f *.o
	rm -f $(TARGET)
