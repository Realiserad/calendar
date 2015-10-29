#include <iostream>
#include "Date/Date.cpp"
#include "Gregorian/Gregorian.cpp"
#include "Julian/Julian.cpp"
#include <assert.h>

int main() {
	lab2::Gregorian g(1993, 2, 16);
	lab2::Julian j(g);
	std::cout << j << std::endl;
}
