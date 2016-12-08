TARGET = run
CC = gcc

all: signal_handler.c
	$(CC) -Wall signal_handler.c -o $(TARGET) -lpthread
clean:
	rm -rf *.o $(TARGET)
