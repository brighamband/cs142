#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
	ofstream outFS;
	ifstream inFS;
	const int PLATE_OFF = 0;
	const int PLATE_ON_HIGH = 100.0;
	const int MATRIX_SIZE = 10;
	const int COLUMN_WIDTH = 9;
	double oldHotPlate[MATRIX_SIZE][MATRIX_SIZE];
	double newHotPlate[MATRIX_SIZE][MATRIX_SIZE];
	double maxCellChange = 0.0;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;

	// welcome screen
	cout << "Hotplate simulator" << endl << endl;

	// pt1.1 - initialize (old) hot plate
	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < MATRIX_SIZE; ++j) {
			// set plates equal to 0
			oldHotPlate[i][j] = PLATE_OFF;

			// set to full heat plates on top and bottom rows besides corners
			if ((i == 0 || i == (MATRIX_SIZE - 1)) && j != 0 && j != (MATRIX_SIZE - 1)) {
				oldHotPlate[i][j] = PLATE_ON_HIGH;
			}
			newHotPlate[i][j] = oldHotPlate[i][j];
		}
	}

	// pt1.2 -  print initial (old) hot plate
	cout << "Printing initial plate..." << endl;

	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < (MATRIX_SIZE - 1); ++j) {
			cout << setw(9);  // set width of columns to 9
			cout << fixed << setprecision(3); // set to 3 decimals
			cout << oldHotPlate[i][j] << ",";
		}
		cout << setw(9) << oldHotPlate[i][j] << endl;
	}
	cout << endl;

	// pt2.1 - update hot plate after 1st iteration
	for (i = 1; i < (MATRIX_SIZE - 1); ++i) {
		for (j = 1; j < (MATRIX_SIZE - 1); ++j) {
			newHotPlate[i][j] = ((oldHotPlate[i - 1][j] + oldHotPlate[i + 1][j] + oldHotPlate[i][j - 1] + oldHotPlate[i][j + 1]) / 4.0);
		}
	}

	// pt2.2 - print hot plate after 1st iteration
	cout << "Printing plate after one iteration..." << endl;

	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < (MATRIX_SIZE - 1); ++j) {
			cout << setw(9);  // set width of columns to 9
			cout << fixed << setprecision(3); // set to 3 decimals
			cout << newHotPlate[i][j] << ",";
		}
		cout << setw(9) << newHotPlate[i][j] << endl;
	}
	cout << endl;

	// pt3.1 - Repeat Update until Stable (until all cells change is until no cell in the array changes by more than 0.1 degrees)
	do {
		maxCellChange = 0.0;
		for (i = 1; i < (MATRIX_SIZE - 1); ++i) {
			for (j = 1; j < (MATRIX_SIZE - 1); ++j) {
				newHotPlate[i][j] = ((oldHotPlate[i - 1][j] + oldHotPlate[i + 1][j] + oldHotPlate[i][j - 1] + oldHotPlate[i][j + 1]) / 4.0);

				if ((fabs(newHotPlate[i][j] - oldHotPlate[i][j])) > maxCellChange) {
					maxCellChange = (fabs(newHotPlate[i][j] - oldHotPlate[i][j]));
				}

			}
		}
		
		// replace old values with new
		for (i = 1; i < (MATRIX_SIZE - 1); ++i) {
			for (j = 1; j < (MATRIX_SIZE - 1); ++j) {
				oldHotPlate[i][j] = newHotPlate[i][j];
			}
		}
	}
	while (maxCellChange > 0.1);

	// pt3.2 - print final hot plate
	cout << "Printing final plate..." << endl;

	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < (MATRIX_SIZE - 1); ++j) {
			cout << setw(9);  // set width of columns to 9
			cout << fixed << setprecision(3); // set to 3 decimals
			cout << newHotPlate[i][j] << ",";
		}
		cout << setw(9) << newHotPlate[i][j] << endl;
	}
	cout << endl;

	// pt4 - output data to file Hotplate.csv
	outFS.open("Hotplate.csv");

	if (!outFS.is_open()) {
		cout << "Could not open file Hotplate.csv." << endl;
		return 1;
	}

	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl << endl;

	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < (MATRIX_SIZE - 1); ++j) {
			outFS << setw(9);  // set width of columns to 9
			outFS << fixed << setprecision(3); // set to 3 decimals
			outFS << newHotPlate[i][j] << ",";
		}
		outFS << setw(9) << newHotPlate[i][j] << endl;
	}
	outFS << endl;
	outFS.close();

	// pt5 - input plate
	inFS.open("Inputplate.txt");
	if (!inFS.is_open()) {
		cout << "Could not open Inputplate.txt." << endl;
		return 1; // error
	}

	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < (MATRIX_SIZE); ++j) {
			inFS >> newHotPlate[i][j];
		}
	}
	inFS.close();

	for (k = 0; k < 3; ++k) {
		for (i = 1; i < (MATRIX_SIZE - 1); ++i) {
			for (j = 1; j < (MATRIX_SIZE - 1); ++j) {
				oldHotPlate[i][j] = newHotPlate[i][j];
			}
		}

		// update hot plate
		for (i = 1; i < (MATRIX_SIZE - 1); ++i) {
			for (j = 1; j < (MATRIX_SIZE - 1); ++j) {
				newHotPlate[i][j] = ((oldHotPlate[i - 1][j] + oldHotPlate[i + 1][j] + oldHotPlate[i][j - 1] + oldHotPlate[i][j + 1]) / 4.0);
			}
		}
	}

	// print hot plate
	cout << "Printing input plate after 3 updates..." << endl;

	for (i = 0; i < MATRIX_SIZE; ++i) {
		for (j = 0; j < (MATRIX_SIZE - 1); ++j) {
			cout << setw(9);  // set width of columns to 9
			cout << fixed << setprecision(3); // set to 3 decimals
			cout << newHotPlate[i][j] << ",";
		}
		cout << setw(9) << newHotPlate[i][j] << endl;
	}
	cout << endl;
	
	return 0;
}