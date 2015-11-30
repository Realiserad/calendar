#include <stdexcept>
#include <ctime>
#include <iostream>
#include <assert.h>

#include "calendar.hpp"
#include "gregorian.hpp"
#include "julian.hpp"

namespace lab2 {
	template <typename DateType>
	Calendar<DateType>::Calendar() {
		time_t unix_timestamp = time(0); 
		struct tm *date = gmtime(&unix_timestamp);
		Gregorian g(date->tm_year + 1900, date->tm_mon + 1, date->tm_mday);
		now = g;
	}
	
	template <typename DateType>
	Calendar<DateType>::Calendar(DateType date) : now(date) {}
	
	template <typename DateType>
	bool Calendar<DateType>::set_date(int year, int month, int day) {
		try { 
			now = DateType(year, month, day);
			return true; 
		}
		catch (std::out_of_range &e) {
			return false;
		}
	}
	
	template <typename DateType>
	bool Calendar<DateType>::add_event(std::string event_name) {
		return add_event( event_name, now.day(), now.month(), now.year() );
	}
	
	template <typename DateType>
	bool Calendar<DateType>::add_event(std::string event_name, int day) {
		return add_event( event_name, day, now.month(), now.year() );
	}
	
	template <typename DateType>
	bool Calendar<DateType>::add_event(std::string event_name, int day, int month) {
		return add_event( event_name, day, month, now.year() );
	}
	
	template <typename DateType>
	bool Calendar<DateType>::add_event(std::string event_name, int day, int month, int year) {
		try {
			DateType date(year, month, day);
			if ( calendar_contains_event(event_name, date) )
				return false;
			event_names.push_back( event_name );
			event_dates.push_back( date );
			return true;
		}
		catch (std::out_of_range &e) {
			return false;
		}
	}
	
	template <typename DateType>
	bool Calendar<DateType>::calendar_contains_event(std::string &event_name, DateType &event_date) const {
		auto i = event_names.begin();
		auto j = event_dates.begin();
		while (i != event_names.end()) {
			if (*i == event_name && *j == event_date) {
				return true;
			} 
			++i;
			++j;
		}
		return false;
	}
	
	template <typename DateType>
	bool Calendar<DateType>::remove_event(std::string event_name) {
		return remove_event( event_name, now.day(), now.month(), now.year() );
	}
	
	template <typename DateType>
	bool Calendar<DateType>::remove_event(std::string event_name, int day) {
		return remove_event( event_name, day, now.month(), now.year() );
	}
	
	template <typename DateType>
	bool Calendar<DateType>::remove_event(std::string event_name, int day, int month) {
		return remove_event( event_name, now.day(), month, now.year() );
	}
	
	template <typename DateType>
	bool Calendar<DateType>::remove_event(std::string event_name, int day, int month, int year) {
		try {
			DateType date(year, month, day);
			return remove_calendar_event(event_name, date);
		}
		catch (std::out_of_range &e) {
			return false;
		}
	}
	
	template <typename DateType>
	bool Calendar<DateType>::remove_calendar_event(std::string &event_name, DateType &event_date) {
		auto i = event_names.begin();
		auto j = event_dates.begin();
		while (i != event_names.end()) {
			if (*i == event_name && *j == event_date) {
				event_names.erase(i);
				event_dates.erase(j);
				return true;
			}
			++i;
			++j;
		}
		return false;
	}
	
	template <typename DateType>
	std::ostream& operator<<(std::ostream &os, const Calendar<DateType> &calendar) {
		// https://en.wikipedia.org/wiki/ICalendar
		os << "BEGIN:VCALENDAR" << std::endl;
		os << "VERSION:2.0" << std::endl;
		auto i = calendar.event_names.begin();
		auto j = calendar.event_dates.begin();
		while (i != calendar.event_names.end()) {
			if (*j >= calendar.now) {
				print_calendar_entry(*i, *j, os);
			}
			++i;
			++j;
		}
		os << "END:VCALENDAR" << std::endl;
        return os;
    }
    
    template <typename DateType>
    void Calendar<DateType>::print_calendar_entry(std::string &event_name, DateType &event_date, std::ostream &os) {
		os << "BEGIN:VEVENT" << std::endl;
		os << "DTSTAMP:" << now.year() << now.month() << now.day() << "T120000Z" << std::endl;
		os << "ORGANIZER;CN=Bastian Fredriksson:MAILTO:bastianf@kth.se" << std::endl;
		os << "DTSTART:" << event_date.year() << event_date.month() << event_date.day() << "T000000Z" << std::endl;
		os << "DTEND:" << event_date.year() << event_date.month() << event_date.day() << "T235959Z" << std::endl;
		os << "SUMMARY:" << event_name << std::endl;
		os << "END:VEVENT" << std::endl;
	}
	
	template class Calendar<Gregorian>;
	template class Calendar<Julian>;
}
