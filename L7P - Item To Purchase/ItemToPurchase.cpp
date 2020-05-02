#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

// default constructor
ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemPrice = 0.0;
	itemQuantity = 0;
}

void ItemToPurchase::SetName(string name) {
	itemName = name;
}
string ItemToPurchase::GetName() const {
	return itemName;
}
void ItemToPurchase::SetPrice(double price) {
	itemPrice = price;
}
double ItemToPurchase::GetPrice() const {
	return itemPrice;
}
void ItemToPurchase::SetQuantity(int quantity) {
	itemQuantity = quantity;
}
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}