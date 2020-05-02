#include "Company.h"
#include <iostream>


Company::Company() : Company("") {
   // Nothing to do here
}

Company::Company(std::string brandName) {
	this->brandName = brandName;
}

int Company::TotalDealerships() {
	return dealerships.size();
}

int Company::TotalVehicles(int dealershipIndex) {
	int total = 0;
	if (IsValidIndex(dealershipIndex)) {
      // BEGIN - add code here
		total = dealerships.at(dealershipIndex)->TotalVehicles();
		// END
	}
	return total;
}

std::string Company::GetLocation(int dealershipIndex) {
   std::string location = "";
	if (IsValidIndex(dealershipIndex)) {
      // BEGIN - add code here
		location = dealerships.at(dealershipIndex)->GetLocation();
		// END
	}
	return location;
}

void Company::TransferVehicle(int sourceIndex, int destinationIndex, int vehicleIndex) {
	if (IsValidIndex(sourceIndex) &&
		IsValidIndex(destinationIndex)) {
      // BEGIN - add code here
		dealerships.at(sourceIndex)->TransferVehicle(dealerships.at(destinationIndex), vehicleIndex);
		// END
	}
}

void Company::SoldVehicle(int dealershipIndex, int vehicleIndex) {
	if (IsValidIndex(dealershipIndex)) {
      // BEGIN - add code here
		dealerships.at(dealershipIndex)->SoldVehicle(vehicleIndex);
		// END
	}
}

void Company::PrintDealerships() {
	std::cout << std::endl << brandName << " (" << dealerships.size() << " dealerships)" << std::endl;
	for (unsigned int i = 0; i < dealerships.size(); i++) {
		std::cout << i << ") ";
      // BEGIN - add code here
		dealerships.at(i)->PrintInventory();
      // END
	}
}

void Company::PrintDealership(int dealershipIndex) {
	if (IsValidIndex(dealershipIndex)) {
      // BEGIN - add code here
		dealerships.at(dealershipIndex)->PrintInventory();
		// END
	}
}

void Company::CreateDealerships(std::vector<std::string>& fileNames) {
	for (unsigned int i = 0; i < fileNames.size(); i++) {
		dealerships.push_back(ParseDealershipFile(fileNames.at(i)));
	}
}

// Private methods below

Dealership* Company::ParseDealershipFile(std::string fileName) {
	Dealership* dealership = nullptr;
	std::ifstream stream(fileName);

	std::string location;
	stream >> location;
	dealership = new Dealership(location);

	while (stream.good()) {
		ParseVehicles(stream, dealership);
	}

	return dealership;
}

void Company::ParseVehicles(std::ifstream& stream, Dealership* dealership) {
	std::string make, model, type, color;
	int year;

	stream >> make;
	stream >> model;
	stream >> year;
	stream >> type;
	stream >> color;

	dealership->AddVehicle(new Vehicle(make, model, year, type, color));
}

bool Company::IsValidIndex(int index) {
	return (index >= 0 && index < static_cast<int>(dealerships.size()));
}