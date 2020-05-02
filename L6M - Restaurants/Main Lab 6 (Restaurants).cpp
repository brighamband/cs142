#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void DisplayRestaurants(const vector<string>&);
bool FindRestaurant(const vector<string>&, string&);
void AddRestaurant(vector<string>&);
void RemoveRestaurant(vector<string>&);
void CutRestaurant(vector<string>&);
void ShuffleRestaurant(vector<string>&);
bool PowerOfTwo(int numberToCheck);
void Battle(vector<string>);

int main() {
	string userStr = "";
	vector<string> restaurantList;

	// welcome user, get input
	cout << "Welcome to the restaurant battle!  Enter \"options\" to see options." << endl << endl;

	while (userStr != "quit") {
		cout << "Enter your selection: ";
		cin >> userStr;
		cin.ignore();

		// if quit is typed, leave the loop
		if (userStr == "quit") {
			break;
		}

		// options menu selection
		else if (userStr == "options") {
			cout << "Please select one of the following options: " << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl << endl;
		}

		// for display
		else if (userStr == "display") {
			DisplayRestaurants(restaurantList);
		}

		// for add
		else if (userStr == "add") {
			AddRestaurant(restaurantList);
		}

		// for remove
		else if (userStr == "remove") {
			RemoveRestaurant(restaurantList);
		}

		// for cut
		else if (userStr == "cut") {
			CutRestaurant(restaurantList);
		}

		// for shuffle
		else if (userStr == "shuffle") {
			ShuffleRestaurant(restaurantList);
		}

		// for battle
		else if (userStr == "battle") {
			Battle(restaurantList);
		}
		// invalid selection
		else {
			cout << "Invalid Selection" << endl;
			cout << "Please select one of the following options: " << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl << endl;
		}

	}
	// once quitted, say goodbye
	cout << "Goodbye!" << endl;

	return 0;
}

void DisplayRestaurants(const vector<string>& restaurantList) {
	cout << "Here are the current restaurants: " << endl << endl;
	for (unsigned int i = 0; i < restaurantList.size(); ++i) {
		cout << "\t\"" << restaurantList.at(i) << "\"" << endl;
	}
	cout << endl;
}

bool FindRestaurant(const vector<string>& restaurantList, string& userRestaurant) {
	bool restaurantExists = false;

	for (unsigned int i = 0; i < restaurantList.size(); ++i) {
		if (restaurantList.at(i) == userRestaurant) {
			restaurantExists = true;
		}
	}
	return restaurantExists;
}

void AddRestaurant(vector<string>& restaurantList) {
	string userRestaurant;

	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, userRestaurant);

	// see if restaurant name already exists
	bool restaurantExists = FindRestaurant(restaurantList, userRestaurant);

	// if found, do not add
	if (restaurantExists) {
		cout << "That restaurant is already in the list, you can not add it again." << endl << endl;
	}
	// if not found, add
	else {
		restaurantList.push_back(userRestaurant);
		cout << userRestaurant << " has been added." << endl << endl;
	}
}

void RemoveRestaurant(vector<string>& restaurantList) {
	string userRestaurant;

	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, userRestaurant);

	// see if restaurant name already exists
	bool restaurantExists = FindRestaurant(restaurantList, userRestaurant);

	// if not found, cannot remove
	if (!restaurantExists) {
		cout << "That restaurant is not in the list, you can not remove it." << endl << endl;
	}

	// if found, remove
	else {
		for (unsigned i = 0; i < restaurantList.size(); ++i) {
			if (restaurantList.at(i) == userRestaurant) {
				restaurantList.erase(restaurantList.begin() + i);
			}
		}
		cout << userRestaurant << " has been removed." << endl << endl;
	}
}

void CutRestaurant(vector<string>& restaurantList) {
	int numToCut = 0;
	vector<string> cutList;

	do {
		cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
		cin >> numToCut;
		cin.ignore();

		// test if int
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n'); // 1000 is high number out of range
			numToCut = -1;
		}

		// test if numToCut is within range of number of restaurants
		if (numToCut < 0 || numToCut > restaurantList.size()) {
			cout << "The cut number must be between 0 and " << restaurantList.size() << endl;
		}
	} while (numToCut < 0 || numToCut > restaurantList.size());

	// everything below restaurant cuts is top of cutList
	for (unsigned int i = numToCut; i < restaurantList.size(); ++i) {
		cutList.push_back(restaurantList.at(i));
	}

	// everything cut from top of restaurant is added to bottom
	for (unsigned int i = 0; i < numToCut; ++i) {
		cutList.push_back(restaurantList.at(i));
	}

	// add updates to restaurantList
	restaurantList = cutList;

}

void ShuffleRestaurant(vector<string>& restaurantList) {
	vector<string> shuffleList;

	if (!PowerOfTwo(restaurantList.size())) {
		cout << "The current tournament size (" << restaurantList.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}
	else {
		for (unsigned int i = 0; i < restaurantList.size() / 2; ++i) {
			shuffleList.push_back(restaurantList.at(i + (restaurantList.size() / 2)));
			shuffleList.push_back(restaurantList.at(i));
		}

		// add updates to restaurantList
		restaurantList = shuffleList;
	}
}

