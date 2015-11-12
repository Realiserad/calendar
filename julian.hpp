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

        // Virtual operators/functions
        virtual Julian& operator=(const Date&) override;
        virtual Type type() const override;
	};
}
#endif
