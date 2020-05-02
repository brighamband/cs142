#ifndef PEOPLE_LIST_H
#define PEOPLE_LIST_H

#include <vector>
#include "Person.h"

using namespace std;

class PeopleList{
public:
   void Add(Person toAdd);
   void PrintList();
   int Size();

private:
   vector<Person> people;

};

#endif
