#include "CupCake.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// default constructor
CupCake::CupCake() {
	sprinklesColor = "white";
}

// parameterized constructor
CupCake::CupCake(string inSprinklesColor, string inCakeFlavor, string inFrostingFlavor) : Cake(inCakeFlavor, inFrostingFlavor, 1.95) { // 1.95 - base price for cupcake
	sprinklesColor = inSprinklesColor;
	if (inFrostingFlavor == "cream-cheese") {
		itemPrice = itemPrice + 0.20; // 20 cents for cream cheese
	}
}

// Functions
string CupCake::ToString() {
	return cakeFlavor + " cupcake with " + frostingFlavor + " frosting and " + sprinklesColor + " sprinkles ($" + BakedGood::ToString() + ")";
}

double CupCake::DiscountedPrice(int numItems) {
	double discountedPrice = itemPrice * numItems;

	if (numItems >= 4) { // if 4/+ of same cupcake
		discountedPrice = discountedPrice - (numItems * 0.40);
	}
	else if (numItems >= 2) { // if 2/+ of same cupcake
		discountedPrice = discountedPrice - (numItems * 0.30);
	}

	return discountedPrice;
}