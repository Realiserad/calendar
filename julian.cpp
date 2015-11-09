#include <ctime>
#include <iostream>
#include <stdexcept>
#include "julian.hpp"
#include "date.hpp"
#include "gregorian.hpp"

namespace lab2 {
    Julian::Julian(int y, int m, int d) : Date(y, m, d, false) {}
    
    // Create a Julian calendar with the current date.
    Julian::Julian() {
		gregorian = false;
		// Get UNIX timestamp in ms
		time_t ms = time(0);
		// Convert to Gregorian calendar format
		struct tm *now = localtime(&ms);
		mYear = now->tm_year + 1900;
		mMonth = now->tm_mon + 1;   
		mDay = now->tm_mday;
		// Convert to Julian
		convert_to_julian();
	}
    
    Julian::Julian(const Date &d) {
		gregorian = false;
		mDay = d.day();
		mYear = d.year();
		mMonth = d.month();
		if (d.is_gregorian()) {
			convert_to_julian();
		}
	}
	
	Julian& Julian::operator=(Date& d) {
		mDay = d.day();
		mYear = d.year();
		mMonth = d.month();
		if (d.is_gregorian()) {
			convert_to_julian();
		}
		return *this;
	}
}