bool PowerOfTwo(int numberToCheck) {
	// number of restaurants is positive, and a high power of two divided by that number has a remainder of 0
	if (numberToCheck > 0 && 0 == (1 << 30) % numberToCheck) {
		return 1;
	}
	else {
		return 0;
	}
}

void Battle(vector<string> restaurantList) {
	int winnerChoice = 0;

	// if number of restaurants is not a power of two
	if (!PowerOfTwo(restaurantList.size())) {
		cout << "The current tournament size (" << restaurantList.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
		return;
	}

	// find number of rounds using log 2
	int numRounds = 0;
	numRounds = log2(restaurantList.size());
	// cout << "There are " << restaurantList.size() << " teams, which means there will be " << numRounds << " rounds." << endl;

	for (unsigned int i = 0; i < numRounds; ++i) {
		cout << "Round: " << i + 1 << endl << endl;
		vector<string> battleList;

		for (unsigned int j = 0; j < restaurantList.size(); j = j + 2) {
			winnerChoice = 0;

			// while winnerChoice is valid
			while (winnerChoice != 1 && winnerChoice != 2) {
				cout << "Type \"1\" if you prefer " << restaurantList.at(j);
				cout << " or type \"2\" if you prefer " << restaurantList.at(j + 1) << endl;

				// ask for user's preference of restaurant
				cout << "Choice: ";
				cin >> winnerChoice;
				cin.ignore();

				// test if int
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n'); // 1000 is high number out of range
					winnerChoice = -1;
				}

				if (winnerChoice > 2 || winnerChoice < 1) { // if user enters a number besides the two options (not valid)
					cout << "Invalid choice" << endl;
				}
			}
			// cout << "who won: " << restaurantList.at(winnerChoice + j - 1);
			battleList.push_back(restaurantList.at(winnerChoice + j - 1));
		}

		restaurantList = battleList;
		cout << endl << endl;
		if (i == numRounds - 1) {	
			cout << "The winning restaurant is " << battleList.at(0) << "." << endl;
		}
	}
}



/* 
Test case #1 - Add, display, remove, cut, and battleInput: add “Mickey D’s”, “Chick-fil-A”, “Taco Time”, “Subway”, “Cafe Rio”, ”Wendy’s”, “Starbucks”, “KFC”, “In-N-Out”. display remove “Starbucks” display cut 2 display battle, 5, 2, 1, 2, 1, 2, 2, 2 quitExpected Output: First 9 restaurants were added. Display correctly lists the restaurants throughout. “Starbucks” successfully removed. Display correctly lists the restaurants throughout. Cut the top two restaurants, “Mickey D’s” and “Chick-fil-A”, and put them on the bottom.  Display correctly lists the restaurants throughout.  Start the battle.  Battle doesn’t accept 5, then goes until “Mickey D’s” is the winner.My results: Adding, displaying, and removing restaurants worked great. Cutting 2 restaurants and putting them on bottom worked.  The battle function effectively outputted an invalid input of 5 when the options were between 1 and 2.  The tournament elimination worked until 1 winner was found.

Test case #2 - Add, display, shuffle, and battleInput: add “Little Caesar’s”, “Burger King”, “Taco Bell”, “Carl’s Jr.”. display shuffle display battle, 8, 2, 2, 1 quitExpected Output: First 4 restaurants were added. Display correctly lists the restaurants throughout. shuffle the restaurants. Display correctly lists the restaurants in the new shuffled order.  Start the battle.  Battle doesn’t accept 8, then goes until “Little Caesar’s” is the winner.My results: Adding and displaying restaurants worked great. The shuffle worked correctly, putting the third one first, the first one second, the fourth one third, and the second one fourth. The battle function outputted an invalid input when 8 was inputted as which restaurant was wanted out of only 2 options. The tournament elimination worked until 1 winner (Little Caesar’s) was found.

Test case #3 - Add, display, battle, remove, shuffle, display battle
Input: add “Cupbop”, “Culver’s”, “Costa Vida”, “Arctic Circle”, “Arby’s”. display battle remove “Cupbop” shuffle display battle 2, -4, 1, 1 quit
Expected Output: First 5 restaurants were added. Display correctly lists the restaurants throughout.  Try to battle but fail because 5 isn’t a power of 2. “Culver’s” successfully removed. Shuffle cards.  Display correctly lists the restaurants throughout.  Start battling.  The first through matches will work until an input of -4 is rejected because it isn’t 1 or 2.  The battle will continue until “Culver’s” is the winner”.
My results: Adding, displaying, and removing restaurants worked well as expected.  The battle function correctly tested that the list was a power of 2, then sent back an error statement when the list had 5.  After successfully removing 1 restaurant and shuffling correctly, the battle then worked because the list had 4, a power of 2.  The battle goes well, catches the wrong input of -4, and works until a winner is declared.
*/