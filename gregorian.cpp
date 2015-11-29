#include <ctime>
#include "gregorian.hpp"
#include "julian.hpp"
#include "date.hpp"
#include <stdexcept>

#define KATTIS (0)

#if KATTIS
#include "kattistime.h"
#endif 

namespace lab2 {
	Gregorian::Gregorian(int y, int m, int d) : Date(y, m, d) {
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

    Gregorian::Gregorian() {

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
        if (d.type() == J) {
            // std::cout << "Copy constructur" << std::endl;
            // std::cout << "Convert from Julian -> Gregorian"  << std::endl; 
            mYear = d.year();
            mMonth = d.month();
            mDay = d.day();
            convert(d.type());
        }
    }
    
    // -------------------- Virtual operators/functions ------------------
    Gregorian& Gregorian::operator=(const Date& d) {
        if (d.type() == J) {
            // std::cout << "Copy assignment operator ==" << std::endl;
            // std::cout << "Convert from Julian -> Gregorian"  << std::endl;
            mYear = d.year();
            mMonth = d.month();
            mDay = d.day();
            convert(d.type());
        }
        return *this;
    }

    Type Gregorian::type() const { return Type(G); }
}
