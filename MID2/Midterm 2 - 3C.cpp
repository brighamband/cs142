#include <vector>
#include <string>
#include <iostream>
using namespace std;

string VectorToString(vector<int> intVector) {
	string intToString = to_string(intVector.at(0));  // initialize string as first integer
	
	for (unsigned int i = 1; i < intVector.size(); ++i) {
		intToString = intToString + ", " + to_string(intVector.at(i));  // add commas and the other integers
	}

	return intToString;
}

int ComputeNextFibonacciNumber(int firstNum, int secondNum) {
	int nextNum = firstNum + secondNum;

	return nextNum;
}

void CreateFibonacciSequence(vector<int>& fibonacciVector, int sequenceLength) {
	fibonacciVector.push_back(0); // set 0 as first int in vector
	fibonacciVector.push_back(1); // set 1 as second int in vector
	fibonacciVector.resize(sequenceLength); // adjust size of vector - if smaller than 2 it will get rid of preset integers

	// set values of integers in fibonacci sequence past the first two
	for (unsigned int i = 2; i < fibonacciVector.size(); ++i) {
		fibonacciVector.at(i) = ComputeNextFibonacciNumber(fibonacciVector.at(i - 2), fibonacciVector.at(i - 1));
	}
}

int main() {	

	return 0;
}