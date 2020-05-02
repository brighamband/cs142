#include <iostream>
// FIXME include the string library
#include <cstring>
using namespace std;

int main() {
   string userString;

   // get user input
   cout << "Enter text: \n";
   getline(cin, userString);
   
   // output user input
   cout << "You entered: " << userString << endl;
   
   // find abbreviations
   if (!(userString.find("BFF") == string::npos)) {
      cout << "BFF: best friend forever\n";
   }
   if (!(userString.find("IDK") == string::npos)) {
      cout << "IDK: I don't know\n";
   }
   if (!(userString.find("JK") == string::npos)) {
      cout << "JK: just kidding\n";
   }
   if (!(userString.find("TMI") == string::npos)) {
      cout << "TMI: too much information\n";
   }
   if (!(userString.find("TTYL") == string::npos)) {
      cout << "TTYL: talk to you later\n";
   }
   
   return 0;
}