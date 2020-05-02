#include "Vehicle.h"

// NOTE: you do not need to modify this file

Vehicle::Vehicle() : Vehicle("", "", 0, "", "") {
    // Nothing to do here
}

Vehicle::Vehicle(std::string make, std::string model, int year, std::string type, std::string color) {
	this->make = make;
	this->model = model;
	this->year = year;
	this->color = color;
	this->type = type;
}

std::string Vehicle::ToString() const {
	return type + ": " + make + " " + model + " " + std::to_string(year) + " " + color;
}

