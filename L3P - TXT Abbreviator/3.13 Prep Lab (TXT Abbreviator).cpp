#include <iostream>
#include <string> // Note: This library is needed to use the string type
using namespace std;

int main() {
   string userString;

   // get user input
   cout << "Input an abbreviation: \n";
   cin >> userString;
   
   // LOL abbreviation
   if (userString == "LOL") {
      cout << "laughing out loud\n";
   }
   
   // IDK abbreviation
   else if (userString == "IDK") {
      cout << "I don't know\n";
   }  
   
   // BFF abbreviation
   else if (userString == "BFF") {
      cout << "best friends forever\n";
   }
   
   // IMHO abbreviation
   else if (userString == "IMHO") {
      cout << "in my humble opinion\n";
   }
   
   // TMI abbreviation
   else if (userString == "TMI") {
      cout << "too much information\n";
   }
      
   // output unknown
   else {
      cout << "Unknown\n";
   }

   return 0;
}