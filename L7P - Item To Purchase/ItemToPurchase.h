#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream>
#include <string>
using namespace std;

class ItemToPurchase {
public:
	ItemToPurchase();
	void SetName(string name);
	string GetName() const;
	void SetPrice(double price);
	double GetPrice() const;
	void SetQuantity(int quantity);
	int GetQuantity() const;
private:
	string itemName;
	double itemPrice;
	int itemQuantity;
};

#endif