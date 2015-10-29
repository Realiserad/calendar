#include <iostream>
#include "Date/Date.cpp"
#include "Gregorian/Gregorian.cpp"
#include "Julian/Julian.cpp"
#include <assert.h>

int main() {
	lab2::Julian j(1900, 1, 1);
	lab2::Gregorian g = j;
	std::cout << j << std::endl;
}
