#ifndef __DATE
#define __DATE
namespace lab2 {	
	/**
	 * Abstract class for a Date which specifies required
	 * functionality of derived classes "Gregorian" and
	 * "Julian". Read the method comments for detailed
	 * instructions of how each method should behave.
	 * Follows the specification: http://goo.gl/ogFLZQ
	 * @author Bastian Fredriksson
	 * @author Sai Man Wong
	 */ 
	class Date {
		protected:
		int mYear, mMonth, mDay;
		public:
		/* Construct a date from the triple (year, month, day)
		 * specified in the date format used by the class. Throws 
		 * std::invalid_argument if an invalid date is given. In
		 * particular, the date must be in the range 1858-01-01
		 * to 2558-12-31. */
		Date(int year, int month, int day);
		/* Important to define the destructor as virtual! */
		virtual ~Date() = default;
		/* Default constructor. */
		Date() = default;
		/* Returns the year of this date. */
		virtual int year() const;
		/* Returns the month of this date. */
		virtual int month() const;
		/* Returns the day of this date. */
		virtual int day() const;
		/* Returns the number associated with the current weekday. */
		virtual int week_day() const;
	};
}
#endif
