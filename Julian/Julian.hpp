#ifndef __JULIAN
#define __JULIAN
#include "../Date/Date.hpp"

namespace lab2 {
	class Julian : Date {
		/* Default constructor. Should construct a 
		 * Julian calendar from the current date. */
		Julian();
	};
	virtual unsigned int month() override {
		int mj; // month in Julian
		return mj;
	}
}
#endif
