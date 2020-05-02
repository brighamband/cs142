#include "LayerCake.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// default constructor
LayerCake::LayerCake() {
	numLayers = 0;
}

// parameterized constructor
LayerCake::LayerCake(int inNumLayers, string inCakeFlavor, string inFrostingFlavor) : Cake(inCakeFlavor, inFrostingFlavor, 9.00) { // 9.00 - base price for layercake
	numLayers = inNumLayers;
	itemPrice = itemPrice + (3.00 * (numLayers - 1.00)); // add $3 per extra layer
	if (inFrostingFlavor == "cream-cheese") {
		itemPrice = itemPrice + (1.00 * numLayers);
	}
}

string LayerCake::ToString() {
	return 	to_string(numLayers) + "-layer " + cakeFlavor + " cake with " + frostingFlavor + " frosting ($" + BakedGood::ToString() + ")";
	;
}

double LayerCake::DiscountedPrice(int numItems) {
	double discountedPrice = itemPrice * numItems;
	if (numItems >= 3) {
		discountedPrice = discountedPrice - (2.00 * numItems); // take off $2 for every same layercake
	}
	return discountedPrice;
}