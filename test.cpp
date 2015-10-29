#include <iostream>
#include "Date/Date.cpp"
#include "Gregorian/Gregorian.cpp"
#include "Julian/Julian.cpp"
#include <assert.h>

void test_increment() {
	lab2::Gregorian g1(1999, 12, 31);
    g1++;
    assert(g1.day() == 1 && g1.month() == 1 && g1.year() == 2000);
    g1++;
    assert(g1.day() == 2 && g1.month() == 1 && g1.year() == 2000);
    lab2::Gregorian g2(2000, 02, 28);
    g2++;
    assert(g2.day() == 29 && g2.month() == 2 && g2.year() == 2000);
    lab2::Gregorian g3(1900, 02, 28);
    g3++;
    assert(g3.day() == 1 && g3.month() == 3 && g3.year() == 1900);
}

int main() {
	lab2::Gregorian g(1900, 1, 1);
	lab2::Julian j(g);
	std::cout << j << std::endl;

    lab2::Julian x(1899, 12, 20);
    lab2::Gregorian y(x);
    std::cout << y << std::endl;
    
    test_increment();
    
    /*Gregorian g(1900, 1, 1);
	Julian j (1899, 12, 19);
	assert((j == g) == false);
	j++;
	assert(j == g);*/
}
