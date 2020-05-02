#include <cassert>

int MultiplyFirstHalf(int array[], int arraySize) {
	int product = array[0];

	for (int i = 0; i < (arraySize / 2); ++i) {
		product = array[i] * product;
	}

	return product;
}

int MultiplySecondHalf(int array[], int arraySize) {
	int product = array[0];

	for (int i = (arraySize / 2); i < arraySize; ++i) {
		product = array[i] * product;
	}

	return product;
}

int MultiplyFirstHalfInclusive(int array[], int arraySize) {
	int product = array[0];

	for (int i = 0; i < (arraySize / 2) + 1; ++i) { // + 1 includes the middle term
		product = array[i] * product;
	}

	return product;
}

int MultiplySecondHalfInclusive(int array[], int arraySize) {
	int product = array[0];

	for (int i = (arraySize / 2); i < arraySize; ++i) {
		product = array[i] * product;
	}

	return product;
}

int main() {	
	// testing arrays with an even amount of integers
	const int EVEN_SIZE = 8;
	int evenArray[EVEN_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
	assert(MultiplyFirstHalf(evenArray, EVEN_SIZE) == 24);
	assert(MultiplySecondHalf(evenArray, EVEN_SIZE) == 1680);

	// testing arrays with an odd amount of integers
	const int ODD_SIZE = 7;
	int oddArray[ODD_SIZE] = { 1, 2, 3, 4, 5, 6, 7};
	assert(MultiplyFirstHalfInclusive(oddArray, ODD_SIZE) == 24);
	assert(MultiplySecondHalfInclusive(oddArray, ODD_SIZE) == 840);

	return 0;
}