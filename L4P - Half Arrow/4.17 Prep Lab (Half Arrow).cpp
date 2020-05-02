#include <iostream>
using namespace std;

int main() {
   int arrowBaseHeight = 0;
   int arrowBaseWidth = 0;
   int arrowHeadWidth = 0;
   int i = 0;
   int j = 0;
   
   cout << "Enter arrow base height: " << endl;
   cin >> arrowBaseHeight;
   
   cout << "Enter arrow base width: " << endl;
   cin >> arrowBaseWidth;
   
   while (arrowHeadWidth <= arrowBaseWidth) {
   cout << "Enter arrow head width: " << endl;
   cin >> arrowHeadWidth;
}
   
   // Draw arrow base (height and width from user)
   for (i = 0; i < arrowBaseHeight; ++i) {
      for (j = 0; j < arrowBaseWidth; ++j) {
      cout << "*";
      }
   cout << endl;
   }
   
   // Draw arrow head (width from user)
   for (i = arrowHeadWidth; i > 0; --i) {
      for (j = 0; j < i; ++j) {
         cout << "*";
      }
      cout << endl;
   }
   
   return 0;
}