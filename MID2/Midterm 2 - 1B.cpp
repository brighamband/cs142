#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int COUNTRIES = 6;
const int MEDALS = 3;

int main() {

	//We are giving you the values for the countries[COUNTRIES] array and the counts[COUNTRIES][MEDALS] two-dimensional array
	string countries[COUNTRIES] = { "Norway", "Germany", "Canada", "Netherlands", "France", "United States" };
	int counts[COUNTRIES][MEDALS] = { { 11, 10, 8 }, { 11, 7, 5 }, { 8, 5, 6 }, { 6, 5, 3 }, { 5, 4, 4 }, { 5, 3, 4 } };

	int totals[COUNTRIES] = {};

	//Print the heading
	cout << setw(15) << "Country";
	cout << setw(8) << "Gold";
	cout << setw(8) << "Silver";
	cout << setw(8) << "Bronze";
	cout << setw(8) << "Total" << endl;

	//Print the information in the "Medal Book"
	for (int i = 0; i < COUNTRIES; ++i) {
		// print country name
		cout << setw(15) << countries[i];

		// print country medal counts
		for (int j = 0; j < MEDALS; ++j) {
			cout << setw(8) << counts[i][j];
		}

		// calculate & print total medal counts
		for (int j = 0; j < MEDALS; ++j) {
			totals[i] += counts[i][j];
		}
		cout << setw(8) << totals[i];

		// move to next line, next country
		cout << endl;
	}
	cout << endl;

	return 0;
}