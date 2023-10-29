/*
Brigham Andersen, Section 3, brighambandersen@gmail.com
Description:  Takes strings from user and edits them according to user input
*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
   string userString = " ";
   string insertText = " ";
   string findOrCopy = " ";
   string subString = " ";
   string findDeleteReplace = " ";
   string replacementString = " ";
   
   int textPosition = 0;
   int textPosition2 = 0;
   int copyLength = 0;
   char userAnswer1;
   char userAnswer2;
   
   // pt1 - get user input
   cout << "Welcome to the Simple Editor. Enter a string to be edited: \n";
   getline(cin, userString);
   cout << userString << endl;
   
   // pt2 - make string > sentence
   cout << "Do you want to make this string a sentence (y/n)?\n";
   cin >> userAnswer1;
   cin.ignore();
   
   if (userAnswer1 == 'y') {
      // capitalize first letter
      userString.at(0) = toupper(userString.at(0));
      
      
      // add period
      userString.append(".");
         
      // print output
      cout << userString << endl << endl;
   }
   
   // pt3 - insert more text
   cout << "Do you want to insert more text into your current text (y/n)?\n";
   cin >> userAnswer2;
   cin.ignore();
   
   
   if (userAnswer2 == 'y') {
      // get input for inserted text
      cout << "Enter text to be inserted: \n";
      getline(cin, insertText);

      // get input for position of inserted text
      cout << "Enter position where text is to be inserted: \n";
      cin >> textPosition;
      cin.ignore();
   
      // if text position is long than the size of the string
      if (textPosition > userString.size() || textPosition < 0) {
         cout << "No change made. Position must be non-negative and not exceed " << userString.size() << ", the length of the current text.\n";
      }
      else {
         // insert text into string
         userString.insert(textPosition, insertText);
         
         // print updated string
         cout << userString << endl;
      }
   }   
   
   // pt4 - find/replace or copy/paste
   
      // prompt user
   cout << "If you would like to find/replace or copy/paste, enter find or copy: \n";
   cin >> findOrCopy;
   cin.ignore();
   
   // if find
   if (findOrCopy == "find") {
      // get substring input to find
      cout << "Enter substring to find: \n";
      cin >> subString;
      cin.ignore();
       
      // get input whether to find, delete, or replace
      cout << "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?\n";
      cin >> findDeleteReplace;
      cin.ignore();
         
      textPosition = userString.find(subString);
         
         // if find
      if (findDeleteReplace == "find") {
         if (textPosition > 0) {
            cout << subString << " was found at position " << textPosition << ".\n";
         }
         
         else {
            cout << subString << " was not found.\n";
         }
      }
         
        // if delete
      if (findDeleteReplace == "delete") {
         // if found
         if (textPosition != string::npos) {
            userString.erase(textPosition, subString.size());
         }
         // if not found
         else {
            cout << subString << " was not found. No change made.\n";
         }   
      }   
         
      // if replace
      if (findDeleteReplace == "replace") {
         // if found
         if (textPosition != string::npos) {
            // get replacement string
            cout << "Enter replacement string: ";
            getline (cin, replacementString);
               
            // replace string
            userString.replace(textPosition, subString.size(), replacementString);
         }
         // if not found
         else {
            cout << subString << " was not found. No change made.\n";
         }
      } 
   }
   // if copy
   else if (findOrCopy == "copy") {
      // get position and length of copy, position to paste
      cout << "Enter position and length of text to be copied, and position for paste: \n";
      cin >> textPosition >> copyLength >> textPosition2;
      cin.ignore();
      
      // valid
      if (((textPosition + copyLength) < userString.size()) && (textPosition2 < userString.size())
      && ((textPosition >= 0) && (copyLength >= 0) && (textPosition2 >= 0))){
         string copyString = userString.substr(textPosition, copyLength);
         userString.insert(textPosition, copyString);
      }
      
      // invalid
      else {  
         cout << "Values entered do not support copy/paste.\n";
      }
   }
      
   cout << "Final text is\n";
   cout << userString << endl;
   
   return 0;
}