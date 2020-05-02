#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

#include <string>
using namespace std;

class BakedGood {
public:
	BakedGood();
	BakedGood(double inPrice);
	virtual string ToString() = 0;
	virtual double DiscountedPrice(int numItems) = 0;
protected:
	double itemPrice;
};

#endif