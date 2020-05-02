#include <iostream>
using namespace std;

int main() {
   int userInteger;
   
   // prompt user for integer
   cout << "Please enter an integer: ";
   cin >> userInteger;
   cout << endl;
   
   // if integer is even
   if (userInteger % 2 == 0 && userInteger != 0) {
      cout << userInteger << " is even";
   }
   
   // if integer is odd
   if (userInteger % 2 != 0 && userInteger != 0) {
      cout << userInteger << " is odd";
   }
   
   // if integer is 0
   if (userInteger == 0) {
      cout << userInteger << " is indeed even.";
   }
   
   return 0;  
}