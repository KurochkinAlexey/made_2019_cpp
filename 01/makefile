CC=g++

all: run

run.o: run.cpp calculate.h
	$(CC) -c run.cpp

calculate.o: calculate.cpp calculate.h
	$(CC) -c calculate.cpp

run: run.o calculate.o
	$(CC) -o run run.o calculate.o

test: run.o calculate.o
	$(CC) -o run run.o calculate.o
	./run 1+1
	./run 2
	./run 2+2*2
	./run -1-1
	./run 2*3--4
	./run 5*-4/10+10/2*-5
	./run 2+3*4--2
	./run 2+
	./run 3+=4
clean:
	rm -rf *.o run
