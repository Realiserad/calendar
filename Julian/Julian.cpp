#include <ctime>
#include <iostream>
#include "../Julian/Julian.hpp"
#include "../Date/Date.hpp"

namespace lab2 {
    Julian::Julian(int y, int m, int d) : Date(y,m,d) { 
        // Error checking
    }
    
    Julian::Julian(Gregorian &g) {
		mDay = g.day();
		mYear = g.year();
		mMonth = g.month();
		convert_to_julian();
	}
}
