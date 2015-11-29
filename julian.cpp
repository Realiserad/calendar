#include <ctime>
#include "julian.hpp"
#include "date.hpp"
#include "gregorian.hpp"
#include <stdexcept>

#define KATTIS (0) 

#if KATTIS
#include "kattistime.h"
#endif 

namespace lab2 {
    Julian::Julian(int y, int m, int d) : Date(y, m, d) {
        if (mYear < 1858 || mYear> 2558) {
            throw std::out_of_range("Bad year");
        }
        if (mMonth < 1 || mMonth > 12) {
            throw std::invalid_argument("Bad month");
        }
        if (mDay < 1) {
            throw std::invalid_argument("Bad day");
        }
        int test = days_this_month();
        if (mDay > test) throw std::invalid_argument("Bad day");
    }
    
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
       // Convert gregorian to this object 
        convert(G);
	}
    
    Julian::Julian(const Date &d) {
        if (d.type() == G) {
            mYear = d.year();
            mMonth = d.month();
            mDay = d.day();
            convert(d.type());
        }
	}

    // -------------------- Virtual operators/functions ------------------
    Julian& Julian::operator=(const Date& d) {
        std::cout << "Julian = " << std::endl;
        if (d.type() == G) {
            mYear = d.year();
            mMonth = d.month();
            mDay = d.day();
            convert(d.type());
        }
        return *this;
    }
     
    Type Julian::type() const { return Type(J); }
}
