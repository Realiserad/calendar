CC = g++
FLAGS = -std=c++11 -Wall -pedantic
all : date.cpp
	$(CC) date.cpp $(FLAGS) -c
clean :
	rm -f *.o *.gch *.out
