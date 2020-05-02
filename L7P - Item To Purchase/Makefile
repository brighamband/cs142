makefile: main.o ItemToPurchase.o ShoppingCart.o
	g++ -o makefile main.o ItemToPurchase.o ShoppingCart.o
		
main.o: main.cpp ItemToPurchase.h ShoppingCart.h
	g++ -c main.cpp

ItemToPurchase.o: ItemToPurchase.cpp ItemToPurchase.h
	g++ -c ItemToPurchase.cpp

ShoppingCart.o: ShoppingCart.cpp ShoppingCart.h ItemToPurchase.cpp ItemToPurchase.cpp
	g++ -c ShoppingCart.cpp