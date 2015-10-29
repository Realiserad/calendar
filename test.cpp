#include <iostream>
#include "Date/Date.cpp"
#include "Gregorian/Gregorian.cpp"
#include "Julian/Julian.cpp"
#include <assert.h>

int main() {
    // Test 1: Conversion Gregorian -> Julian and Conversion Julian -> Gregorian
    std::cout << "Test 1: Conversion Gregorian -> Julian and Conversion Julian -> Gregorian" << std::endl;
	lab2::Gregorian g(1900, 1, 1);
    std::cout << "g (Gregorian): " << g << std::endl;
	lab2::Julian gj(g);
    std::cout << "gj (Gregorian -> Julian): " << gj << std::endl;
    lab2::Gregorian gjg(gj); 
    std::cout << "gjg (Gregorian -> Julian -> Gregorian): " << gjg << std::endl;

    
    lab2::Julian x(1899, 12, 20);
    lab2::Gregorian y(x);

    lab2::Julian a(1993, 2, 28);
    lab2::Julian b(1993, 2, 28);

    if (x == g) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    
}
