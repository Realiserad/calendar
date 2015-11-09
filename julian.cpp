#include <ctime>
#include <iostream>
#include <stdexcept>
#include "julian.hpp"
#include "date.hpp"
#include "gregorian.hpp"

namespace lab2 {
    Julian::Julian(int y, int m, int d) : Date(y, m, d, false) { 
		// Do range check for february
        if (is_leap_year()) {
			if (m == 2 && d > 29) {
				throw std::out_of_range("A leap year can only contain at most 29 days in february");
			}
		} else {
			if (m == 2 && d > 28) {
				throw std::out_of_range("A non-leap year can contain at most 28 days in february");
			}
		}
    }
    
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
	
	Julian& Julian::add_day() {
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
		if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
			if (mDay > 30) {
				mDay = 1;
				++mMonth;
				if (mMonth > 12) {
					mMonth = 1;
					++mYear;
				}
			}
		}
		
		if (mMonth == 2) {
			if (mYear % 4 == 0) {
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
	
	Julian& Julian::add_days(int days_to_add) {
		for (int i = 0; i < days_to_add; ++i) {
			add_day();
		}
		return *this;
	}
	
	Julian& Julian::remove_day() {
		--mDay;
		if (mDay < 1) {
			if (mMonth == 1 || mMonth == 3 || mMonth == 5 || mMonth == 7 || mMonth == 8 || mMonth == 10 || mMonth == 12) {
				mDay = 31;
			}
			if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
				mDay = 30;
			}
			
			if (mMonth == 2) {
				mDay = is_leap_year() ? 29 : 28;
			}
			mMonth--;
			if (mMonth < 1) {
				mMonth = 12;
				--mYear;
			}
		}
		
		return *this;
	}
	
	Julian& Julian::remove_days(int days_to_remove) {
		for (int i = 0; i < days_to_remove; ++i) {
			remove_day();
		}
		return *this;
	}
	
	// Postfix increment e.g julian++
	Julian& Julian::operator++(int) {
		return add_day();
	}
	
	Julian& Julian::operator++() {
		return add_day();
	}
	
	// Postfix decrement e.g julian--
	Julian& Julian::operator--(int) {
		return remove_day();
	}
	
	Julian& Julian::operator--() {
		return remove_day();
	}
	
	Julian& Julian::operator+=(int days_to_add) {
		return add_days(days_to_add);
	}
	
	Julian& Julian::operator-=(int days_to_remove) {
		return remove_days(days_to_remove);
	} 
	
	Julian& Julian::add_month() {
		mMonth++;
		if (mMonth > 12) {
			mMonth = 0;
			mYear++;
		}
		if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
			if (mDay > 30) {
				mDay = 30;
			}
		}
		if (mMonth == 2) {
			if (!is_leap_year() && mDay > 28) {
				mDay = 28;
			}
		}
		return *this;
	}
	
	Julian& Julian::add_year() {
		++mYear;
		if (!is_leap_year() && mDay > 28) {
			mDay = 28;
		}
		return *this;
	}
}
