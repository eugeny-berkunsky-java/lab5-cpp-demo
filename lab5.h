
#ifndef UNTITLED20_LAB5_H
#define UNTITLED20_LAB5_H

#include <string>

using namespace std;

struct Person {
    int id{};
    string name;
    string city;
    int year{};
};

struct Element {
    Person * p;
    Element * next;
};

void print(Element  * list);

void findByYear(int year, Element * list);

void printOne(const Person& person);

void findByCity(const string& city, Element * list);

Element * readFromTextFile(const string& filename);

void addInTail(Person * person, Element **pHead, Element **pTail);

Person *findByName(const string& name, Element *list);

#endif //UNTITLED20_LAB5_H
