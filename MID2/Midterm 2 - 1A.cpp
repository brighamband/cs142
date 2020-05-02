#include <iostream>
using namespace std;

const int NUM_INTEGERS = 10;

int main() {
	int intList[NUM_INTEGERS];

	// initialize array values
	for (int i = 0; i < NUM_INTEGERS; ++i) {
		cin >> intList[i];
	}
	cout << endl;

	// change integers to 1s and 0s
	for (int i = 0; i < NUM_INTEGERS; ++i) {
		if (0 == intList[i] % 2) {
			intList[i] = 1;
		}
		else {
			intList[i] = 0;
		}
	}

	// print array in reverse order
	for (int i = NUM_INTEGERS - 1; i >= 0; --i) {
		cout << intList[i] << endl;
	}
	cout << endl;

	return 0;
}