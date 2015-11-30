#include <iostream>
#include <assert.h>
#include "date.cpp"
#include "gregorian.cpp"
#include "julian.cpp"
#include "calendar.hpp"
#include <ctime>

void test_calendar() {
	lab2::Calendar<lab2::Gregorian> cal;
	cal.set_date(2000, 12, 2);
	cal.add_event("Basketträning", 4, 12, 2000);
	cal.add_event("Basketträning", 11, 12, 2000);
	cal.add_event("Nyårsfrukost", 1, 1, 2001);
	cal.add_event("Första advent", 1); // år = 2000, månad = 12
	cal.add_event("Vårdagjämning", 20, 3); // år = 2000
	cal.add_event("Julafton", 24, 12);
	cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
	cal.add_event("Julafton", 24); // En likadan händelse samma datum ska ignoreras och inte sättas in i kalendern
	cal.add_event("Min första cykel", 20, 12, 2000);
	cal.remove_event("Basketträning", 4);
	std::cout << cal;
}

/// test operator++(int)
void test_increment() {
	lab2::Gregorian g1(1999, 12, 31);
    g1++;
    assert(g1.day() == 1 && g1.month() == 1 && g1.year() == 2000);
    g1++;
    assert(g1.day() == 2 && g1.month() == 1 && g1.year() == 2000);
    lab2::Gregorian g2(2000, 2, 28);
    g2++;
    assert(g2.day() == 29 && g2.month() == 2 && g2.year() == 2000);
    lab2::Gregorian g3(1900, 2, 28);
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

void test_relational() {
	lab2::Julian j1;
	lab2::Julian j2;
	int diff = j1-j2;
	assert(diff == 0);
}

void test_cout() {
	lab2::Gregorian j(1993, 02, 16);
	std::cout << j << std::endl;
}


void test_kattis1() {
    lab2::Julian a (2140, 8, 9);
    a.add_year(18);
    a += 18;
    a.add_month(18);
    a -= 18;
    a += -18;
    a.add_year(-18);
    a -= -18;
    ++a;
    a.add_month(-18);
    --a;
    a.add_year(5);
    a += 5;
    a.add_month(5);
    a -= 5;
    a += -5;
    a.add_year(-5);
    a -= -5;
    ++a;
    a.add_month(-5);
    --a;
    a.add_year(17);
    a += 17;
    a.add_month(17);
    a -= 17;
    // std::cout << a << std::endl;
    std::cout << " -------------------------------------- " << std::endl;
    a += -17;
    std::cout << "FAIL: " << a << ", " << a.mod_julian_day() << std::endl; 
    std::cout << "YEEY: " << "2158-12-23" << ", " << "109623" << std::endl; 
}

void test_kattis2() {
    // lab2::Gregorian b; // 1: k_time-construct gregorian $B 367758793
    // b.add_year(18);// 2: add_year  $B  18
    // b += 18;// 3: d+= $B 18
    // b.add_month(18);// 4: add_month $B  18
    // b -= 18;// 5: d-= $B 18
    // b += -18;// 6: d+= $B -18
    // b.add_year(-18);// 7: add_year  $B -18
    // b -= -18;// 8: d-= $B -18
    // ++b;// 9: ++d $B
    // b.add_month(-18);// 10: add_month $B -18
    // --b;// 11: --d $B
    // // 12: dump-info $B
    // b.add_year(18);// 13: add_year  $B  18
    // b += 18;// 14: d+= $B 18
    // b.add_month(18);// 15: add_month $B  18
    // b -= 18;// 16: d-= $B 18
    // b += -18;// 17: d+= $B -18
    // b.add_year(-18);// 18: add_year  $B -18
    // b -= -18;// 19: d-= $B -18
    // ++b;// 20: ++d $B
    // b.add_month(-18);// 21: add_month $B -18
    // --b;// 22: --d $B
    // // 23: dump-info $B
    // b.add_year(17);// 24: add_year  $B  17
    // b += 17;// 25: d+= $B 17
    // b.add_month(17);// 26: add_month $B  17
    // b -= 17;// 27: d-= $B 17
    // b += -17;// 28: d+= $B -17
    // b.add_year(-17);// 29: add_year  $B -17
    // b -= -17;// 30: d-= $B -17
    // ++b;// 31: ++d $B
    // b.add_month(-17);// 32: add_month $B -17
    // --b;// 33: --d $B
    // // 34: dump-info $B


    lab2::Date * c = new lab2::Julian(2097,2,15);
    // lab2::Julian c(2097, 2, 15); // 35: ymd-construct julian $C 2097 2 15
    c->add_year(16);// 36: add_year  $C  16
    *c += 16;// 37: d+= $C 16
    c->add_month(16);// 38: add_month $C  16
    *c -= 16;// 39: d-= $C 16
    *c += -16;// 40: d+= $C -16
    c->add_year(-16);// 41: add_year  $C -16
    *c -= -16;// 42: d-= $C -16
    ++(*c);// 43: ++d $C
    c->add_month(-16);// 44: add_month $C -16
    --(*c);// 45: --d $C
    // 46: dump-info $C
    c->add_year(18);// 47: add_year  $C  18
    *c += 18;// 48: d+= $C 18
    c->add_month(18);// 49: add_month $C  18
    *c -= 18;// 50: d-= $C 18
    *c += -18;// 51: d+= $C -18
    c->add_year(-18);// 52: add_year  $C -18
    *c -= -18;// 53: d-= $C -18
    ++(*c);// 54: ++d $C
    c->add_month(-18);// 55: add_month $C -18
    --(*c);// 56: --d $C
    // 57: dump-info $C
    c->add_year(8);// 58: add_year  $C  8
    *c += 8;// 59: d+= $C 8
    c->add_month(8);// 60: add_month $C  8
    *c -= 8;// 61: d-= $C 8
    *c += -8;// 62: d+= $C -8
    c->add_year(-8);// 63: add_year  $C -8
    *c -= -8;// 64: d-= $C -8
    ++(*c);// 65: ++d $C
    c->add_month(-8);// 66: add_month $C -8
    --(*c);// 67: --d $C
    // 68: dump-info $C
    std::cout << "Before copy-assign C: " << *c << ", mod: " << c->mod_julian_day() << std::endl; 
    // 69: copy-assign $C $B
    lab2::Date * b = new lab2::Gregorian(2097,3,5);
    // lab2::Gregorian b(2097, 3, 5);
    std::cout << "Before copy-assign B: " << *b << ", mod: " << b->mod_julian_day() << std::endl; 
    std::cout << "Copy assign: C <- B" << std::endl;
    *c = *b;
    std::cout << "After copy-assign C: " << *c << ", mod: " << c->mod_julian_day() << std::endl; 
    std::cout << "After copy-assign B: " << *b << ", mod: " << b->mod_julian_day() << std::endl; 
    
    std::cout << "Kattis: $B => '2097-02-20, mod_julian_day() = 87037' should have been '2097-03-05, mod_julian_day() = 87037" << std::endl;
}

void test_copy_assign() {
	/*lab2::Julian j1(1993,2,16);
	lab2::Julian j2(1993,8,8);
	j1 = j1;
	j1 = j2;
	
	lab2::Gregorian g(2008,1,1);
	j1=g;
	std::cout << j1 << std::endl;*/
	
	lab2::Date *jp = new lab2::Julian(1994,2,2);
	lab2::Date *gp = new lab2::Gregorian(1996,9,9);
	*gp = *jp;
	std::cout << *jp << std::endl;
}


int main() {
	/*test_cout();
    test_increment();
    test_feminism();
    test_convert();
    test_pointers();
    test_add_month();
    test_add_year(); 
    test_relational();
    test_kattis1();
    test_kattis2();*/
    
    test_calendar();
    
    // lab2::Gregorian c(2134,2,29);
    // std::cout << c << std::endl;
    // test_copy_assign();
    // lab2::Gregorian j(1993,2,28);
    // std::cout << j << std::endl;
    // // std::cout << "g: " << g << ", mod: " << g.mod_julian_day() << std::endl;
    // lab2::Julian g(j);
    // std::cout << j.mod_julian_day() << ", " << g.mod_julian_day() << std::endl;
    // std::cout << g << std::endl;
    // j = g;
    // // std::cout << "after copy con j: " << j << ", mod: " << j.mod_julian_day() << std::endl;
    //
    // lab2::Gregorian g1;
    // // std::cout << "g1: " << g1 << ", mod: " << g1.mod_julian_day() << std::endl;
    // lab2::Julian j1;
    // // std::cout << "j1: " << j1 << ", mod: " << j1.mod_julian_day() << std::endl;
    // j1 = g1;
    //
	// lab2::Date *jp = new lab2::Julian(2013,1,2);
    // // std::cout << "*jp: " << *jp << ", mod: " << jp -> mod_julian_day() << std::endl;
	// lab2::Date *gp = new lab2::Gregorian();
    // // std::cout << "*gp: " << *gp << ", mod: " << gp -> mod_julian_day() << std::endl;
	// *gp = *jp;
    // // std::cout << "*gp: " << *gp << ", mod: " << gp -> mod_julian_day() << std::endl;
}
