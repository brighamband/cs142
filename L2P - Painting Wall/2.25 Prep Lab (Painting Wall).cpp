#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
using namespace std;

int main() {
   double wallHeight = 0.0;
   double wallWidth = 0.0;
   double wallArea = 0.0;
   const double galPaintCoverage = 350;     // every gallon of paint covers 350 sq feet
   double galPaintNeeded = 0.0;
   int galCans;
   
   cout << "Enter wall height (feet): ";
   cin  >> wallHeight;
   cout << endl;
   
   cout << "Enter wall width (feet): ";
   cin >> wallWidth;             // FIXME (1): Prompt user to input wall's width
   cout << endl;
   
   // Calculate and output wall area
   wallArea = wallHeight * wallWidth;                 // FIXME (1): Calculate the wall's area
   cout << "Wall area: " << wallArea << " square feet" << endl;  // FIXME (1): Finish the output statement
   
   // FIXME (2): Calculate and output the amount of paint in gallons needed to paint the wall
   galPaintNeeded = wallArea / galPaintCoverage;
   cout << "Paint needed: " << galPaintNeeded << " gallons" << endl;

   // FIXME (3): Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
   galCans = (wallArea / galPaintCoverage) + 1;
   cout << "Cans needed: " << galCans << " can(s)" << endl;
   
   return 0;
}