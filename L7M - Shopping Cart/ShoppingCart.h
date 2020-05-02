#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
	ShoppingCart();
	ShoppingCart(string name, string date);
	void SetName(string name);
	string GetName() const;
	void SetDate(string date);
	string GetDate() const;
	void AddItem(ItemToPurchase item);
	void RemoveItem(string name);
	void ChangeQuantity(ItemToPurchase item, int newQuantity);
	int TotalQuantity();
	double TotalCost();
	void PrintCartTotals();
	void PrintCartDescriptions();
	bool ItemExists(string testString);
private:
	string customerName;
	string dateCreated;
	vector<ItemToPurchase> cartItems;
};

#endif