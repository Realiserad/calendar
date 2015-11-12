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
        if (d.type() == J) {
            std::cout << "Copy constructur" << std::endl;
            std::cout << "Convert from Julian -> Gregorian"  << std::endl;
        }
    }
    
    // -------------------- Virtual operators/functions ------------------
    Gregorian& Gregorian::operator=(const Date& d) {
        if (d.type() == J) {
            std::cout << "Copy assignment operator ==" << std::endl;
            std::cout << "Convert from Julian -> Gregorian"  << std::endl;
        }
        return *this;
    }

    Type Gregorian::type() const { return Type(G); }
}
