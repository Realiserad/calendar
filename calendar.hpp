namespace lab2 {
	template <typename DateType>
	struct Event {
		std::string name;
		DateType date;
	};
	
	template <typename DateType>
	class Calendar<DateType> {
		DateType now;
		std::vector<Event> events;
		bool set_date(int, int, int);
		bool add_event(std::string);
		bool add_event(std::string, int);
		bool add_event(std::string, int, int);
		bool add_event(std::string, int, int, int); 
		bool remove_event(std::string);
		bool remove_event(std::string, int);
		bool remove_event(std::string, int, int);
		bool remove_event(std::string, int, int, int); 
	};
}
