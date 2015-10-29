#ifndef __GREGORIAN
#define __GREGORIAN
#include "../Date/Date.hpp"
#include "../Julian/Julian.hpp"

namespace lab2 {
	class Gregorian : public Date {
        public:
        Gregorian(int , int , int);
		/* Default constructor. Should construct a 
		 * Gregorian calendar from the current date. */
        Gregorian();
        Gregorian(const Date&);
        Gregorian& operator++(int);
        bool is_leap_year(int);
    };
}
#endif
