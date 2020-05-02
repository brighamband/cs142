#include <iostream>
#include <cctype>
using namespace std;


int main() {
   int punctuationFound = 0;
   int yesFound = 0;
   int helloFound = 0;
   string userString = " ";

   // get string input from user
   cout << "Welcome to the Talk like a Pirate Translator. Enter a string to be translated: ";
   getline(cin, userString);
   cout << endl;
   
   // if punctuation is found, erase it
   punctuationFound = userString.find(".");
   if (punctuationFound != string::npos) {
      userString.erase(punctuationFound, 1); // 1 is number of characters of "."
   }
   
   // if yes is found, replace with Aye!
   yesFound = userString.find("yes");
   if (yesFound != string::npos) {
      userString.replace(yesFound, 3, "Aye!"); // 3 is number of characters of "yes"
   }
   
   // if CAPITAL Yes is found, replace with Aye!
   yesFound = userString.find("Yes");
   if (yesFound != string::npos) {
      userString.replace(yesFound, 3, "Aye!"); // 3 is number of characters of "Yes"
   }
   
   // if hello is found, replace with Ahoy matey!
   helloFound = userString.find("hello");
   if (helloFound != string::npos) {
      userString.replace(helloFound, 5, "Ahoy matey!"); // 5 is number of characters of "hello"
   }
   
   // if CAPITAL Hello is found, replace with Ahoy matey!
   helloFound = userString.find("Hello");
   if (helloFound != string::npos) {
      userString.replace(helloFound, 5, "Ahoy matey!"); // 5 is number of characters of "Hello"
   }
   
   // add Arrr! to every sentence
   userString.append(", Arrr!");
   
   // output final text
   cout << "Final text is: " << endl << userString;
   

   return 0;
}