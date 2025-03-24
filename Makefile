CC = gcc
CFLAGS = -O2 -Wall
TARGET = mocro

all:
	$(CC) $(CFLAGS) -o $(TARGET) src/mocro.c

clean:
	rm -f $(TARGET)
