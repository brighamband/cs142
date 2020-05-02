#include <iostream>
#include <string>
#include "Ornament.h"
using namespace std;

// default constructor
Ornament::Ornament() {
	ornamentColor = "gold";
}

void Ornament::SetOrnamentColor(string inputColor) {
	ornamentColor = inputColor;
}

string Ornament::GetOrnamentColor() const {
	return ornamentColor;
}