#include <iostream>
#include "Date/Date.hpp"
#include "Gregorian/Gregorian.hpp"
#include "Julian/Julian.hpp"
#include <assert.h>

int main() {
	lab2::Julian j(1900, 1, 1);
	lab2::Gregorian g = j;
	std::cout << j << std::endl;
}
