#include "Date.hpp"

namespace lab2 {
	int Date::year() const { return mYear; }
	unsigned Date::month() const { return mMonth; }
	unsigned Date::day() const {	return mDay; }
	
	Date::Date(int year, int month, int day) 
		: mYear(year), 
		  mMonth(month), 
		  mDay(day) {
		// Do some error checking here
	}
}
