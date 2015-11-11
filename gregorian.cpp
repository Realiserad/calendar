#include <ctime>
#include "gregorian.hpp"
#include "julian.hpp"
#include "date.hpp"

#define KATTIS (0)

#if KATTIS
#include "kattistime.h"
#endif 

namespace lab2 {
	Gregorian::Gregorian(int y, int m, int d) : Date(y, m, d, true) {}
	Gregorian::Gregorian() {
		gregorian = true;

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
	}
	
    Gregorian::Gregorian(const Date& d) {
		mYear = d.year();
		mMonth = d.month();
		mDay = d.day();
		if (!d.is_gregorian()) {
            gregorian = false;
			convert_to_gregorian();
            gregorian = true;
		}
    }
    
    Gregorian& Gregorian::operator=(Date& d) {
		mMonth = d.month();
		mYear = d.year();
		mDay = d.day();
		if (!d.is_gregorian()) {
            gregorian = false;
			convert_to_gregorian();
            gregorian = true;
		}
		return *this;
	}
}
