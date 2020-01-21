/*
	Author: Rubén Rentero Trejo.

	Event.
	Source file.
*/

#include <stdio.h>
#include "User.h"

User::User(){
	id=0;
	preferences="";
}

User::User(const char* _id, const char* _preferences){
	id=_id;
	preferences=_preferences;
}

// Setters & Getters
void 	User::setId(const char* _id){
	id=_id;
}
void	User::setPreferences(const char* _preferences){
	preferences=_preferences;
}

const char*	User::getId(){
	return id;
}
const char* User::getPreferences(){
	return preferences;
}