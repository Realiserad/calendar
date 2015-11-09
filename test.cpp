#include <iostream>
#include <assert.h>
#include "date.cpp"
#include "gregorian.cpp"
#include "julian.cpp"

/// test operator++(int)
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

/// test operator++, operator== and operator!=
void test_feminism() {
	lab2::Gregorian g(1900, 1, 1);
	lab2::Julian j(1899, 12, 19);
	assert(j != g);
	j++;
	assert(j == g);
}

void test_pointers() {
	lab2::Date * p1 = new lab2::Julian();
	lab2::Date * p2 = new lab2::Gregorian();
	assert(*p1 == *p2); 
	delete p1;
	delete p2;
}

void test_convert() {
	// Test 1: Conversion Gregorian -> Julian and Conversion Julian -> Gregorian
    std::cout << "Test 1: Conversion Gregorian -> Julian and Conversion Julian -> Gregorian" << std::endl;
	lab2::Gregorian g(1900, 1, 1);
    std::cout << "g (Gregorian): " << g << std::endl;
	lab2::Julian gj(g);
    std::cout << "gj (Gregorian -> Julian): " << gj << std::endl;
    lab2::Gregorian gjg(gj); 
    std::cout << "gjg (Gregorian -> Julian -> Gregorian): " << gjg << std::endl;
}

void test_add_month() {
    lab2::Gregorian g(2004, 1, 30);
    g.add_month(1); 
    lab2::Gregorian gTest(2004, 2, 29); 
    assert(g == gTest);

    lab2::Gregorian g2(2003, 1, 30);
    g2.add_month(1);
    lab2::Gregorian g2Test(2003, 2, 28);
    assert(g2 == g2Test);
}

void test_add_year() {
    lab2::Gregorian g(2000, 1, 20);
    g.add_year(5); 
    lab2::Gregorian gTest(2005, 1, 20); 
    assert(g == gTest);

    lab2::Gregorian g2(2004, 2, 29);
    g2.add_year(1); 
    lab2::Gregorian g2Test(2005, 2, 28); 
    assert(g2 == g2Test);

    lab2::Gregorian g3(2004, 2, 29);
    g3.add_year(4); 
    lab2::Gregorian g3Test(2008, 2, 29); 
    assert(g3 == g3Test);
}

void test_operators() {
    
}

int main() {
    test_increment();
    test_feminism();
    test_convert();
    test_pointers();
    test_add_month();
    test_add_year(); 
    test_operators();
}
