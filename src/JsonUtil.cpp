/*
	Author: Rubén Rentero Trejo.

	Json Parser. Takes key-values from a DynamicJsonDocument and creates the object.
	Source file.
*/

#include "JsonUtil.h"

Event JsonUtil::parseEvent(DynamicJsonDocument &json){
	Location location(json["params"]["event"]["location"]["latitude"],
					  json["params"]["event"]["location"]["longitude"],
					  json["params"]["event"]["location"]["radius"]);

	Event event(json["params"]["event"]["id"],
				json["params"]["event"]["title"],
				json["params"]["event"]["description"], 
				location);

	return event;
}

User JsonUtil::parseUser(DynamicJsonDocument &json){
	User user(json["params"]["user"]["id"],
			  json["params"]["user"]["preferences"]);

	return user;
}