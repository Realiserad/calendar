#ifndef __CALENDAR
#define __CALENDAR

#include <string>
#include <vector>
#include <iostream>

namespace lab2 {
	template <typename DateType>
	class Calendar {
		DateType now;
		std::vector<DateType> event_dates;
		std::vector<std::string> event_names;
		bool calendar_contains_event(std::string&, DateType&) const;
		bool remove_calendar_event(std::string&, DateType&);
		
		public:
		explicit Calendar();
		explicit Calendar(DateType);
		bool set_date(int, int, int);
		bool add_event(std::string);
		bool add_event(std::string, int);
		bool add_event(std::string, int, int);
		bool add_event(std::string, int, int, int); 
		bool remove_event(std::string);
		bool remove_event(std::string, int);
		bool remove_event(std::string, int, int);
		bool remove_event(std::string, int, int, int);
		
		template <typename T>
		friend std::ostream& operator<<(std::ostream&, const Calendar<T>&);
	};
}

#endif
