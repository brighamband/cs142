#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"
#include <string>
using namespace std;

class CupCake : public Cake {
public:
	CupCake();
	CupCake(string inSprinklesColor, string inCakeFlavor, string inFrostingFlavor);
	string ToString();
	double DiscountedPrice(int numItems);
private:
	string sprinklesColor;
};

#endif