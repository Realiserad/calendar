#include "date.hpp"

namespace lab2 {
	int Date::year() const {
		return y;
	}
	
	int Date::month() const {
		return m;
	}
	
	int Date::day() const {
		return d;
	}
	
	Date::Date(int year, int month, int day) : y{year}, m{month}, d{day} {
		// Do nothing
	}
}
