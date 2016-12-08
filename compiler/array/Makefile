TARGET = run
CC = gcc
CFLAGS = -Wall
RM = rm -rf

all: main

#create object file for array_input.c
array_input.o: array_input.c
	$(CC) $(CFLAGS) -c array_input.c

#create object file for array_output.c
array_output.o: array_output.c
	$(CC) $(CFLAGS) -c array_output.c

#create object file for main.c
main.o: main.c array_input.h array_output.h
	$(CC) $(CFLAGS) -c main.c

#create the executable 
main: main.o array_input.o array_output.o
	$(CC) $(CFLAGS) main.o array_input.o array_output.o -o $(TARGET)

#clean files generated during compilation
clean:
	$(RM) *.o $(TARGET)



