#include <ctime>
#include <iostream>
#include "Gregorian.hpp"
#include "../Date/Date.hpp"

namespace lab2 {
	Gregorian::Gregorian() : Date() {
		// Get UNIX timestamp in ms
		time_t ms = time(0);
		// Convert to Gregorian calendar format
		struct tm *now = localtime(&ms);
		mYear = now->tm_year + 1900;
		mMonth = now->tm_mon + 1;   
		mDay = now->tm_mday;
	}
    Gregorian::Gregorian(Julian& j) {
       convert(mYear, mMonth, mDay, false); 
    }

    int Gregorian::year() const { return mYear; }
    unsigned Gregorian::month() const { return mMonth; }
    unsigned Gregorian::day() const { return mDay; }
}
