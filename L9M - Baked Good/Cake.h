#ifndef CAKE_H
#define CAKE_H

#include "BakedGood.h"
#include <string>
using namespace std;

class Cake : public BakedGood {
public:
	Cake();
	Cake(string inCakeFlavor, string inFrostingFlavor, double inPrice);
	virtual string ToString() = 0;
	virtual double DiscountedPrice(int numItems) = 0;
protected:
	string cakeFlavor;
	string frostingFlavor;
};

#endif