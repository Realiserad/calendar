#ifndef __GREGORIAN
#define __GREGORIAN
#include "date.hpp"
#include "julian.hpp"

namespace lab2 {
	class Gregorian : public Date {
        public:
        Gregorian(int , int , int);
		/* Default constructor. Should construct a 
		 * Gregorian calendar from the current date. */
        Gregorian();
        Gregorian(const Date&);
        Gregorian operator++(int);
        Gregorian& operator++(); // Prefix increment
        Gregorian operator--(int); // Postfix decrement
        Gregorian& operator--(); // Prefix decrement
        Gregorian& operator+=(const int); // addition assignment
        Gregorian& operator-=(const int); // subtraction assignment
    };
}
#endif
