#ifndef __GREGORIAN
#define __GREGORIAN
#include "../Date/Date.hpp"
#include "../Julian/Julian.hpp"

namespace lab2 {
	class Gregorian : public Date {
        public:
		/* Default constructor. Should construct a 
		 * Gregorian calendar from the current date. */
            Gregorian();
            Gregorian(const Julian&);
    };
}
#endif
