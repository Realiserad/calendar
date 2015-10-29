#include <ctime>
#include <iostream>
#include "Gregorian.hpp"
#include "../Julian/Julian.hpp"
#include "../Date/Date.hpp"

namespace lab2 {
	Gregorian::Gregorian(int y, int m, int d) : Date(y,m,d, true) {}
	Gregorian::Gregorian() : Date() {
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
    Gregorian& Gregorian::operator++(int) {
		++mDay;
		if (mMonth == 1 || mMonth == 3 || mMonth == 5 || mMonth == 7 || mMonth == 8 || mMonth == 10 || mMonth == 12) {
			if (mDay > 31) {
				mDay = 1;
				++mMonth;
				if (mMonth > 12) {
					mMonth = 1;
					++mYear;
				}
			}
		}
		else if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
			if (mDay > 30) {
				mDay = 1;
				++mMonth;
				if (mMonth > 12) {
					mMonth = 1;
					++mYear;
				}
			}
		}
		else if (mMonth == 2) {
			if (is_leap_year()) {
				// Leap year
				if (mDay > 29) {
					++mMonth;
					mDay = 1;
				}
			} else {
				// Not a leap year
				if (mDay > 28) {
					++mMonth;
					mDay = 1;
				}
			}
		}
		return *this;
	}
}
