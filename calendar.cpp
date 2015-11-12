#include "calendar.hpp"

namespace lab2 {
	template <typename DateType>
	bool Calendar::set_date(int y, int m, int d) {
		now = DateType(y, m, d);
	}
	
	template <typename DateType>
	bool Calendar::add_event(std::string) {
		// TODO
	}
	
	bool Calendar::add_event(std::string, int) {
		// TODO
	}
	
	bool add_event(std::string, int, int);
	bool add_event(std::string, int, int, int); 
	bool remove_event(std::string);
	bool remove_event(std::string, int);
	bool remove_event(std::string, int, int);
	bool remove_event(std::string, int, int, int); 
}
