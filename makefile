CC = clang++
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
	$(CC) $(FLAGS) -c julian.cpp
	$(CC) $(FLAGS) -c date.cpp
	$(CC) $(FLAGS) -c gregorian.cpp
test :
	$(CC) $(FLAGS) test.cpp -o test.out
	./test.out
