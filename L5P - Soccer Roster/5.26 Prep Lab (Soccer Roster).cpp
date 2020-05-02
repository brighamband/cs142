#include <iostream>
#include <vector>
using namespace std;

int main() {
	const int NUM_PLAYERS = 5;
	unsigned i = 0;
	int userInput = 0;
	vector<int> playerJerseyNum(NUM_PLAYERS);
	vector<int> playerRating(NUM_PLAYERS);
	char menuChoice = ' ';

	for (i = 0; i < NUM_PLAYERS; ++i) {
		// get user inputs for player jersey numbers and ratings
		cout << "Enter player " << i + 1 << "'s jersey number: ";
		cin >> playerJerseyNum.at(i);
		cout << "Enter player " << i + 1 << "'s rating: ";
		cin >> playerRating.at(i);
	}
	cout << endl;

	// print roster
	cout << "ROSTER" << endl;
	for (i = 0; i < NUM_PLAYERS; ++i) {
		cout << "Player " << i + 1 << " -- Jersey number: " << playerJerseyNum.at(i)
		<< ", Rating: " << playerRating.at(i) << endl;
	}
	cout << endl;

	while (menuChoice != 'q') {
		// MENU
		cout << "MENU" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option: " << endl;
		cin >> menuChoice;

      // a- Add player
		if (menuChoice == 'a') {
			playerJerseyNum.resize(playerJerseyNum.size() + 1);
			playerRating.resize(playerRating.size() + 1);
			cout << "Enter another player's jersey number: ";
			cin >> playerJerseyNum.at(playerJerseyNum.size() - 1);
			cout << endl;
			cout << "Enter another player's rating: ";
			cin >> playerRating.at(playerRating.size() - 1);
			cout << endl;
		}

      // d - Remove player
		if (menuChoice == 'd') {
			cout << "Enter a jersey number: " ;
			cin >> userInput;
			for (i = 0; i < playerJerseyNum.size(); ++i) {
				if (userInput == playerJerseyNum.at(i)) {
					playerJerseyNum.erase(playerJerseyNum.begin() + i);
					playerRating.erase(playerRating.begin() + i);
				}
			}
			cout << endl;
		}
		
		// u - Update player rating
		if (menuChoice == 'u') {
			cout << "Enter a jersey number: ";
			cin >> userInput;
			for (i = 0; i < playerJerseyNum.size(); ++i) {
				if (userInput == playerJerseyNum.at(i)) {
					cout << "Enter a new rating for player: ";
					cin >> userInput;	
					playerRating.at(i) = userInput;
				}
			}
			cout << endl;
		}

		// r - Output players above a rating
		if (menuChoice == 'r') {
			cout << "Enter a rating: ";
			cin >> userInput;
			cout << "ABOVE " << userInput << endl;
			for (i = 0; i < playerJerseyNum.size(); ++i) {
				if (playerRating.at(i) > userInput) {
					cout << "Player " << i + 1 << " -- Jersey number: " << playerJerseyNum.at(i)
					<< ", Rating: " << playerRating.at(i) << endl; 
				}
			}
			cout << endl;
		}

		// o - Output roster
		if (menuChoice == 'o') {
			cout << "ROSTER" << endl;
			for (i = 0; i < playerJerseyNum.size(); ++i) {
				cout << "Player " << i + 1 << " -- Jersey number: " << playerJerseyNum.at(i)
				<< ", Rating: " << playerRating.at(i) << endl;
			} 
			cout << endl; 
		}
	}

	// q - Quit

	return 0;
}