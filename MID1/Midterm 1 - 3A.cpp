#include <iostream>
using namespace std;


int main() {
   int userInt = 0;
   int oddSum = 0;
   int evenSum = 0;
   
   // keeps receiving user input while integers are positive
   while (userInt >= 0) {
      cin >> userInt;
      
      // see if odd, add up sum
      if (userInt % 2 != 0 && userInt > 0) {
         oddSum = oddSum + userInt;
      }
      
      // see if even, add up sum
      if (userInt % 2 == 0) {
         evenSum = evenSum + userInt;
      }
   }
   
   // output odd sum
   cout << "The sum of the odd numbers is: " << oddSum << endl;
   
   // output even sum
   cout << "The sum of the even numbers is: " << evenSum << endl;
   
   
   return 0;
}  