CC=g++ -std=c++11


all: project clean

project: main.o
	$(CC) main.o -o project

main.o: main.cpp
	$(CC) -c main.cpp

.PHONY: clean
clean:
	rm -rf *.o *.gch
