CC=g++

all: run

main.o: main.cpp deserializer.cpp deserializer.h serializer.cpp serializer.h data.h

	$(CC) -c main.cpp
serializer.o: serializer.cpp serializer.h data.h
	$(CC) -c serializer.cpp

deserializer.o: deserializer.cpp deserializer.h data.h
	$(CC) -c deserializer.cpp

run: main.o serializer.o deserializer.o
	$(CC) -o run main.o serializer.o deserializer.o

test: main.o serializer.o deserializer.o
	$(CC) -o run main.o serializer.o deserializer.o
	./run

clean:
	rm -rf *.o run
