#include <iostream>
#include <string>
#include "Ornament.h"
using namespace std;

int main() {

	Ornament userOrnament;
	string inputColor;

	// get user input for ornament color
	cout << "Enter Color: ";
	cin >> inputColor;

	// set ornament color if it's not the same
	if (inputColor != "same") {
		userOrnament.SetOrnamentColor(inputColor);
	}

	// print color of ornament object
	cout << "The ornament is " << userOrnament.GetOrnamentColor() << endl;

	return 0;
}