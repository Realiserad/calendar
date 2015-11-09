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
		Julian operator++(int); // Postfix increment
        Julian& operator++(); // Prefix increment
        Julian operator--(int); // Postfix decrement
        Julian& operator--(); // Prefix decrement
        Julian& operator+=(const int); // addition assignment
        Julian& operator-=(const int); // subtraction assignment
	};
}
#endif
