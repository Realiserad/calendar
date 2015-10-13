#ifndef __DATE
#define __DATE
namespace lab2
{
	/* Contains different calendar formats. Each calendar
	 * format has its own Date-implementation. */
	enum CalendarFormat {
		// Julian calendar format.
		JULIAN,
		// Gregorian calendar format.
		GREGORIAN
	};
	
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
		int y, m, d;
		CalendarFormat f;
		public:
		/* Default construct with todays date. */
		Date();
		/* Construct a date from the triple (year, month, day)
		 * specified in the date format used by the class. Throws 
		 * std::invalid_argument if an invalid date is given. In
		 * particular, the date must be in the range 1858-01-01
		 * to 2558-12-31. */
		Date(int year, int month, int day);
		/* Copy-construct from another Date instance. Performs a
		 * conversation between Julian and Gregorian if required. */
		Date(Date &date);
		/* Default destructor. IMPORTANT! The destructor should be
		 * declared virtual to prevent resource leaks. */
		virtual ~Date();
		/* Copy-assign from another Date instance. Performs a
		 * conversation between Julian and Gregorian if required. */
		Date& operator=(Date &date);
		/* Returns a CalendarFormat specifying the type of calendar
		 * format used by this class. The value returned by this method
		 * can be used to determine if a conversation is needed, e.g in
		 * the copy-assign constructor (depending on your implementation). */
		virtual CalendarFormat format() const;
		/* Returns the year of this date. */
		virtual int year() const;
		/* Returns the month of this date. */
		virtual int month() const;
		/* Returns the day of this date. */
		virtual int day() const;
		/* Returns the number associated with the current weekday. */
		virtual int week_day() const = 0;
	};
}
#endif
