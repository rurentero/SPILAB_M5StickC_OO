/*
	Author: Rubén Rentero Trejo.

	Json Parser. Converts and create objects from DynamicJsonDocument to a specific object defined in OpenAPI.
	This class only parses objects used in the field "params".
	This class hightly depends on ArduinoJson library from Arduino.
	Header file.
*/

#ifndef JSONUTIL_H
#define JSONUTIL_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include "Event.h"
#include "User.h"

class JsonUtil {
	// Properties

	public:
		static Event parseEvent(DynamicJsonDocument &json);
		static User parseUser(DynamicJsonDocument &json);
		static Location parseLocation(DynamicJsonDocument &json);
		static Location parseLocation(const JsonObject &json);
	private:
		// Disallow creating an instance of this object
		JsonUtil() {};
};


#endif