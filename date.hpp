#ifndef __DATE
#define __DATE
#include <string>
#include <iostream>
#include "type.hpp"

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
		bool gregorian;
		void convert(bool);
		void convert_to_julian( void );
		void convert_to_gregorian( void );
		public:
         
        // Copy constructor - behövs inte egenligen
        Date (const Date& d) {
            mYear = d.year();
            mMonth = d.month();
            mDay = d.day();
        }
        
        // -------------------- Virtual operators/functions ------------------
        virtual Date& operator=(const Date&) { return *this; }
        virtual Type type() const { return Type(D); }
        
		/* Construct a date from the triple (year, month, day)
		 * specified in the date format used by the class. Throws 
		 * std::invalid_argument if an invalid date is given. In
		 * particular, the date must be in the range 1858-01-01
		 * to 2558-12-31. */
		Date(int year, int month, int day, bool gregorian);
		/* Important to define the destructor as virtual! */
		virtual ~Date();
		/* Default constructor. */
		Date() = default;
		/* Returns the year of this date. */
		int year() const;
		/* Returns the month of this date. */
		unsigned int month() const;
		/* Returns the day of this date. */
		unsigned int day() const;
		/* Returns the number associated with the current weekday. */
		unsigned int week_day() const;
		/* Returns the number of days in a week. */
		unsigned int days_per_week() const;
		/* Returns the number of days in the current month. */
		unsigned int days_this_month() const;
		/* Returns the name of the current weekday. */
		std::string week_day_name() const;
		/* Returns name of current month. */
		std::string month_name() const;
		/* Increments the current year by the number specified. */
		Date& add_year(int);
		/* Increments the current year by the number specified. */
		Date& add_month(int);
		/* This function shall return the MJD representation of the current day. */
		int mod_julian_day() const;
		int julian_day() const;
		bool is_leap_year() const;
		
		bool is_gregorian() const;

        // ------------------------------------ operators --------------------
        /* << operator */
		friend std::ostream& operator <<(std::ostream& os, const Date& date) {
			os << date.year() << "-" << date.month() << "-" << date.day();
			return os;
		}
        // == Operator
        friend bool operator==(const Date&, const Date&);
        friend bool operator!=(const Date&, const Date&);

        friend int operator-(const Date&, const Date&);
        
        Date operator++(int); // Postfix increment
        Date& operator++(); // Prefix increment
        Date operator--(int); // Postfix decrement
        Date& operator--(); // Prefix decrement
        Date& operator+=(int); // addition assignment
        Date& operator-=(int); // subtraction assignment
        bool operator>(const Date&) const;
        bool operator>=(const Date&) const;
        bool operator<=(const Date&) const;
        bool operator<(const Date&) const;
        Date& add_days(int);
        Date& add_day();
        Date& remove_day();
        Date& remove_days(int);
        Date& add_year();
        Date& add_month();
	};
}
#endif
