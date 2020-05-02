#include <iostream>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"
using namespace std;

int main() {

	ItemToPurchase firstItem;
	ItemToPurchase secondItem;

	string name;
	double price;
	int quantity;

	// item 1
	cout << "Item 1" << endl;

	cout << "Enter the item name: ";
	getline(cin, name);
	firstItem.SetName(name);

	cout << "Enter the item price: ";
	cin >> price;
	cin.ignore();
	firstItem.SetPrice(price);

	cout << "Enter the item quantity: ";
	cin >> quantity;
	cin.ignore();
	firstItem.SetQuantity(quantity);

	// item 2
	cout << "Item 2" << endl;

	cout << "Enter the item name: ";
	getline(cin, name);
	secondItem.SetName(name);

	cout << "Enter the item price: ";
	cin >> price;
	cin.ignore();
	secondItem.SetPrice(price);

	cout << "Enter the item quantity: ";
	cin >> quantity;
	cin.ignore();
	secondItem.SetQuantity(quantity);

	// print total cost
	cout << "TOTAL COST" << endl;
	cout << fixed << setprecision(2) << firstItem.GetName() << " " << firstItem.GetQuantity() << " @ $" << firstItem.GetPrice() << " = $" << (firstItem.GetQuantity() * firstItem.GetPrice()) << endl;
	cout << secondItem.GetName() << " " << secondItem.GetQuantity() << " @ $" << secondItem.GetPrice() << " = $" << (secondItem.GetQuantity() * secondItem.GetPrice()) << endl << endl;
	cout << "Total: $" << ((firstItem.GetQuantity() * firstItem.GetPrice()) + (secondItem.GetQuantity() * secondItem.GetPrice())) << endl;

	return 0;
}