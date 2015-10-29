#include "Date.hpp"
#include <stdexcept>
#include "../Gregorian/Gregorian.hpp"
namespace lab2 {
	Date::Date(int year, int month, int day, bool gregorian) 
		: mYear(year), 
		  mMonth(month), 
		  mDay(day),
		  gregorian(gregorian) {
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
	
	bool Date::is_gregorian() const {
		return gregorian;
	}
	
	int Date::year() const { return mYear; }
    unsigned int Date::month() const { return mMonth; }
    unsigned int Date::day() const { return mDay; }
	
	unsigned int Date::week_day() {
		return 0;
	}
	
	unsigned int Date::days_per_week() {
		return 7;
	}
	
	unsigned int Date::days_this_month() {
		return 31;
	}
	
	std::string Date::week_day_name() {
		return "";
	}
	
	std::string Date::month_name() {
		return "";
	}
	
	template <typename T>
	T Date::add_year(int y) {
		return this;
	}
	
	template <typename T>
	T Date::add_month(int m) {
		return this;
	}
	
	int Date::mod_julian_day() {
		return 1337;
	}
	
	Date::~Date() {}
	
	/// Convert the date stored in this object to Julian.
	void Date::convert_to_julian() {
		convert( true );
	}
	
	void Date::convert_to_gregorian() {
		convert( false );
	}
	
	/// Convert the date stored in the current object from
	/// Gregorian to Julian, or from Julian to Gregorian depending
	/// on the flag given as argument.
	/// @param convert_to_julian True iff convert from Gregorian to Julian
	void Date::convert(bool convert_to_julian) {
		// Ref: https://en.wikipedia.org/wiki/Julian_day#Calculation
		
		//////////////////////////////////////////////////////
		//	Convert the current date to Julian Day (JD)
		//////////////////////////////////////////////////////
		int a = (14 - mMonth) / 12;
		int y = mYear + 4800 - a;
		int mm = mMonth + 12*a - 3;
		
		double JD;
		if (convert_to_julian) {
			// For a date in the gregorian calendar
			JD = mDay + ((153*mm + 2) / 5) + (365*y) + (y/4) - (y/100) + (y/400) - 32045;
            // std::cout << "if - sats " << JD << std::endl;
		} else {
			// For a date in the Julian calendar
			JD = mDay + ((153*mm + 2) / 5) + (365*y) + (y/4) - 32083;
            // std::cout << "else - sats " << JD << std::endl;
		}
		
		//////////////////////////////////////////////////////
		//	Convert JD to (year, month, day) in the calendar 
		//	format specified by convert_to_julian
		//////////////////////////////////////////////////////
        int f;
        y = 4716;
        int j = 1401;
        int m = 2;
        int n = 12;
        int r = 4;
        int p = 1461; 
        int v = 3;
        int u = 5;
        int s = 153;
        int w = 2; 
        int B = 274277;
        int C = -38;
		if (convert_to_julian) {
			// For the Julian calendar, calculate:
            f = JD + j; 
			// b = 0;
			// c = JD + 32082;
		} else {
            f = JD + j + (((4*JD+B)/146097)*3)/4+C;
			// For the Gregorian calendar, calculate:
			// double a = JD + 32044;
			// b = (4*a+3)/146097;
			// c = a - ((146097*b)/4);
		}
		
        int e = r*f+v;
        int g = (e % p)/r;
        int h = u*g+w;
        mDay = (h % s)/u+1;
        mMonth = ((h/s+m)%n)+1;
        mYear = (e/p)-y+(n+m-mMonth)/n;
		// Then for both calendars, calculate:
		// double d = (4*c+3)/1461;
		// double e = c - ((1461*d)/4);
		// double m = (5*e+2)/153;
		//
		// mDay = e - ((153*m + 2)/5) + 1;
		// mMonth = m + 3 - (12*(m/10));
		// mYear = (100*b) + d - 4800 + (m/10);
	}

    bool operator==(const Date& a, const Date& b) {
        // Checking if it is the same type of date
        if ( (a.is_gregorian() && b.is_gregorian()) || (!a.is_gregorian() && !b.is_gregorian()) ) {
           if ((a.year() == b.year()) && (a.month() == b.month()) && (a.day() == b.day())) {
               return true;
           } 
           else return false; 
        }
        // Check gregorian == julian
        else if ( a.is_gregorian() && !b.is_gregorian() ) {
            Gregorian tempX(b); 
            if ((a.year() == tempX.year()) && (a.month() == tempX.month()) && (a.day() == tempX.day())) 
                return true;
            else return false;
        }
        // Check julian == gregorian
        else if ( !a.is_gregorian() && b.is_gregorian() ) {
            Julian tempX(b); 
            if ((a.year() == tempX.year()) && (a.month() == tempX.month()) && (a.day() == tempX.day())) 
                return true;
            else return false;
        }
        else return false;
    }
}
