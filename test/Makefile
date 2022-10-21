CC=gcc
CFLAGS=-I. -Wall -I../ -Ilib/

SRC=$(wildcard *.c)
BIN=test

all: build execute

build:
	$(CC) $(SRC) -o $(BIN) $(CFLAGS)

execute:
	./$(BIN)

clean:
	rm -f $(BIN)