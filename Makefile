CC=gcc
CFLAGS=-c -Wall

all: chull

chull: main.o stack.o data_struct.o
	$(CC) main.o stack.o data_struct.o -o chull

main.o: main.c
	$(CC) $(CFLAGS) main.c

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

data_struct.o: data_struct.c
	$(CC) $(CFLAGS) data_struct.c

clean:
	rm *.o chull
