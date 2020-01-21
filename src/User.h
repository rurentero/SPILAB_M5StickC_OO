/*
	Author: Rubén Rentero Trejo.

	User.
	Header file.
*/

#ifndef USER_H
#define USER_H
#include <Arduino.h>

class User {
	// Properties
	const char* id;
	const char* preferences;

	public:	
		// Constructor
		User();
		User(const char* _id, const char* _preferences);

		// Setters & Getters
		void 	setId(const char* _id);
		void	setPreferences(const char* _preferences);

		const char*	getId();
		const char* getPreferences();

};


#endif