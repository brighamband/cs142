#include <iostream>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

int main() {

	ItemToPurchase item;
	ShoppingCart cart;

	string user;
	string date;
	string userStr;
	string name;
	string description;
	double price;
	int quantity;

	cout << "Enter Customer's Name: ";
	getline(cin, user);
	cart.SetName(user);

	cout << "Enter Today's Date: ";
	getline(cin, date);
	cart.SetDate(date);
	cout << endl;

	while (userStr != "quit") {
		cout << "Enter option: ";
		cin >> userStr;
		cin.ignore();

		// if quit is typed, leave the loop
		if (userStr == "quit") {
			break;
		}

		// for add
		else if (userStr == "add") {
			cout << "Enter the item name: ";
			getline(cin, name);
			item.SetName(name);

			cout << "Enter the item description: ";
			getline(cin, description);
			item.SetDescription(description);

			cout << "Enter the item price: ";
			cin >> price;
			cin.ignore();
			item.SetPrice(price);

			cout << "Enter the item quantity: ";
			cin >> quantity;
			cin.ignore();
			item.SetQuantity(quantity);

			// add item to cartItems
			cart.AddItem(item);
			cout << endl;
		}

		// for remove
		else if (userStr == "remove") {
			cout << "Enter name of the item to remove: ";
			getline(cin, name);

			// remove item from cartItems
			cart.RemoveItem(name);
		}

		// for change
		else if (userStr == "change") {
			cout << "Enter the item name: ";
			getline(cin, name);
			item.SetName(name);

			cout << "Enter the new quantity: ";
			cin >> quantity;
			cin.ignore();
			item.SetQuantity(quantity);

			cart.ChangeQuantity(item, quantity);
		}

		// for descriptions
		else if (userStr == "descriptions") {
			cout << cart.GetName() << "'s Shopping Cart - " << cart.GetDate() << endl;
			cart.PrintCartDescriptions();
			cout << endl;
		}

		// for cart
		else if (userStr == "cart") {
			cout << cart.GetName() << "'s Shopping Cart - " << cart.GetDate() << endl;
			cart.PrintCartTotals();
			cout << endl;
		}

		// print option menu
		else { // invalid selection OR user types "options" 
			cout << "MENU" << endl;
			cout << "add - Add item to cart" << endl;
			cout << "remove - Remove item from cart" << endl;
			cout << "change - Change item quantity" << endl;
			cout << "descriptions - Output items' descriptions" << endl;
			cout << "cart - Output shopping cart" << endl;
			cout << "options - Print the options menu" << endl;
			cout << "quit - Quit" << endl << endl;
		}

	}
	// once quitted, say goodbye
	cout << "Goodbye." << endl;

	return 0;
}