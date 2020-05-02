#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
public:
   Person(string newName, int newAge);
   string Name();
   void Rename(string newName);
   int Age();
   void SetAge(int newAge);
   bool LessThan(Person compareTo);

private:
   int age;
   string name;
};

#endif