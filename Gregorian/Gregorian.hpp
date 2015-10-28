#ifndef __GREGORIAN
#define __GREGORIAN
#include "../Date/Date.hpp"

namespace lab2 {
	class Gregorian : Date {
		/* Default constructor. Should construct a 
		 * Gregorian calendar from the current date. */
		Gregorian();
	};
	virtual unsigned int month() override {
		return mMonth;
	}
}
#endif
