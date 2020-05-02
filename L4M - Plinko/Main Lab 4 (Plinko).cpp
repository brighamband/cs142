/*
Brigham Andersen (brighamband@gmail.com) &
Spencer Andersen (spencerandersen1@gmail.com)
CS 142 Section 3
Description:  Lab #4 Plinko
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
	int userSelection = 0;
	int slotNumber = 0;
	int numChips = 0;

  	int i = 0;
  	int j = 0;

  	const int leftBoardEdge = 0;
  	const int rightBoardEdge = 8;
  	const int numPegRows = 12;

	double chipLocation = 0.0;
	double randomTest = 0.0;
	double totalWinnings = 0.0;
	double avgWinnings = 0.0;

	const double NO_WINNINGS = 0;
	const double SMALL_WINNINGS = 100.00;
	const double MEDIUM_WINNINGS = 500.00;
	const double LARGE_WINNINGS = 1000.00;
	const double GRAND_WINNINGS = 10000.00;

	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);


	// welcome prompt 
	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userSelection;
	cout << endl;

	while (userSelection != 4) {
		// option 1
		while (userSelection == 1) {
			// prompt user for slot number
			cout << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotNumber;
			cout << endl;

			// test for outliers
			if (slotNumber < leftBoardEdge || slotNumber > rightBoardEdge) {
				cout << "Invalid slot." << endl << endl;
				break;
			}

			// valid input, drop chip
			if (slotNumber >= leftBoardEdge || slotNumber <= rightBoardEdge) {
				cout << "*** Dropping chip into slot " << slotNumber << " ***" << endl;
				cout << "Path: [";

				// first chip location is the slot chosen
				chipLocation = slotNumber;

				// chip falls on random side
				for (i = 0; i < numPegRows; ++i) {
					cout << fixed << setprecision(1) << chipLocation << ", ";
					// if chip hits left side
					if (chipLocation == leftBoardEdge) {
						chipLocation = chipLocation + 0.5;
					}

					// if chip hits right side
					else if (chipLocation == rightBoardEdge) {
						chipLocation = chipLocation - 0.5;
					}

					// randomize which way chip falls
					else if (chipLocation > leftBoardEdge && chipLocation < rightBoardEdge) {

						randomTest = (rand() % 2);
						if (randomTest == 0) {
							chipLocation = chipLocation - 0.5;
						}
						else if (randomTest == 1) {
							chipLocation = chipLocation + 0.5;
						}
					}
				}
				// final chip location, close bracket
				cout << chipLocation << "]" << endl;

				// output winnings
				cout << fixed << setprecision(2) << "Winnings: $";
				if (chipLocation == 3.0 || chipLocation == 5.0) {
					cout << NO_WINNINGS << endl << endl;
				}
				if (chipLocation == 0.0 || chipLocation == 8.0) {
					cout << SMALL_WINNINGS << endl << endl;
				}
				if (chipLocation == 1.0 || chipLocation == 7.0) {
					cout << MEDIUM_WINNINGS << endl << endl;
				}
				if (chipLocation == 2.0 || chipLocation == 6.0) {
					cout << LARGE_WINNINGS << endl << endl;
				}
				if (chipLocation == 4.0) {
					cout << GRAND_WINNINGS << endl << endl;
				}
			}
			break;
		}

		// option 2 - multiple chips
		while (userSelection == 2) {
			cout << "*** Drop multiple chips ***" << endl << endl;

			// ask user number of chips to drop
			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl;

			// if input for numChips is invalid (negative)
			if (numChips <= 0) {
				cout << "Invalid number of chips." << endl << endl;
				break;
			}
			// if input for numChips is valid - prompt which slot
			else {
				cout << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> slotNumber;
				cout << endl;

				// test for outliers
				if (slotNumber < leftBoardEdge || slotNumber > rightBoardEdge) {
					cout << "Invalid slot." << endl << endl;
					break;
				}

				// first chip location is the slot chosen
				chipLocation = slotNumber;

				// chip falls on random side
				for (i = 0; i < numChips; ++i) {
					chipLocation = slotNumber;
					for (j = 0; j < numPegRows; ++j) {

						// if chip hits left side
						if (chipLocation == leftBoardEdge) {
							chipLocation = chipLocation + 0.5;
						}

						// if chip hits right side
						else if (chipLocation == rightBoardEdge) {
							chipLocation = chipLocation - 0.5;
						}

						// randomize which way chip falls
						else if (chipLocation > leftBoardEdge && chipLocation < rightBoardEdge) {

							randomTest = (rand() % 2);
							if (randomTest == 0) {
								chipLocation = chipLocation - 0.5;
							}
							else if (randomTest == 1) {
								chipLocation = chipLocation + 0.5;
							}

						}
					}


					// output total winnings
						// don't need condition if lands in 3 or 5, no winnings

					if (chipLocation == 3.0 || chipLocation == 5.0) {
						totalWinnings = totalWinnings + NO_WINNINGS;
					}
					if (chipLocation == 0.0 || chipLocation == 8.0) {
						totalWinnings = totalWinnings + SMALL_WINNINGS;
					}
					if (chipLocation == 1.0 || chipLocation == 7.0) {
						totalWinnings = totalWinnings + MEDIUM_WINNINGS;
					}
					if (chipLocation == 2.0 || chipLocation == 6.0) {
						totalWinnings = totalWinnings + LARGE_WINNINGS;
					}
					if (chipLocation == 4.0) {
						totalWinnings = totalWinnings + GRAND_WINNINGS;
					}
				}

				// output total winnings
				cout << fixed << setprecision(2) << "Total winnings on " << numChips << " chips: $";
				cout << totalWinnings << endl;

				// output average winnings
				avgWinnings = totalWinnings / numChips;
				cout << fixed << setprecision(2) << "Average winnings per chip: $" << avgWinnings << endl << endl;

				totalWinnings = 0;
				break;
			}
		}

		// option 3 - options menu
		if (userSelection == 3) {
			cout << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl << endl;
		}

		// out of range
		if (userSelection < 1 || userSelection > 4) {
			cout << "Invalid selection.  Enter 3 to see options." << endl << endl;
		}

		// get user selection again
		cout << "Enter your selection now: ";
		cin >> userSelection;
		cout << endl;
	}

	// option 4 - out of range
	if (userSelection == 4) {
		cout << "Goodbye!";
		return 0;
	}

	// option 4 - out of range
	if (userSelection == 4) {
		cout << "Goodbye!";
		return 0;
	}
	return 0;
}