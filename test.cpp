#include <iostream>
#include "Date/Date.cpp"
#include "Gregorian/Gregorian.cpp"
#include "Julian/Julian.cpp"
#include <assert.h>

int main() {
	lab2::Gregorian g(1900, 1, 1);
	lab2::Julian j(g);
	std::cout << j << std::endl;

    lab2::Julian x(1899, 12, 20);
    lab2::Gregorian y(x);
    std::cout << y << std::endl;
}
