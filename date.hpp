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
        // ------------------------------ PROTECTED ----------------------------
		protected:

        // ------------------------- Protected variables -------------------------
		int mYear, mMonth, mDay;

        // ------------------ Additional optional functions -----------------------
        
        /* Convert specified Type to current Type*/
		void convert(Type);
        
        /* Get the Julian for specified Type */
		int julian_day(Type) const;

        /* Get the Julian for this object */
		int julian_day() const;

        /* Increments the current day by n */
        Date& add_days(int);

        /* Increments the current day by 1 */
        Date& add_day();

        /* Decrements the current day by n */
        Date& remove_days(int);

        /* Decrements the current day by 1 */
        Date& remove_day();

        // ------------------------------- PUBLIC --------------------------
        private:
        
        // ------------------ Additional optional functions -----------------------
        
        /* Checks leap year */
		bool is_leap_year() const;


		public:
        
        // ------------------ Additional optional functions -----------------------

        /* Get Type of object */
        virtual Type type() const { return Type(D); }
		
        // ------------------ Constructors / destructor ---------------------

        /* Construct a date from the triple (year, month, day)
		 * specified in the date format used by the class. Throws 
		 * std::invalid_argument if an invalid date is given. In
		 * particular, the date must be in the range 1858-01-01
		 * to 2558-12-31. */
		Date(int year, int month, int day);

        /* Copy constructor */
        Date (const Date& d);

		/* Default constructor */
		Date() = default;

		/* Important to define the destructor as virtual! */
		virtual ~Date() { };
        
        // ----------------------- Mandatory functions -----------------------
        
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

        /* Increments the current year by 1. */
        Date& add_year();
        
		/* Increments the current year by the number specified. */
		Date& add_year(int);

        /* Increments the current month by 1. */
        Date& add_month();

		/* Increments the current year by the number specified. */
		Date& add_month(int);

		/* This function shall return the MJD representation of the current day. */
		int mod_julian_day() const;


        // -------------------- Virtual operators/functions ------------------
        
        /* Copy assignment operator */
        virtual Date& operator=(const Date& d) { 
            mYear = d.year();
            mMonth = d.month();
            mDay = d.day();
            return *this;
        }

        /* << operator */
		friend std::ostream& operator <<(std::ostream&, const Date&);
        
        /* == Operator */
        friend bool operator==(const Date&, const Date&);

        /* != Operator */
        friend bool operator!=(const Date&, const Date&);

        /* - Operator */
        friend int operator-(const Date&, const Date&);
        
        /* Postfix increment i++ */
        Date operator++(int); 

        /* Prefix increment ++i */
        Date& operator++(); 

        /* Postfix decrement i-- */
        Date operator--(int); 

        /* Prefix decement --i; */
        Date& operator--(); // Prefix decrement

        /* Addition assignment */
        Date& operator+=(int); 

        /* Subraction assignment */
        Date& operator-=(int); 

        /* Greater than operator */
        bool operator>(const Date&) const;

        /* Greater than or equal to operator */
        bool operator>=(const Date&) const;

        /* Less than operator */
        bool operator<(const Date&) const;

        /* Less than or equal to operator */
        bool operator<=(const Date&) const;
	};
}
#endif
