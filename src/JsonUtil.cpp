/*
	Author: Rubén Rentero Trejo.

	Json Parser. Takes key-values from a DynamicJsonDocument and creates the object.
	Source file.
*/

#include "JsonUtil.h"

Event JsonUtil::parseEvent(DynamicJsonDocument &json){
	Event event(json["params"]["event"]["id"],
				json["params"]["event"]["title"],
				json["params"]["event"]["description"], 
				parseLocation((JsonObject) json["params"]["event"]["location"]));

	return event;
}

User JsonUtil::parseUser(DynamicJsonDocument &json){
	User user(json["params"]["user"]["id"],
			  json["params"]["user"]["preferences"]);

	return user;
}

// Procesamiento para parametros
Location JsonUtil::parseLocation(DynamicJsonDocument &json){
		Location location(json["params"]["location"]["latitude"],
					  json["params"]["location"]["longitude"],
					  json["params"]["location"]["radius"]);

	return location;
}

// Procesamiento cuando Location es un objeto dependiente de otro
Location JsonUtil::parseLocation(const JsonObject &json){
		Location location(json["latitude"],
					  json["longitude"],
					  json["radius"]);

	return location;
}