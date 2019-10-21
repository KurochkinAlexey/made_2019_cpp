CC=g++

all: run

main.o: main.cpp
	$(CC) -c main.cpp

run: main.o
	$(CC) -o alloc main.o

test: main.o
	$(CC) -o alloc main.o
	./alloc
clean:
	rm -rf *.o alloc
