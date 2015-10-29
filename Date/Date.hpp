#ifndef __DATE
#define __DATE
#include <string>
#include <iostream>
namespace lab2 {	
	/**
	 * Abstract class for a Date which specifies required
	 * functionality of derived classes "Gregorian" and
	 * "Julian". Read the method comments for detailed
	 * instructions of how each method should behave.
	 * Follows the specification: 
	 * http://www.tondering.dk/claus/cal/julperiod.php
	 * @author Bastian Fredriksson
	 * @author Sai Man Wong
	 */
	class Date {
		protected:
		int mYear, mMonth, mDay;
		void convert(bool);
		void convert_to_julian( void );
		void convert_to_gregorian( void );
		public:
		/* Construct a date from the triple (year, month, day)
		 * specified in the date format used by the class. Throws 
		 * std::invalid_argument if an invalid date is given. In
		 * particular, the date must be in the range 1858-01-01
		 * to 2558-12-31. */
		Date(int year, int month, int day);
		/* Important to define the destructor as virtual! */
		virtual ~Date();
		/* Default constructor. */
		Date() = default;
		/* Returns the year of this date. */
		virtual int year() const;
		/* Returns the month of this date. */
		virtual unsigned int month() const;
		/* Returns the day of this date. */
		virtual unsigned int day() const;
		/* Returns the number associated with the current weekday. */
		virtual unsigned int week_day();
		/* Returns the number of days in a week. */
		virtual unsigned int days_per_week();
		/* Returns the number of days in the current month. */
		virtual unsigned int days_this_month();
		/* Returns the name of the current weekday. */
		virtual std::string week_day_name();
		/* Returns name of current month. */
		virtual std::string month_name();
		/* Increments the current year by the number specified. */
		template <typename T> 
		T add_year(int);
		/* Increments the current year by the number specified. */
		template <typename T> 
		T add_month(int);
		/* This function shall return the MJD representation of the current day. */
		int mod_julian_day();
		
		friend std::ostream& operator <<(std::ostream& os, const Date& date) {
			os << date.year() << "-" << date.month() << "-" << date.day();
			return os;
		}
	};
}
#endif
