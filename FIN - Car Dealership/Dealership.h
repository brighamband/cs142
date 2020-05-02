#pragma once
#include "Vehicle.h"
#include <string>
#include <vector>

// NOTE: you do not need to modify this file

class Dealership
{
public:
	Dealership();
	Dealership(std::string location);

	int TotalVehicles();
	std::string GetLocation();
	Vehicle* GetVehicle(int index);
	void AddVehicle(Vehicle* vehicle);
    void TransferVehicle(Dealership* other, int vehicleIndex);
	void SoldVehicle(int vehicleIndex);
	void PrintInventory();

private:
	void RemoveVehicle(int index);
	bool IsValidIndex(int index);

	std::string location;
	std::vector<Vehicle*> vehicles;
};

