CC=g++

all: run

main.o: main.cpp parser.cpp parser.h callbacks.cpp callbacks.h
	$(CC) -c main.cpp

parser.o: parser.cpp parser.h
	$(CC) -c parser.cpp

callbacks.o: callbacks.cpp callbacks.h
	$(CC) -c callbacks.cpp

run: main.o parser.o callbacks.o
	$(CC) -o run main.o parser.o callbacks.o

test: main.o parser.o callbacks.o
	$(CC) -o run main.o parser.o callbacks.o
	./run

clean:
	rm -rf *.o run
