#ifndef ORNAMENT_H
#define ORNAMENT_H

#include <iostream>
#include <string>
using namespace std;

class Ornament {
public:
	Ornament();
	void SetOrnamentColor(string inputColor);
	string GetOrnamentColor() const;
private:
	string ornamentColor;
};

#endif