/*
	Author: Rubén Rentero Trejo.

	Json Parser.
	Source file.
*/

#include "JsonUtil.h"

// TODO: Cualquier objeto dentro de otro, es totalmente dependiente del padre, no se puede reutilizar
// debido a la forma de acceder al json. Habria que hacerlos desde 0. 
// TODO sólo se parsean los objetos que están en PARAMS
// Location 	JsonUtil::parseLocation(DynamicJsonDocument json){
// 	// TODO test
// 	Location location(json["params"]["event"]["location"]["latitude"],
// 					json["params"]["event"]["location"]["longitude"],
// 					json["params"]["event"]["location"]["radius"]);
// }

Event JsonUtil::parseEvent(DynamicJsonDocument &json){
	// TODO test
	Location location(json["params"]["event"]["location"]["latitude"],
					  json["params"]["event"]["location"]["longitude"],
					  json["params"]["event"]["location"]["radius"]);

	Event event(json["params"]["event"]["id"],
				json["params"]["event"]["title"],
				json["params"]["event"]["description"], 
				location);
	// event.setId(json["params"]["event"]["id"]);
	// event.setTitle(json["params"]["event"]["title"]);
	// event.setDescription(json["params"]["event"]["description"]);
	// event.setLocation(location);

	Serial.println("----Dentro del parser: Obteniendo datos primero del JSON y luego del objeto creado.");
	// Serial.println(json["params"]["event"]["title"]);
	const char* title = json["params"]["event"]["title"];
	Serial.println(title);
	const char* description = json["params"]["event"]["description"];
	Serial.println(description);
	Serial.println(event.getTitle());
	Serial.println(event.getDescription());
	return event;
}