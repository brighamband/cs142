#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"
#include <string>
using namespace std;

class LayerCake : public Cake {
public:
	LayerCake();
	LayerCake(int inNumLayers, string inCakeFlavor, string inFrostingFlavor);
	string ToString();
	double DiscountedPrice(int numItems);
private:
	int numLayers;
};

#endif