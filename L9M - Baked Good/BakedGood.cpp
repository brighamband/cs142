#include "BakedGood.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// default constructor
BakedGood::BakedGood() {
	itemPrice = 0.00;
}

// parameterized constructor
BakedGood::BakedGood(double inPrice) {
	itemPrice = inPrice;
}

string BakedGood::ToString() {
	return to_string(itemPrice);
}