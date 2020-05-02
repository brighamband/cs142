#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

using namespace std;


int main() {

	vector<BakedGood*> orderList;
	vector<BakedGood*> invoiceVector;
	vector<int> quantityCounter;

	string tempBakedGood = "";
	string tempBreadVariety = "";
	string tempCakeFlavor = "";
	string tempFrostingFlavor = "";
	string tempSprinklesColor = "";
	int tempNumLayers = 0;
	int tempQuantity = 0;
	int totalQuantity = 0;
	double totalCost = 0.0;


	Bread* newBread = nullptr;
	CupCake* newCupCake = nullptr;
	LayerCake* newLayerCake = nullptr;



	// Part 1
	cout << "**Bread and Cakes Bakery**" << endl << endl;

	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	do {
		cout << "Sub-order: ";
		cin >> tempBakedGood;

		// If it's Bread
		if (tempBakedGood == "Bread") {
			cin >> tempBreadVariety;
			cin >> tempQuantity;

			for (int i = 0; i < tempQuantity; ++i) {
				newBread = new Bread(tempBreadVariety);
				orderList.push_back(newBread);
			}
		}

		// If it's a Cupcake
		else if (tempBakedGood == "Cupcake") {
			cin >> tempCakeFlavor;
			cin >> tempFrostingFlavor;
			cin >> tempSprinklesColor;
			cin >> tempQuantity;

			for (int i = 0; i < tempQuantity; ++i) {
				newCupCake = new CupCake(tempSprinklesColor, tempCakeFlavor, tempFrostingFlavor);
				orderList.push_back(newCupCake);
			}
		}

		// If it's a Layer-cake
		else if (tempBakedGood == "Layer-cake") {
			cin >> tempCakeFlavor;
			cin >> tempFrostingFlavor;
			cin >> tempNumLayers;
			cin >> tempQuantity;

			for (int i = 0; i < tempQuantity; ++i) {
				newLayerCake = new LayerCake(tempNumLayers, tempCakeFlavor, tempFrostingFlavor);
				orderList.push_back(newLayerCake);
			}
		}
	} while (tempBakedGood != "done");
	cout << endl;

	// part 2
	cout << "Order Confirmations:" << endl;
	for (unsigned int i = 0; i < orderList.size(); ++i) {
		cout << orderList.at(i)->ToString() << endl;
	}
	cout << endl;

	// part 3
	cout << "Invoice:" << endl;
	cout << "Baked Good" << setw(75) << "Quantity" << setw(9) << "Total" << endl;

	// setting up the invoice vector and the quantity counter
	for (unsigned int i = 0; i < orderList.size(); ++i) {
		bool ifInInvoiceVector = false;
		for (unsigned int j = 0; j < invoiceVector.size(); ++j) {
			if (orderList.at(i)->ToString() == invoiceVector.at(j)->ToString()) {
				ifInInvoiceVector = true;
				quantityCounter.at(j)++;
			}
		}
		if (ifInInvoiceVector == false) {
			invoiceVector.push_back(orderList.at(i));
			quantityCounter.push_back(1);
		}
	}

	// print invoice (invoice vector and quantity counter)
	for (unsigned int i = 0; i < invoiceVector.size(); ++i) {
		cout << invoiceVector.at(i)->ToString() << setw(75);
		cout << quantityCounter.at(i) << setw(9);
		cout << fixed << setprecision(2) << invoiceVector.at(i)->DiscountedPrice(quantityCounter.at(i)) << endl;
	}
	
	// print totals (total quantity of baked goods and total cost)
		// total quantity
	for (unsigned int i = 0; i < quantityCounter.size(); ++i) {
		totalQuantity = totalQuantity + quantityCounter.at(i);
	}
		// total cost
	for (unsigned int i = 0; i < invoiceVector.size(); ++i) {
		totalCost = totalCost + invoiceVector.at(i)->DiscountedPrice(quantityCounter.at(i));
	}
	cout << "Totals" << setw(75) << totalQuantity << setw(9) << totalCost << endl;

	cout << "Good Bye" << endl;

	// delete all pointers
	//for (unsigned int i = 0; i < orderList.size(); ++i) {
		//delete orderList.at(i);
	//}

	return 0;
}