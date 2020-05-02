#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double newGPA);
	string ToString() const;
private:
	string name;
	double GPA;
};

Student::Student(string initialName, double initialGPA) {
	name = initialName;
	GPA = initialGPA;
}

void Student::SetName(string inputName) {
	name = inputName;
}

void Student::SetGPA(double newGPA) {
	GPA = newGPA;
}

string Student::ToString() const { 
   string toString = "";
   toString = name;
   toString.append(" has a GPA of ");
   toString.append(to_string(GPA));
   return toString;
}

int main() {
	vector<Student*> students;
	string userInput = "";
	string inputName = "";
	double inputGPA = 0.0;
	int index = 0;

   do {      
   	cout << "Enter Option: " << endl;
   	cin >> userInput;
   	cin.ignore();
   	
   	if (userInput == "add") {
   	   Student* newStudent = new Student;
   	   
   	   cout << "Student name: " << endl;
   	   cin >> inputName;
   	   newStudent->SetName(inputName);
   	   
   	   cout << inputName << "'s GPA: " << endl;
   	   cin >> inputGPA;
   	   newStudent->SetGPA(inputGPA);
   	   cout << endl;
   	   
   	   students.push_back(newStudent);
   	}
   	
   	if (userInput == "drop") {
   	   cout << "Index of student to drop: " << endl;
   	   cin >> index;
   	   students.erase(students.begin() + index);
   	}
   	
   	if (userInput == "print") {
   	  for (unsigned int i = 0; i < students.size(); ++i) {
   	      cout << i << ": " << students.at(i)->ToString() << endl;
   	  }
   	  cout << endl;
   	}
   }
   while (userInput != "quit");
   
   // deleted memory locations allocated with new for every added student
   for (unsigned int i = 0; i < students.size(); ++i) {
      delete students.at(i);
   }
   
	return 0;
}
