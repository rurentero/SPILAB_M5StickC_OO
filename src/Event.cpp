/*
	Author: Rubén Rentero Trejo.

	Event.
	Source file.
*/

#include <stdio.h>
#include "Event.h"

Event::Event(){
	id = 0;
	title = "";
	description = "";
	location = Location();
}

Event::Event(int _id, const char* _title, const char* _description, Location _location){
	id = _id;
	title = _title;
	description = _description;
	location = _location;
}

// Setters & Getters
void Event::setId(int _id){
	id = _id;
}

void Event::setTitle(const char* _title){
	title = _title;
}
void Event::setDescription(const char* _description){
	description = _description;
}
void Event::setLocation(Location _location){
	location = _location;
}

int	Event::getId(){
	return id;
}
const char* Event::getTitle(){
	return title;
}
const char* Event::getDescription(){
	return description;
}
Location 	Event::getLocation(){
	return location;
}