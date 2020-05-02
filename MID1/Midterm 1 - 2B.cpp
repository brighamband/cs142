#include <iostream>
using namespace std;

int main() {
   double userLatitude = 0.0;
   double userLongitude = 0.0; 
   const double NORTH_BORDER = 49.0;
   const double EAST_BORDER = -97.7;
   const double SOUTH_BORDER = 41.0;
   const double WEST_BORDER = -110.5;
   const double MT_WY_BORDER = 45.0;
   const double CENTER_BORDER = -104.1;
   const double ND_SD_BORDER = 45.9;
   const double SD_NE_BORDER = 43.0;
   
   
   // prompt user for inputs
   cout << "Enter your latitude and longitude: " << endl;
   cin >> userLatitude; // get latitude input
   cin.ignore();
   cin >> userLongitude; // get longitude input
   cin.ignore();
   
   // in Montana
   if (userLatitude > MT_WY_BORDER && userLatitude < NORTH_BORDER
   && userLongitude > WEST_BORDER && userLongitude < CENTER_BORDER) {
      cout << "You are in Montana";
   }
   
   // in Wyoming
   if (userLatitude > SOUTH_BORDER && userLatitude < MT_WY_BORDER
   && userLongitude > WEST_BORDER && userLongitude < CENTER_BORDER) {
      cout << "You are in Wyoming";
   }
   
   // in North Dakota
   if (userLatitude > ND_SD_BORDER && userLatitude < NORTH_BORDER
   && userLongitude > CENTER_BORDER && userLongitude < EAST_BORDER) {
      cout << "You are in North Dakota";
   }
   
   // in South Dakota
   if (userLatitude > SD_NE_BORDER && userLatitude < ND_SD_BORDER
   && userLongitude > CENTER_BORDER && userLongitude < EAST_BORDER) {
      cout << "You are in South Dakota";
   }
   
   // in Nebraska
   if (userLatitude > SOUTH_BORDER && userLatitude < SD_NE_BORDER
   && userLongitude > CENTER_BORDER && userLongitude < EAST_BORDER) {
      cout << "You are in Nebraska";
   }
  
   // if unknown state (outside of borders)
   if (userLatitude < SOUTH_BORDER || userLatitude > NORTH_BORDER
   || userLongitude < WEST_BORDER || userLongitude > EAST_BORDER) {
      cout << "You are in an unknown State";
   }
   return 0;  
}