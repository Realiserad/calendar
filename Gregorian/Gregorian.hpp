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
            Gregorian(Julian&);
            // From date.hpp
            virtual int year() const override;
            virtual unsigned int month() const override;
            virtual unsigned int day() const override;
    };
}
#endif
