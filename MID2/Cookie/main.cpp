#include <iostream>
#include <string>
#include "Cookie.h"
using namespace std;

int main() {
	Cookie simpleCookie;
	Cookie sugarCookie("sugar", 4, false);

	simpleCookie.PrintInfo();
	sugarCookie.PrintInfo();

	sugarCookie.SetHomemade(true);
	sugarCookie.PrintInfo();

	return 0;
}