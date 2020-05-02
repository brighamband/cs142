#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"
#include <string>
using namespace std;

class Bread : public BakedGood {
public:
	Bread();
	Bread(string inVariety);
	string ToString();
	double DiscountedPrice(int numItems);
private:
	string breadVariety;
};

#endif