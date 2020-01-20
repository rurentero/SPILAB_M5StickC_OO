/*
	Author: Rubén Rentero Trejo.

	Json Parser. Converts and create objects from DynamicJsonDocument to a specific object defined in OpenAPI.
	This class hightly depends on ArduinoJson library from Arduino.
	Header file.
*/

#ifndef JSONUTIL_H
#define JSONUTIL_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include "Event.h"

class JsonUtil {
	// Properties

	public:
		//Location 	parseLocation(DynamicJsonDocument json);
		static Event parseEvent(DynamicJsonDocument &json);
		// TODO añadir user
	private:
		// Disallow creating an instance of this object
		JsonUtil() {};
};


#endif