#ifndef __JULIAN
#define __JULIAN
#include "date.hpp"
#include "gregorian.hpp"

namespace lab2 {
	class Julian : public Date {
		public:
		Julian();
		Julian(int, int, int);
		Julian(const Date&);
		Julian& operator=(Date&);
		Julian& operator=(Julian&);
		//Julian& operator=(Gregorian&);
	};
}
#endif
