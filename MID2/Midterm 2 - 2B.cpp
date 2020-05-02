#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int numTasks = 0;
	string taskName = "";
	int taskTime = 0;
	int timeLeft = 0;
	vector<string> taskNameList;
	vector<int> taskTimeList;

	// prompt user for number of tasks
	cout << "How many things do you want to add to your list? " << endl;
	cin >> numTasks;
	cin.ignore();

	// add tasks to vector lists
	for (int i = 0; i < numTasks; ++i) {
		cout << "Enter the task: ";
		getline(cin, taskName);
		taskNameList.push_back(taskName); 

		cout << "How many minutes will it take you to \"" << taskName << "\"? ";
		cin >> taskTime;
		cin.ignore();
		taskTimeList.push_back(taskTime);
		cout << endl;
	}
	cout << endl;

	// print tasks to do
	cout << "Things I need to do:" << endl;
	for (int i = 0; i < numTasks; ++i) {
		cout << taskNameList.at(i) << ": " << taskTimeList.at(i) << endl;
	}
	cout << endl;
	
	// prompt user how much time is left
	cout << "How much time do you have left today? ";
	cin >> timeLeft;
	cin.ignore();
	cout << endl;

	// remove tasks that take longer than time left
	for (int i = 0; i < numTasks; ++i) {
		if (taskTimeList.at(i) > timeLeft) {
			taskNameList.erase(taskNameList.begin() + i);
			taskTimeList.erase(taskTimeList.begin() + i);
			numTasks = numTasks - 1;
		}
		
	}

	// print possible tasks (take less than time left)
	cout << "Remaining possible things to do today:" << endl;
	for (int i = 0; i < numTasks; ++i) {
		cout << taskNameList.at(i) << ": " << taskTimeList.at(i) << endl;
	}

	return 0;
}
