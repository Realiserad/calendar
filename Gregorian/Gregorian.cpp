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
}
