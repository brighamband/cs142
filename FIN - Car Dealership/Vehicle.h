#pragma once
#include <string>

// NOTE: you do not need to modify this file

class Vehicle
{
public:
	Vehicle();
	Vehicle(std::string make, std::string model, int year, std::string type, std::string color);

	std::string ToString() const;

private:
	std::string make;
	std::string model;
	int year;
	std::string type;
	std::string color;
};

