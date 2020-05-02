#include <iostream>
#include <string>
#include "Cookie.h"
using namespace std;

// default constructor
Cookie::Cookie() {
	cookieName = "chocolate chip";
	baseDeliciousness = 6;
	isHomemade = false;
}

// parameterized constructor
Cookie::Cookie(string name, int deliciousness, bool homemade) {
	cookieName = name;
	baseDeliciousness = deliciousness;
	isHomemade = homemade;
}

void Cookie::SetHomemade(bool homemade) {
	isHomemade = homemade;
}

void Cookie::PrintInfo() const {
	// homemade
	if (isHomemade) {
		cout << "A homemade " << cookieName << " cookie that is " << baseDeliciousness + 4 << "/10 delicious" << endl;
	}
	// if not homemade
	else {
		cout << "A " << cookieName << " cookie that is " << baseDeliciousness << "/10 delicious" << endl;
	}
}