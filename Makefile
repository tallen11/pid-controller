CC=clang
CFLAGS=-g -Wall
BLOBS=pid.o main.o

all: pid.o main.o
	$(CC) $(BLOBS) -o main

pid.o: pid.h pid.c
	$(CC) -c pid.c $(CFLAGS) -o pid.o

main.o: main.c
	$(CC) -c main.c $(CFLAGS) -o main.o

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf main
	rm -rf *.gch