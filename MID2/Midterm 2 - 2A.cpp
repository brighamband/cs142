#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string userStr = "";
	vector<string> list;
	
	cout << "Please enter your shopping list. Type \"done\" when finished." << endl;

	// fill vector
	while (userStr != "done") {
		getline(cin, userStr);
		
		if (userStr == "done") { // if user enters "break", don't add it to the vector
			break;
		}

		list.push_back(userStr);
	}
	cout << endl;

	// print vector
	cout << "My shopping list: " << endl;
	for (unsigned int i = 0; i < list.size(); ++i) {
		cout << list.at(i) << endl;
	}

	return 0;
}