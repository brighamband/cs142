#include "Dealership.h"
#include <iostream>


Dealership::Dealership() : Dealership("") {
	// Nothing to do here
}

Dealership::Dealership(std::string location) {
	this->location = location;
}

int Dealership::TotalVehicles() {
   // BEGIN - modify code here
	return vehicles.size();
   // END
}

std::string Dealership::GetLocation() {
   // BEGIN - modify code here
	return location;
   // END
}

Vehicle* Dealership::GetVehicle(int index) {
	Vehicle* vehicle = nullptr;
	if (IsValidIndex(index)) {
		// BEGIN - add code here
		vehicle = vehicles.at(index);
		// END
	}
	return vehicle;
}

void Dealership::AddVehicle(Vehicle* vehicle) {
   // BEGIN - add code here
	vehicles.push_back(vehicle);
   // END
}

void Dealership::TransferVehicle(Dealership* other, int vehicleIndex) {
	if (IsValidIndex(vehicleIndex)) {
		std::cout << "[Transfered] " << vehicles.at(vehicleIndex)->ToString() << " from "
			<< location << " to " << other->location << std::endl;
      // BEGIN - add code here
		other->AddVehicle(vehicles.at(vehicleIndex));
		RemoveVehicle(vehicleIndex);
      // END
	}
	else {
		std::cout << "[Not a valid vehicle index]" << std::endl;
	}
}

void Dealership::SoldVehicle(int vehicleIndex) {
	if (IsValidIndex(vehicleIndex)) {
        std::cout << "[Sold] " << vehicles.at(vehicleIndex)->ToString() << std::endl;
      // BEGIN - add code here
		RemoveVehicle(vehicleIndex);
      // END
	}
	else {
		std::cout << "[Not a valid vehicle index]" << std::endl;
	}
}

void Dealership::PrintInventory() {
	std::cout << "Location: " << location << std::endl;
	std::cout << "Total Vehicles: " << vehicles.size() << std::endl;
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		std::cout << i << ") " << vehicles.at(i)->ToString() << std::endl;
	}
	std::cout << std::endl;
}

void Dealership::RemoveVehicle(int index) {
	if (IsValidIndex(index)) {
      // BEGIN - add code here
		vehicles.erase(vehicles.begin() + index);
	  // END
	}
}

bool Dealership::IsValidIndex(int index) {
	return (index >= 0 && index < static_cast<int>(vehicles.size()));
}
