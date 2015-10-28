#include <ctime>
#include <iostream>
#include "../Julian/Julian.hpp"
#include "../Date/Date.hpp"

namespace lab2 {
	Julian::Julian() : Date() {

	}

    int Julian::year() const { return mYear; }
    unsigned Julian::month() const { return mMonth; }
    unsigned Julian::day() const { return mDay; }
}
