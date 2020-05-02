#include <iostream>
#include <cstring>  // FIXME include string library
using namespace std;

int main() {
   string userLine;
   int itemIndex;

   // get line from user
   cout << "Enter text: \n";
   getline(cin, userLine);
   
   // output user line
   cout << "You entered: " << userLine << endl;
   
   // output expanded user line
   if (userLine.find("BFF") != string::npos) { // Found
      itemIndex = static_cast<int>(userLine.find("BFF"));
      userLine.replace(itemIndex, 4, "best friend forever,"); 
   }
   if (userLine.find("IDK") != string::npos) { // Found
      itemIndex = static_cast<int>(userLine.find("IDK"));
      userLine.replace(itemIndex, 4, "I don't know "); 
   }
   if (userLine.find("JK") != string::npos) { // Found
      itemIndex = static_cast<int>(userLine.find("JK"));
      userLine.replace(itemIndex, 4, "just kidding, "); 
   }
   if (userLine.find("TMI") != string::npos) { // Found
      itemIndex = static_cast<int>(userLine.find("TMI"));
      userLine.replace(itemIndex, 4, "too much information"); 
   }
   if (userLine.find("TTYL") != string::npos) { // Found
      itemIndex = static_cast<int>(userLine.find("TTYL"));
      userLine.replace(itemIndex, 4, "talk to you later"); 
   }
   
   cout << "Expanded: " << userLine << endl;

   return 0;
}