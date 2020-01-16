/*
	Author: Rubén Rentero Trejo.

	Location.
	Source file.
*/

#include <stdio.h>
#include "Location.h"

Location::Location(){
	latitude = 0;
	longitude = 0;
	radius = 0;
}

Location::Location(double _latitude, double _longitude, int _radius) {
	latitude=_latitude;
	longitude=_longitude;
	radius=_radius;
}

// Setters & Getters
void Location::setLatitude(double _latitude) {
	latitude = _latitude;
}
void Location::setLongitude(double _longitude) {
	longitude = _longitude;
}
void Location::setRadius(int _radius){
	radius=_radius;
}

double Location::getLatitude() {
	return latitude;
}
double Location::getLongitude() {
	return longitude;
}
int Location::getRadius() {
	return radius;
}