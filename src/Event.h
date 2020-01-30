/*
	Author: Rubén Rentero Trejo.

	Event.
	Header file.
*/

#ifndef EVENT_H
#define EVENT_H
#include <Arduino.h>
#include "Location.h"

class Event {
	// Properties
	int 		id;
	const char* title;
	const char* description;
	Location 	location;

	public:	
		// Constructor
		Event();
		Event(int _id, const char* _title, const char* _description, const Location _location);

		// Setters & Getters
		void 	setId(int _id);
		void	setTitle(const char* _title);
		void 	setDescription(const char* _description);
		void 	setLocation(Location _location);

		int			getId();
		const char* getTitle();
		const char* getDescription();
		Location 	getLocation();

};


#endif