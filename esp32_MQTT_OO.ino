/*
 * Basic API implementation.
 * Author: Ruben Rentero Trejo
 * 
 * This sketch implements the skeleton of your API designed using OpenAPI.
 * Designed for M5-Stick-C.
 */
#include <WiFi.h>
#include <PubSubClient.h>
// WARNING: MQTT_MAX_PACKET_SIZE needs to be defined in PubSubClient.h library. MQTT Max message size is 128B by default.
#include <M5StickC.h>
#include <ArduinoJson.h>

#include "./src/JsonUtil.h"

#include "./src/Location.h"
#include "./src/Event.h"

const char* ssid = "Gloin";
const char* password = "Gloin2014";
const char* mqttServer = "192.168.0.103";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

// TODO Crear un parser que pase de DynamicJson a la creación del objeto en cuestion.
 
WiFiClient espClient;
PubSubClient client(espClient);
  
void setup() {
  Serial.begin(115200);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }

  // Subscribe to topic
  client.subscribe("mytopic/test");

  // Initialize the M5StickObject (for LCD notifications)
  M5.begin();
}

// ---- Function invoked every time a new message arrives to the topic. 
void callback(char* topic, byte* payload, unsigned int length) {
  // PubSub Tasks
  Serial.print("MQTT. Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("MQTT. Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  //Deserialize Json. Json stored in "doc" variable.
  Serial.println("Deserializating JSON");
  const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(3) + 2*JSON_OBJECT_SIZE(4) + 200;
  //TODO Volver a usar "lenght" en lugar de capacity
  DynamicJsonDocument doc(capacity);
  DeserializationError err = deserializeJson(doc, payload, length);
  if (err) {
    Serial.print(F("deserializeJson() failed with code "));
    Serial.println(err.c_str());
  }
  
  Serial.print(F("Resource Type: "));
  const char* resource = doc["resource"];
  Serial.println(resource);
  Serial.print(F("Method: "));
  const char* method_ = doc["method"];
  Serial.println(method_);
  Serial.print(F("Sender ID: "));
  int sender = doc["sender"];
  Serial.println(sender);

    Serial.println(F("----Testeo antes de llamada al parser-----"));
  int eventId = doc["params"]["event"]["id"];
  Serial.println(eventId);
  const char* title = doc["params"]["event"]["title"];
  Serial.println(title);
  const char* description = doc["params"]["event"]["description"];
  Serial.println(description);
  Serial.println(F("Event -> Location: "));
  double latitude = doc["params"]["event"]["location"]["latitude"];
  Serial.println(latitude,6);
  double longitude = doc["params"]["event"]["location"]["longitude"];
  Serial.println(longitude,6);
  int radius = doc["params"]["event"]["location"]["radius"];
  Serial.println(radius);

  //Resource selector
  if (strcmp(resource,"Event")==0) {
    notify("New notification: Event");
    // Method selector: GET, POST, PUT, DELETE. Note that "method" (JSON) === operationId (OpenAPI)
    if (strcmp(method_,"getEvent")==0) { 
      getEvent(doc, sender);
    }
    else if (strcmp(method_,"postEvent")==0){
      Event event = JsonUtil::parseEvent(doc);
          Serial.println("----Despues del parser y antes del post");
          Serial.println(event.getId());
          Serial.println(event.getTitle());
          Serial.println(event.getDescription());
          Location loc = event.getLocation();
          Serial.println("Retrieved Location from event:");
          Serial.println(loc.getLatitude(),6);
          Serial.println(loc.getLongitude(),6);
          Serial.println(loc.getRadius());
      postEvent(event, sender);
    }
    else if (strcmp(method_,"putEvent")==0){
      putEvent(doc, sender);
    }
    else if (strcmp(method_,"deleteEvent")==0){
      deleteEvent(doc, sender);
    }
    else { // Default
      Serial.println("Resource method not supported.");
    }
  }
  else if (strcmp(resource,"User")==0) {
    notify("New notification: User");
    if (strcmp(method_,"getUser")==0) { 
      // TODO Aquí habria que llamar al parser para obtener los parametros y poder pasarlos.
      double latitude = doc["params"]["latitude"];
      double longitude = doc["params"]["longitude"];
      int radius = doc["params"]["radius"];
      getUser(doc, latitude, longitude, radius, sender);
    }
    else if (strcmp(method_,"postUser")==0){
      postUser(doc, sender);
    }
    else if (strcmp(method_,"putUser")==0){
      putUser(doc, sender);
    }
    else if (strcmp(method_,"deleteUser")==0){
      deleteUser(doc, sender);
    }
    else { // Default
      Serial.println("Resource method not supported.");
    }
  }
  else {  //Default
    Serial.println("API resource not supported.");
  }

  Serial.println("-----------------------");
}

void loop() {
  client.loop();
}


// --------------- API Methods
// ---- Event
void getEvent(DynamicJsonDocument &json, int &sender) {
  // Mocked response
  Serial.println("Method: getEvent");
}
void postEvent(Event &event, int &sender) {
  // Mocked response
  Serial.println("Method: postEvent");
  // TODO Limpiar todo este codigo y sustituir por la funcionalidad del parser
  // POO Test
  Serial.println("----Dentro del postEvent");
//  Location loc2(json["params"]["event"]["location"]["latitude"],
//                json["params"]["event"]["location"]["longitude"],
//                json["params"]["event"]["location"]["radius"]);
//  Serial.println(loc2.getLatitude(),6);
//  Serial.println(loc2.getLongitude(),6);
//  Serial.println(loc2.getRadius(),6);
//  Serial.println("POO Event");
//  Event event1(json["params"]["event"]["id"],
//              json["params"]["event"]["title"],
//              json["params"]["event"]["description"], 
//              loc2);
//  Serial.println(event1.getId());
//  Serial.println(event1.getTitle());
//  Serial.println(event1.getDescription());
//  Location loc = event1.getLocation();
//  Serial.println("Retrieved Location from event:");
//  Serial.println(loc.getLatitude(),6);
//  Serial.println(loc.getLongitude(),6);
//  Serial.println(loc.getRadius(),6);

  
  
}
void putEvent(DynamicJsonDocument &json, int &sender) {
  // Mocked response
  Serial.println("Method: putEvent");
}
void deleteEvent(DynamicJsonDocument &json, int &sender) {
  // Mocked response
  Serial.println("Method: deleteEvent");
}

// ---- User
void getUser(DynamicJsonDocument &json, double latitude, double longitude, int radius, int &sender) {
  // Mocked response
  // TODO Testear los parametros recibidos
  Serial.println("Method: getUser");
  Serial.println("Testing received params:");
  Serial.println(latitude);
  Serial.println(longitude);
  Serial.println(radius);
}
void postUser(DynamicJsonDocument &json, int &sender) {
  // Mocked response
  Serial.println("Method: postUser");
}
void putUser(DynamicJsonDocument &json, int &sender) {
  // Mocked response
  Serial.println("Method: putUser");
}
void deleteUser(DynamicJsonDocument &json, int &sender) {
  // Mocked response
  Serial.println("Method: deleteUser");
}


// ---- Utilities
void notify(char* msg){
  // Show notification in LCD. M5 must be initialized.
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf(msg);
  M5.Lcd.fillCircle(40, 80, 30, RED);
}

//  ---- How to acess a DynamicJSON. Examples.
//  -- JSON received via MQTT:
//  {
//    "resource": "Event",
//    "method": "postEvent",
//    "sender": "1",
//    "params": {
//        "event": {
//            "id": 1,
//            "title": "Football Match!",
//            "description": "Football Match at 11:00 in City Soccer Stadium",
//            "location":{
//                "latitude": 38.514377,
//                "longitude":-6.844325,
//                "radius": 200
//                    }
//                }
//        }
//  }
//
//  -- POO Test
//  Serial.println("POO Location");
//  Location loc2(json["params"]["event"]["location"]["latitude"], json["params"]["event"]["location"]["longitude"], json["params"]["event"]["location"]["radius"]);
//  Serial.println(loc2.getLatitude(),6);
//  Serial.println(loc2.getLongitude(),6);
//  Serial.println(loc2.getRadius(),6);
//  Serial.println("POO Event");
//  Event event1(json["params"]["event"]["id"],
//              json["params"]["event"]["title"],
//              json["params"]["event"]["description"], 
//              loc2);
//  Serial.println(event1.getId());
//  Serial.println(event1.getTitle());
//  Serial.println(event1.getDescription());
//  Location loc = event1.getLocation();
//  Serial.println("Retrieved Location from event:");
//  Serial.println(loc.getLatitude(),6);
//  Serial.println(loc.getLongitude(),6);
//  Serial.println(loc.getRadius(),6);
//
//  -- To try this code, copy and paste it after the serialization phase, inside the "callback" function.
//
//  Serial.print(F("Recource Type: "));
//  const char* resource = doc["resource"];
//  Serial.println(resource);
//  const char* method_ = doc["method"];
//  Serial.println(method_);
//  const char* sender = doc["sender"];
//  Serial.println(sender);
//  Serial.println(F("Params -> Event:"));
//  int eventId = doc["params"]["event"]["id"];
//  Serial.println(eventId);
//  const char* title = doc["params"]["event"]["title"];
//  Serial.println(title);
//  const char* description = doc["params"]["event"]["description"];
//  Serial.println(description);
//  Serial.println(F("Event -> Location: "));
//  double latitude = doc["params"]["event"]["location"]["latitude"];
//  Serial.println(latitude,6);
//  double longitude = doc["params"]["event"]["location"]["longitude"];
//  Serial.println(longitude,6);
//  int radius = doc["params"]["event"]["location"]["radius"];
//  Serial.println(radius);
