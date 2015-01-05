#
#  CS 11: Makefile for C track, assignment 5 .
#
CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

.PHONY: clean

all : 1dca_pointer 1dca_array

1dca_pointer: 1dca_pointer.o memcheck.o
	$(CC) 1dca_pointer.o  memcheck.o -o 1dca_pointer
1dca_array: 1dca_array.o memcheck.o
	$(CC) 1dca_array.o  memcheck.o -o 1dca_array
1dca_pointer.o : 1dca_pointer.c
	$(CC) $(CFLAGS) -c 1dca_pointer.c
1dca_array.o : 1dca_array.c
	$(CC) $(CFLAGS) -c 1dca_array.c
memcheck.o : memcheck.c
	$(CC) $(CFLAGS) -c memcheck.c
clean :
	rm -f *.o 1dca_pointer 1dca_array

