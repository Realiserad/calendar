#include "date.hpp"
#include <stdexcept>
#include "gregorian.hpp"
namespace lab2 {
    // --------------------------- PROTECTED -------------------------------------
	void Date::convert(Type t) {
		// Ref: https://en.wikipedia.org/wiki/Julian_day#Calculation
		
		//////////////////////////////////////////////////////
		//	Convert the current date to Julian Day (JD)
		//////////////////////////////////////////////////////
		int JD = julian_day(t);
		
		//////////////////////////////////////////////////////
		//	Convert JD to (year, month, day) in the calendar 
		//	format specified by convert_to_julian
		//////////////////////////////////////////////////////
        int f;
        int y = 4716;
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
		if (this -> type() == J) {
			// For the Julian calendar, calculate:
            f = JD + j; 
		} 
        else if (this -> type() == G) {
			// For the Gregorian calendar, calculate:
            f = JD + j + (((4*JD+B)/146097)*3)/4+C;
		}
        else f = -1; // Nor Gregorian or Julian
		
        int e = r*f+v;
        int g = (e % p)/r;
        int h = u*g+w;
        mDay = (h % s)/u+1;
        mMonth = ((h/s+m)%n)+1;
        mYear = (e/p)-y+(n+m-mMonth)/n;
	}

	int Date::julian_day(Type t) const {
		int a = (14 - mMonth) / 12;
		int y = mYear + 4800 - a;
		int mm = mMonth + 12*a - 3;
		
		int JD;
		if (t == G) {
			// For a date in the gregorian calendar
			JD = mDay + ((153*mm + 2) / 5) + (365*y) + (y/4) - (y/100) + (y/400) - 32045;
            // std::cout << "if - sats " << JD << std::endl;
		} 
        else if (t == J) {
			// For a date in the Julian calendar
			JD = mDay + ((153*mm + 2) / 5) + (365*y) + (y/4) - 32083;
            // std::cout << "else - sats " << JD << std::endl;
		}
        else return -1; // Nor Gregorian or Julian
		return JD;
	}

	int Date::julian_day() const {
		int a = (14 - mMonth) / 12;
		int y = mYear + 4800 - a;
		int mm = mMonth + 12*a - 3;
		
		int JD;
		if (this -> type() == G) {
			// For a date in the gregorian calendar
			JD = mDay + ((153*mm + 2) / 5) + (365*y) + (y/4) - (y/100) + (y/400) - 32045;
            // std::cout << "if - sats " << JD << std::endl;
		} 
        else if (this -> type() == J) {
			// For a date in the Julian calendar
			JD = mDay + ((153*mm + 2) / 5) + (365*y) + (y/4) - 32083;
            // std::cout << "else - sats " << JD << std::endl;
		}
        else return -1; // Nor Gregorian or Julian
		return JD;
	}
    
	bool Date::is_leap_year() const {
		if (this -> type() == G) {
			return mYear % 4 == 0 && (mYear % 100 != 0 || mYear % 400 == 0);
		}
		return mYear % 4 == 0;
	}
    
	Date& Date::add_days(int days_to_add) {
		if (days_to_add < 0) {
			for (int i = 0; i > days_to_add; --i) {
				remove_day();
			}
		}
		else {
			for (int i = 0; i < days_to_add; ++i) {
				add_day();
			}
		}
		return *this;
	}

	Date& Date::add_day() {
        ++mDay;
        if (mDay > int(days_this_month()) ) {
            mDay = 1;
            ++mMonth;
            if (mMonth > 12) {
                mMonth = 1;
                ++mYear;
            }
        }
        return *this;
	}

	Date& Date::remove_days(int days_to_remove) {
		if (days_to_remove < 0) {
			for (int i = 0; i > days_to_remove; --i) {
				add_day();
			}
		}
		else {
			for (int i = 0; i < days_to_remove ; ++i) {
				remove_day();
			}
		}
		return *this;
	}

	Date& Date::remove_day() {
		--mDay;
		if (mDay < 1) {
			mMonth--;
			if (mMonth == 1 || mMonth == 3 || mMonth == 5 || mMonth == 7 || mMonth == 8 || mMonth == 10 || mMonth == 12) {
				mDay = 31;
			}
			else if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
				mDay = 30;
			}
			else if (mMonth == 2) {
				mDay = is_leap_year() ? 29 : 28;
			}
			if (mMonth < 1) {
				mMonth = 12;
                mDay = 31;
				--mYear;
			}
		}
		
