#ifndef __JULIAN
#define __JULIAN
#include "../Date/Date.hpp"

namespace lab2 {
	class Julian : public Date {
		public:
		/* Default constructor. Should construct a 
		 * Julian calendar from the current date. */
		Julian(int, int, int);
	};
}
#endif
