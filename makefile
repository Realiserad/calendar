CC = g++ 
FLAGS = -std=c++11 -Wall -pedantic -g
date :
	$(CC) ./Date.cpp $(FLAGS) -c
greg :
	$(CC) ./Gregorian.cpp $(FLAGS) -c
julia :
	$(CC) ./Julian.cpp $(FLAGS) -c
clean :
	rm -rf *.o *.gch *.out .*.*.swp
	@echo "Crap destroyed successfully!"
all : 
	@echo "No rule defined yet."
test :
	$(CC) $(FLAGS) test.cpp -o test.out
	./test.out
