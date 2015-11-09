#include <ctime>
#include "gregorian.hpp"
#include "julian.hpp"
#include "date.hpp"

namespace lab2 {
	Gregorian::Gregorian(int y, int m, int d) : Date(y, m, d, true) {}
	Gregorian::Gregorian() {
		gregorian = true;
		// Get UNIX timestamp in ms
		time_t ms = time(0);
		// Convert to Gregorian calendar format
		struct tm *now = localtime(&ms);
		mYear = now->tm_year + 1900;
		mMonth = now->tm_mon + 1;   
		mDay = now->tm_mday;
	}
	
    Gregorian::Gregorian(const Date& d) {
		mYear = d.year();
		mMonth = d.month();
		mDay = d.day();
		gregorian = true;
		if (!d.is_gregorian()) {
			convert_to_gregorian();
		}
    }
    
    Gregorian& Gregorian::operator=(Date& d) {
		mMonth = d.month();
		mYear = d.year();
		mDay = d.day();
		if (!d.is_gregorian()) {
			convert_to_gregorian();
		}
		return *this;
	}
}
