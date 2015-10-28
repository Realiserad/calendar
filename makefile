CC = gcc
FLAGS = -std=c++11 -Wall -pedantic -g
date :
	$(CC) ./Date/Date.cpp $(FLAGS) -c
greg :
	$(CC) ./Gregorian/Gregorian.cpp $(FLAGS) -c
julia :
	$(CC) ./Julian/Julian.cpp $(FLAGS) -c
clean :
	rm -rf *.o *.gch *.out
	@echo "Crap destroyed successfully!"
all : 
	@echo "No rule defined yet."
test :
	$(CC) $(FLAGS) test.cpp -o test.out
	./test.out
