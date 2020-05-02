#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.h"
using namespace std;

// default constructor
ShoppingCart::ShoppingCart() {
	customerName = "none";
	dateCreated = "January 1, 2016";
}

// parameterized constructor
ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	dateCreated = date;
}

void ShoppingCart::SetName(string name) {
	customerName = name;
}
string ShoppingCart::GetName() const {
	return customerName;
}
void ShoppingCart::SetDate(string date) {
	dateCreated = date;
}
string ShoppingCart::GetDate() const {
	return dateCreated;
}
void ShoppingCart::AddItem(ItemToPurchase item) {
	if (ItemExists(item.GetName())) {
		cout << "Item is already in cart. Nothing added." << endl;
	}
	else {
		cartItems.push_back(item);
	}
}

void ShoppingCart::RemoveItem(string name) {
	if (!ItemExists(name)) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
	else { // find location of item in cart, then remove it
		int itemLocation = -1;

		for (unsigned int i = 0; i < cartItems.size(); ++i) {
			if (name == cartItems.at(i).GetName()) {
				itemLocation = i;
			}
		}
		cartItems.erase(cartItems.begin() + itemLocation);
	}
}

void ShoppingCart::ChangeQuantity(ItemToPurchase item, int newQuantity) {
	if (!ItemExists(item.GetName())) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
	else { // find location of item in cart, then change its quantity
		int itemLocation = -1;

		for (unsigned int i = 0; i < cartItems.size(); ++i) {
			if (item.GetName() == cartItems.at(i).GetName()) {
				itemLocation = i;
			}
		}
		cartItems.at(itemLocation).SetQuantity(newQuantity);
	}
}

int ShoppingCart::TotalQuantity() {
	int totQuantity = 0;

	for (unsigned int i = 0; i < cartItems.size(); ++i) {
		totQuantity = cartItems.at(i).GetQuantity() + totQuantity;
	}
	return totQuantity;
}

double ShoppingCart::TotalCost() {
	double totCost = 0.0;

	for (unsigned int i = 0; i < cartItems.size(); ++i) {
		totCost = (cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice()) + totCost;
	}
	return totCost;
}

void ShoppingCart::PrintCartTotals() {
	if (cartItems.size() != 0) {
		cout << "Number of Items: " << TotalQuantity() << endl << endl;

		for (unsigned int i = 0; i < cartItems.size(); ++i) {
			cartItems.at(i).PrintItemCost();
		}
		cout << endl;
		cout << "Total: $" << TotalCost() << endl;
	}
	else {
		cout << "Shopping cart is empty." << endl;
	}
}

void ShoppingCart::PrintCartDescriptions() {
	if (cartItems.size() != 0) {
		cout << "Item Descriptions" << endl;
		for (unsigned int i = 0; i < cartItems.size(); ++i) {
			cartItems.at(i).PrintItemDescription();
		}
	}
	else {
		cout << "Shopping cart is empty." << endl;
	}
}

bool ShoppingCart::ItemExists(string testString) {
	for (unsigned int i = 0; i < cartItems.size(); ++i) {
		if (testString == cartItems.at(i).GetName()) {
			return true;
		}
	}
	return false;
}