CC=g++

all: run

main.o: main.cpp bigint.cpp bigint.h
	$(CC) -c main.cpp

bigint.o: bigint.cpp bigint.h
	$(CC) -c bigint.cpp

run: main.o bigint.o
	$(CC) -o run main.o bigint.o

test: main.o bigint.o
	$(CC) -o run main.o bigint.o
	./run

clean:
	rm -rf *.o run
