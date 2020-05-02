#include "Bread.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// default constructor
Bread::Bread() {
	breadVariety = "none";
}

// parameterized constructor
Bread::Bread(string inVariety) : BakedGood(4.50) {  // 4.50 - base price for bread
	breadVariety = inVariety;
}

// Functions
string Bread::ToString() {
	return breadVariety + " bread ($" + BakedGood::ToString() + ")";
}

double Bread::DiscountedPrice(int numItems) {
	int freeBreads = numItems / 3;

	return (itemPrice * numItems) - (freeBreads * itemPrice);
}

