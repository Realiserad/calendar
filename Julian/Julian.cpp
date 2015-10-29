#include <ctime>
#include <iostream>
#include "Julian.hpp"
#include "../Date/Date.hpp"
#include "../Gregorian/Gregorian.hpp"

namespace lab2 {
    Julian::Julian(int y, int m, int d) : Date(y,m,d, false) { 
        // Error checking
    }
    
    Julian::Julian(const Date &d) {
		mDay = d.day();
		mYear = d.year();
		mMonth = d.month();
		if (d.is_gregorian) {
			convert_to_julian();
		}
	}
}
