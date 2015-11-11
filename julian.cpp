#include <ctime>
#include "julian.hpp"
#include "date.hpp"
#include "gregorian.hpp"

#define KATTIS (0) 

#if KATTIS
#include "kattistime.h"
#endif 

namespace lab2 {
    Julian::Julian(int y, int m, int d) : Date(y, m, d, false) {}
    
    // Create a Julian calendar with the current date.
    Julian::Julian() {
#if KATTIS
        // kattis time include "kattistime.h"
        time_t mytime;
        k_time(&mytime);
        struct tm *now = gmtime(&mytime);
#else
        // local time
		time_t ms = time(0); 
		struct tm *now = gmtime(&ms);
#endif

		// Convert to Gregorian calendar format
		mYear = now->tm_year + 1900;
		mMonth = now->tm_mon + 1;   
		mDay = now->tm_mday;
        
        // Gregorian date -> Julian
        gregorian = true;
		convert_to_julian();
        gregorian = false;
	}
    
    Julian::Julian(const Date &d) {
		mDay = d.day();
		mYear = d.year();
		mMonth = d.month();
		if (d.is_gregorian()) {
            gregorian = true; 
			convert_to_julian();
            gregorian = false; 
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
	
	Julian& Julian::operator=(Julian& j) {
		mDay = j.day();
		mYear = j.year();
		mMonth = j.month();
		return *this;
	}
}
