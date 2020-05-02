#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>
#include <string>
using namespace std;

class Cookie {
public:
	Cookie();
	Cookie(string cookieName, int baseDeliciousness, bool isHomemade);
	void SetHomemade(bool isHomemade);
	void PrintInfo() const;
	string cookieName = "";
	int baseDeliciousness = 0;
	bool isHomemade = false;
};

#endif
