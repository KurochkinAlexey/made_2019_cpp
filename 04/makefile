CC=g++

all: run

main.o: main.cpp matrix.cpp matrix.h row.cpp row.h
	$(CC) -c main.cpp

matrix.o: matrix.cpp matrix.h row.cpp row.h
	$(CC) -c matrix.cpp

row.o: row.cpp row.h
	$(CC) -c row.cpp

run: main.o matrix.o row.o
	$(CC) -o run main.o matrix.o row.o

test: main.o matrix.o row.o
	$(CC) -o run main.o matrix.o row.o
	./run

clean:
	rm -rf *.o run
