#include "Date.hpp"
#include <stdexcept>
namespace lab2 {
	Date::Date(int year, int month, int day) 
		: mYear(year), 
		  mMonth(month), 
		  mDay(day) {
		// Do some error checking here
		if (year < 1858 || year > 2558) {
			throw std::invalid_argument("Invalid year");
		}
		if (month < 1 || month > 12) {
			throw std::invalid_argument("Invalid month");
		}
		if (day < 1) {
			throw std::invalid_argument("Invalid day");
		}
		if (month == 1 ||
			month == 3 ||
			month == 5 ||
			month == 7 ||
			month == 8 ||
			month == 10 ||
			month == 12) {
				if (day > 31)
					throw std::invalid_argument("Invalid day");
			}
		if (month == 4 ||
			month == 6 ||
			month == 9 ||
			month == 11) {
				if (day > 30)
					throw std::invalid_argument("Invalid day");
			}
	}
	void Date::convert(int &year, int &month, int &day, bool julian) {
		// Ref: http://www.tondering.dk/claus/cal/julperiod.php
		
		// Calculate JD
		int a = (14 - mMonth) / 12;
		int y = mYear + 4800 - a;
		int mJD = mMonth + 12*a - 3;
		
		double JD, b, c;
		if (julian) {
			JD = mDay + ((153*mJD + 2) / 5) + (365*y) + (y/4) - 32083;
			b = 0;
			c = JD + 32082;
			
		} else {
			JD = mDay + ((153*mJD + 2) / 5) + (365*y) + (y/4) - (y/100) + (y/400) - 32045;
			double a = JD + 32044;
			b = (4*a+3)/146097;
			c = a - ((146097*b)/4);
		}
		
		double d = (4*c+3)/1461;
		double e = c - ((1461*d)/4);
		double m = (5*e+2)/153;
		
		day = e - ((153*m + 2)/5) + 1;
		month = m + 3 - (12*(m/10));
		year = (100*b) + d - 4800 + (m/10);
	}
}
