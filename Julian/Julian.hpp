#ifndef __JULIAN
#define __JULIAN
#include "../Date/Date.hpp"
#include "../Gregorian/Gregorian.hpp"

namespace lab2 {
	class Julian : public Date {
		public:
		Julian();
		Julian(int, int, int);
		Julian(const Date&);
		Julian& operator++(int);
		bool is_leap_year(int);
	};
}
#endif
