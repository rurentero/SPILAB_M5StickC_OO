/*
	Author: Rubén Rentero Trejo.

	Location.
	Header file.
*/

#ifndef LOCATION_H
#define LOCATION_H
#include <Arduino.h>

class Location {
	// Properties
	double latitude;
	double longitude;
	int radius;

	public:	
		// Constructor
		Location();
		Location(double _latitude, double _longitude, int _radius);

		// Setters & Getters
		void 	setLatitude(double _latitude);
		void 	setLongitude(double _longitude);
		void 	setRadius(int _radius);

		double 	getLatitude();
		double 	getLongitude();
		int 	getRadius();
};


#endif