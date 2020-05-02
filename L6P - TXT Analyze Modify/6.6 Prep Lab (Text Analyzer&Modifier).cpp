#include <iostream>
#include <string>
using namespace std;

//Returns the number of spaces in usrStr
int GetNumOfSpaces(const string usrStr) {
   unsigned int i = 0;
   int numSpaces = 0;
   
   /* Type your code here. */
   for (i = 0; i < usrStr.size(); ++i) {
      if (isspace(usrStr.at(i))) {
         numSpaces = numSpaces + 1;
      }
   }
   cout << "Number of spaces: " << numSpaces << endl;
   return numSpaces;  
}

void OutputWithoutWhitespace(string usrStr) {
   unsigned int i = 0;
   
   for (i = 0; i < usrStr.size(); ++i) {
      if (isspace(usrStr.at(i))) {
         usrStr.erase(i, 1);
      }
   }   
      cout << "String with no whitespace: " << usrStr << endl;
      return;
   
}

int main() {
   string usrStr = "";

   /* Type your code here. */
   cout << "Enter a sentence or phrase: " << endl;
   getline(cin, usrStr);
   cout << "You entered: " << usrStr << endl << endl;
   
   GetNumOfSpaces(usrStr);
      
   OutputWithoutWhitespace(usrStr);

   return 0;
}