#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
   int volumeRemainder = 0.0;
   double cylinderRadius = 0.0;
   double cylinderHeight = 0.0;
   double rectangleSurfaceArea = 0.0;
   double circlesSurfaceArea = 0.0;
   double totalSurfaceArea = 0.0;
   double cylinderVolume = 0.0;
   const double PI = 3.14;
   
   // get cylinder radius from user
   cout << "Please enter the radius of your cylinder: ";
   cin >> cylinderRadius;
   cout << endl;
   
   // get cylinder height from user
   cout << "Please enter the height of your cylinder: ";
   cin >> cylinderHeight;
   
   // calculate surface area of rectangle
   rectangleSurfaceArea = 2 * PI * cylinderRadius * cylinderHeight;
   cout << "The rectangular surface area of the cylinder is: " << rectangleSurfaceArea << endl;
   
   // calculate surface area of circles on end of cylinder
   circlesSurfaceArea = 2 * PI * pow(cylinderRadius, 2);
   cout << "The surface area of the circles on the end of the cylinder is: " << circlesSurfaceArea << endl;
   
   // calculate total surface area of cylinder
   totalSurfaceArea = rectangleSurfaceArea + circlesSurfaceArea;
   cout << "The total surface area of the cylinder is: " << totalSurfaceArea << endl;
   
   // calculate volume of cylinder
   cylinderVolume = PI * pow(cylinderRadius, 2) * cylinderHeight;
   cout << "The volume of the cylinder is: " << cylinderVolume << endl;
   
   // drop decimal from volume
   cout << fixed << setprecision(0) << "The truncated volume is: " << (cylinderVolume - 0.5) << endl; // cylinderVolume - 0.5 ensures the decimal drops off instead of rounding up
   
   // find remainder of volume divided by 7
   volumeRemainder = static_cast<int>(cylinderVolume) % 7;
   cout << "The remainder of "<< cylinderVolume << " divided by 7 is: " << volumeRemainder << endl;
   
   return 0;
}