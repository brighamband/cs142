#include "Company.h"
#include <iostream>

// NOTE: you do not need to modify this file

int GetValidDealershipIndex(Company& company, std::string dealershipType="") {
	int dealershipIndex = 0;
	do {
		std::cout << "Choose a " << dealershipType << " dealership (0 - "
			<< company.TotalDealerships() - 1 << ")" << std::endl;
		std::cin >> dealershipIndex;
	} while (dealershipIndex < 0 ||
		dealershipIndex > company.TotalDealerships() - 1);

	return dealershipIndex;
}

void HandlePrintOption(Company& company) {
	company.PrintDealerships();
}

int GetSelectionFromDealership(Company& company, int dealershipIndex, std::string operation) {
	std::string location = company.GetLocation(dealershipIndex);
	company.PrintDealership(dealershipIndex);
	int vehicleIndex = 0;
	int totalVehicles = company.TotalVehicles(dealershipIndex);
	if (totalVehicles > 0) {
		std::cout << "Choose a vehicle from " << location << " (0 - "
			<< totalVehicles - 1 << ") to " << operation << std::endl;
		std::cin >> vehicleIndex;
	}
	else {
		std::cout << "No vehicles to " << operation << " from " << location << std::endl;
	}
	return vehicleIndex;
}

void HandleTransferOption(Company& company) {
	int destinationDealershipIndex = GetValidDealershipIndex(company, "destination");
	int sourceDealershipIndex = GetValidDealershipIndex(company, "source");
	int vehicleIndex = GetSelectionFromDealership(company, sourceDealershipIndex, "transfer");
	company.TransferVehicle(sourceDealershipIndex, destinationDealershipIndex, vehicleIndex);
}

void HandleSellOption(Company& company) {
	int sourceDealershipIndex = GetValidDealershipIndex(company);
	int vehicleIndex = GetSelectionFromDealership(company, sourceDealershipIndex, "sell");
	company.SoldVehicle(sourceDealershipIndex, vehicleIndex);
}

void PrintMenu() {
	std::cout << "Menu Options:" << std::endl;
	std::cout << " - 'p': Print out dealership inventories" << std::endl;
	std::cout << " - 't': Transfer a vehicle from source dealership to destination dealership" << std::endl;
	std::cout << " - 's': Chose a vehicle from a dealership that was sold" << std::endl;
	std::cout << " - 'q': Quit program" << std::endl;
}

int main() {

	Company company("Larry H. Miller Toyota");
	std::vector<std::string> fileNames { "TestFile1.txt", "TestFile2.txt", "TestFile3.txt" };
	company.CreateDealerships(fileNames);
	
	char option;
	do {
		PrintMenu();
		std::cin >> option;
		switch (option) {
		case 'p':
			HandlePrintOption(company);
			break;
		case 't':
			HandleTransferOption(company);
			break;
		case 's':
			HandleSellOption(company);
			break;
		case 'q':
			break;
		default:
			std::cout << "Not a valid option!" << std::endl;
			break;
		}
	} while (option != 'q');

	return 0;
}