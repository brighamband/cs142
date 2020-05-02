/*
Brigham Andersen, Section 3, brighamband@gmail.com
Description:  Makes calculations for a pizza restaurant (financial and logistical)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   const int GUESTS_PER_LARGE = 9;
   const int GUESTS_PER_MEDIUM = 5;
   const int GUESTS_PER_SMALL = 2;
   
   const double DIAMETER_LARGE = 24.0;
   const double DIAMETER_MEDIUM = 18.0;
   const double DIAMETER_SMALL = 14.0;
   const double PI = 3.14159265;
   const double LARGE_PRICE = 15.78;
   const double MEDIUM_PRICE = 13.25;
   const double SMALL_PRICE = 8.39;
   
   int numGuests = 0;
   int numLargePizzas = 0;
   int numMediumPizzas = 0;
   int numSmallPizzas = 0;
   int tipPercent = 0;
   int totalCostRounder = 0;

   double totalArea = 0.0;
   double pizzaAreaPortion = 0.0;
   double totalCost = 0.0;
   
   cout << "Please enter the number of guests: " << endl;
   cin >> numGuests;
   
   numLargePizzas = numGuests / GUESTS_PER_LARGE;
   numMediumPizzas = (numGuests % GUESTS_PER_LARGE) / GUESTS_PER_MEDIUM;
   numSmallPizzas = ((numGuests % GUESTS_PER_LARGE) % GUESTS_PER_MEDIUM) / GUESTS_PER_SMALL;
   cout << numLargePizzas << " large pizzas, ";
   cout <<  numMediumPizzas << " medium pizzas, and ";
   cout << numSmallPizzas << " small pizzas will be needed." << endl << endl;
   
   const double LARGE_AREA = pow((DIAMETER_LARGE /2), 2) * PI;
   const double MEDIUM_AREA = pow((DIAMETER_MEDIUM /2), 2) * PI;
   const double SMALL_AREA = pow((DIAMETER_SMALL /2), 2) * PI;
   totalArea= (numLargePizzas * LARGE_AREA ) + (numMediumPizzas * MEDIUM_AREA) + (numSmallPizzas * SMALL_AREA);
   pizzaAreaPortion = totalArea / numGuests;
   cout << "A total of " << totalArea << " square inches of pizza will be purchased (" << pizzaAreaPortion << " per guest)." << endl;
   cout << endl;

   cout << "Please enter the tip as a percentage (i.e. 10 means 10%): " << endl;
   cin >> tipPercent;
   
   totalCost = ((numLargePizzas * LARGE_PRICE) + (numMediumPizzas * MEDIUM_PRICE) + (numSmallPizzas * SMALL_PRICE));
   totalCost = totalCost + (totalCost * tipPercent / 100.0);
   totalCostRounder = round(totalCost);
   cout << "The total cost of the event will be: $" << totalCostRounder << endl;
   
   return 0;  
}