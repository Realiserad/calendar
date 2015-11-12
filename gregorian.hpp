#ifndef __GREGORIAN
#define __GREGORIAN
#include "date.hpp"
#include "julian.hpp"

namespace lab2 {
	class Gregorian : public Date {
        public:
        Gregorian();
        Gregorian(int, int, int);
        Gregorian(const Date&);

        // Virtual operators/functions
        virtual Gregorian& operator=(const Date&);
        virtual Type type() const; 
    };
}
#endif
