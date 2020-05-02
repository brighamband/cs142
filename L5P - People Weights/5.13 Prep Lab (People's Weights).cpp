#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<double> userWeight(5);
   unsigned i = 0;
   const int NUM_VALS = 5;
   double sumVal = 0;
   double avgVal = 0;
   double maxVal;
   
   // get weight inputs from user
   for (i = 0; i < NUM_VALS; ++i) {
      cout << "Enter weight " << i + 1 << ": " << endl;
      cin >> userWeight.at(i);
      
      // get sum of values
      sumVal = sumVal + userWeight.at(i);
      
      // get max of values
      maxVal = userWeight.at(0);
      if (userWeight.at(i) >= maxVal) {
         maxVal = userWeight.at(i);
      }
   }
   cout << endl;
   
   // print vector of user weight inputs
   cout << "You entered: ";
   for (i = 0; i < NUM_VALS; ++i) {
      cout << userWeight.at(i) << " ";
   }
   cout << endl;
   
   // output total (sum)
   cout << "Total weight: " << sumVal << endl;
   
   // calculate and output avg
   avgVal = sumVal / NUM_VALS;
   cout << "Average weight: " << avgVal << endl;
   
   // output max
   cout << "Max weight: " << maxVal << endl;
   

   return 0;
}