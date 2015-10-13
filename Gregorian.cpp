#include <ctime>
#include <iostream>
#include "date.cpp"
namespace lab2 {
	class Gregorian : Date {
			public:
			Gregorian() : Date() {
				time_t t = time(0);   // get time now
				struct tm *now = localtime( & t );
				y = now->tm_year + 1900;
				m = now->tm_mon + 1;   
				d   = now->tm_mday;
			}
	};
}