		return *this;
	}

    // ---------------------- Constructors / destructor ----------------------------

	Date::Date(int year, int month, int day) 
		: mYear(year), 
		  mMonth(month), 
		  mDay(day) {
		// Do some error checking here
	}
	
    Date::Date (const Date& d) {
        mYear = d.year();
        mMonth = d.month();
        mDay = d.day();
    }

    int Date::year() const { return mYear; }

    unsigned int Date::month() const { return mMonth; }
    
    unsigned int Date::day() const { return mDay; }
	
	unsigned int Date::week_day() const {
		// https://en.wikipedia.org/wiki/Julian_day
		return (julian_day() % 7) + 1;
	}
	
	unsigned int Date::days_per_week() const {
		return 7;
	}
	
	unsigned int Date::days_this_month() const {
		if (mMonth == 1 || mMonth == 3 || mMonth == 5 || mMonth == 7 || mMonth == 8 || mMonth == 10 || mMonth == 12) {
			return 31;
		}
		if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
			return 30;
		}
		if (mMonth == 2) {
			if (is_leap_year()) {
				return 29;
			}
			return 28;
		}
		return -1;
	}
	
	
	std::string Date::week_day_name() const {
		int w =  week_day();
		if (w == 1) return "Monday";
		if (w == 2) return "Tuesday";
		if (w == 3) return "Wednesday";
		if (w == 4) return "Thursday";
		if (w == 5) return "Friday";
		if (w == 6) return "Saturday";
		return "Sunday";
	}
	
	std::string Date::month_name() const {
		if (mMonth == 1) {
			return "January";
		}
		if (mMonth == 2) {
			return "February";
		}
		if (mMonth == 3) {
			return "March";
		}
		if (mMonth == 4) {
			return "April";
		}
		if (mMonth == 5) {
			return "May";
		}
		if (mMonth == 6) {
			return "June";
		}
		if (mMonth == 7) {
			return "July";
		}
		if (mMonth == 8) {
			return "August";
		}
		if (mMonth == 9) {
			return "September";
		}
		if (mMonth == 10) {
			return "October";
		}
		if (mMonth == 11) {
			return "November";
		}
		if (mMonth == 12) {
			return "December";
		}
		return "Unknown";
	}
	
	Date& Date::add_year(int n) {
		mYear += n;
		if (mMonth == 2 && mDay == 29 && !is_leap_year()) {
			mDay--;
		}
		return *this;
	}
	
	Date& Date::add_month(int n) {
		int years = n / 12;
		int months = n - (years * 12);
		add_year(years);
		mMonth += months;

        if (mMonth < 1) {
            mMonth = 12 + mMonth;
            --mYear;
        }

		if (mMonth > 12) {
			++mYear;
			mMonth -= 12;
		}
		if (mMonth == 4 || mMonth == 6 || mMonth == 9 || mMonth == 11) {
			if (mDay > 30) {
				mDay = 30;
			}
		}
		if (mMonth == 2) {
			if (is_leap_year()) {
				if (mDay > 29) {
					mDay = 29;
				}
			} else {
				if (mDay > 28) {
					mDay = 28;
				}
			}
		}
		return *this;
	}
	
	int Date::mod_julian_day() const {
		return julian_day() - 2400000.5;
	}

    std::ostream& operator <<(std::ostream& os, const Date& date) {
        os << date.year() << "-" << date.month() << "-" << date.day();
        return os;
    }

    bool operator==(const Date& a, const Date& b) {
        return a.mod_julian_day() == b.mod_julian_day();
    }

    
    bool operator!=(const Date &a, const Date& b) {
		return !(a == b);
	}
	
	
	int operator -(const Date& l, const Date& r) {
		return l.julian_day() - r.julian_day();
	}

	Date Date::operator++(int) {
		Date d = *this;
		add_day();
		return d;
	}
	
	Date& Date::operator++() {
		return add_day();
	}
	
	Date Date::operator--(int) {
		Date d = *this;
		return remove_day();
		return d;
	}
	
	Date& Date::operator--() {
		return remove_day();
	}

	Date& Date::operator+=(int days_to_add) {
		return add_days(days_to_add);
	}

	Date& Date::operator-=(int days_to_remove) {
		return remove_days(days_to_remove);
	}

	bool Date::operator>=(const Date& d) const {
		return julian_day()>=d.julian_day();
	}
    
	bool Date::operator>(const Date& d) const  {
		return julian_day()>d.julian_day();
	}

	bool Date::operator<(const Date& d) const {
		return julian_day() < d.julian_day();
	}
	
	bool Date::operator<=(const Date& d) const {
		return julian_day()<=d.julian_day();
	}

	
	
	
	
	
}
