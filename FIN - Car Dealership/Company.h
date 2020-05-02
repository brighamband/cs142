#pragma once
#include "Dealership.h"
#include <string>
#include <vector>
#include <fstream>

// NOTE: you do not need to modify this file

class Company
{
public:
	Company();
	Company(std::string brandName);

	int TotalDealerships();
	int TotalVehicles(int dealershipIndex);
	std::string GetLocation(int dealershipIndex);
	void TransferVehicle(int sourceIndex, int destinationIndex, int vehicleIndex);
	void SoldVehicle(int dealershipIndex, int vehicleIndex);
	void PrintDealerships();
	void PrintDealership(int dealershipIndex);
	void CreateDealerships(std::vector<std::string>& fileNames);

private:
	Dealership* ParseDealershipFile(std::string fileName);
	void ParseVehicles(std::ifstream& stream, Dealership* dealership);
	bool IsValidIndex(int index);

	std::string brandName;
	std::vector<Dealership*> dealerships;
};

