CC = gcc
all: main

main: main.o mul.o
	$(CC) main.o mul.o -o run	

main.o: main.c
	$(CC) -c main.c

mul.o: mul.c
	$(CC) -c mul.c

clean:
	rm -rf *.o
