edit : main.o
	cc -o edit main.o

main.o : main.cpp Cave.h Room.h
	cc -c main.cpp
clean :
	rm edit main.o
