CC = clang++

all: run

threadpool.o: threadpool.cpp threadpool.h
	$(CC) -std=c++11 -c threadpool.cpp

main.o: main.cpp threadpool.cpp threadpool.h
	$(CC) -std=c++11 -c main.cpp

run: main.o threadpool.o
	$(CC) -std=c++11 -o run main.o threadpool.o

test: main.o threadpool.o
	$(CC) -std=c++11 -o run main.o threadpool.o
	./run

clean:
	rm -rf *.o run
