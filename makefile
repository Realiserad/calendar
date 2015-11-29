CC = g++
FLAGS = -std=c++11 -Wall -pedantic -g
calendar :
	$(CC) calendar.cpp $(FLAGS) -c
date :
	$(CC) date.cpp $(FLAGS) -c
greg :
	$(CC) gregorian.cpp $(FLAGS) -c
julia :
	$(CC) julian.cpp $(FLAGS) -c
clean :
	rm -rf *.o *.gch *.out .*.*.swp
	@echo "Crap destroyed successfully!"
all : date greg julia calendar
test :
	$(CC) $(FLAGS) test.cpp -o test.out
	./test.out
