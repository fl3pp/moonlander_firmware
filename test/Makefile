CC=gcc
CFLAGS=-ggdb -I. -Wall -I../ -Ilib/ -I../../../../../quantum

SRCS = $(wildcard *.c)
BINS = $(patsubst %.c,%,$(SRCS))

all: execute

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

execute: $(BINS)
	./$(BINS)

clean: 
	rm -f $(BINS)