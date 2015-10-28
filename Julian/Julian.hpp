#ifndef __JULIAN
#define __JULIAN
#include "../Date/Date.hpp"

namespace lab2 {
	class Julian : public Date {
		public:
		/* Default constructor. Should construct a 
		 * Julian calendar from the current date. */
		Julian();
        virtual int year() const override;
        virtual unsigned int month() const override;
		virtual unsigned int day() const override;
	};
}
#endif
