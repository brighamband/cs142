#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
	Student(string initialName = "No Name") {
		name = initialName;
	}

	// Enter definition for a virtual ToStr member function here.
	virtual string ToStr() {
	   return name + " is an undergraduate student.";
	}

protected:
	string name;
};

class GradStudent : public Student {
public:
	// Enter definition for a parameterized contructor function here that sets both data members.
	GradStudent(string inpName = "No Name", string inpResearchArea = "None"){
	   name = inpName;
	   researchArea = inpResearchArea;
	}

	// Enter definition for a virtual ToStr member function here.
	string ToStr() {
	   return name + " is a graduate student researching the area of " + researchArea + ".";
	}

private:
	string researchArea;
};

int main() {
	string usrOption;
	string inpName;
	string inpResearch;
	vector<Student*> classMembers;

	do {
		cout << "Option: ";
		cin >> usrOption;
	   cout << endl;
		if (usrOption == "print") {
			// Enter code here to print each member pointed to from classMembers using their respective ToStr member functions.			}
			for (unsigned int i = 0; i < classMembers.size(); ++i) {
			   cout << classMembers.at(i)->ToStr() << endl;
			}
		}

		else if (usrOption == "add") {
			cout << "Name: ";
			cin >> inpName;
			cout << endl;
			cout << "If grad student enter a one word research area, else enter \"NO\": ";
			cin >> inpResearch;
			cout << endl;
				// Enter code here to create new objects (using new) for either a Student or a GradStudent
				// and add the pointer to the classMember vector.			}
			if (inpResearch != "NO") {
			   GradStudent* gradStudentPtr = new GradStudent(inpName, inpResearch);
			   classMembers.push_back(gradStudentPtr);
			}
			else {
			   Student* studentPtr = new Student(inpName);
			   classMembers.push_back(studentPtr);
			}
		}
	} while (usrOption != "quit");
	return 0;
}