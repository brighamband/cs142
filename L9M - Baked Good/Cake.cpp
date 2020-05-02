#include "Cake.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// default constructor
Cake::Cake() {
	cakeFlavor = "plain";
	frostingFlavor = "plain";
}

// parameterized constructor
Cake::Cake(string inCakeFlavor, string inFrostingFlavor, double inPrice) : BakedGood(inPrice) {
	cakeFlavor = inCakeFlavor;
	frostingFlavor = inFrostingFlavor;
}