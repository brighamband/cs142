#include <iostream>
#include <string>
using namespace std;

int main() {  
   int intKey = 0;
   int numLetters = 0;
   char userAnswer = 'y';
   string encodeString = " ";
   string randString = " ";
   const string RANDOM_CHARS = "nai2f7!98qwrf$$NF*@Bsgh#aef51@3syvbQ0zjbalsjgas5ac245ff&*lasgaoygf334dbaljhc%Dd";
	
	
	// title line
	cout << "--Word Encoder--" << endl;
	
	while (userAnswer == 'y') {
   	// get integer key from user
   	cout << "Enter a key: ";
   	cin >> intKey;
   	cin.ignore();
   	cout << endl;
   	
   	// get string to be encoded from user
      cout << "Enter the text to be encoded: ";
      cin >> encodeString;
      cin.ignore();
      cout << endl;
      
      numLetters = encodeString.size();
      for (int i = 0; i < numLetters; ++i) {
         randString = RANDOM_CHARS.substr(i * (intKey - 1), intKey - 1);
         encodeString.insert(intKey * i, randString);
      }
      
      // output encoded string
      cout << "The encoded word is " << encodeString << endl << endl;
      
      // check if user wants to continue
      cout << "Would you like to encode another word? (y/n) ";
      cin >> userAnswer;
	}
	
	// if answer is no, quit program
   cout << "Thank you for using the encoder!";
	return 0;
}