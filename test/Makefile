CC=gcc
CFLAGS=-I. -Wall -I../ -Ilib/

SRCS = $(wildcard *.c)
BINS = $(patsubst %.c,%,$(SRCS))

all: execute

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

execute: $(BINS)
	./$(BINS)

clean: 
	rm -f $(BINS)