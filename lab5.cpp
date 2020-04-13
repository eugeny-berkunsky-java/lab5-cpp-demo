
#include <fstream>
#include <iostream>
#include "lab5.h"

Element * readFromTextFile(const string& filename) {
    Element * head = nullptr;
    Element * tail = nullptr;
    ifstream fin(filename);
    int count;
    fin >> count;
    for (int i = 0; i < count; ++i) {
        auto * p = new Person;
        fin >> p->id >> p->name >> p->city >> p->year;
        addInTail(p, &head, &tail);
    }
    return head;
}

void addInTail(Person *person, Element **pHead, Element **pTail) {
    auto * t = new Element;
    t->p = person;
    t->next = nullptr;
    if (*pHead == nullptr) {
        *pHead = t;
    } else {
        (*pTail)->next = t;
    }
    *pTail = t;
}

void findByCity(const string& city, Element * list) {
    Element * t = list;
    while (t) {
        if (t->p->city == city) {
            printOne(*(t->p));
        }
        t = t->next;
    }
    cout << "-----------------------" << endl;
}

void findByYear(int year, Element * list) {
    Element * t = list;
    while (t) {
        if (t->p->year > year) {
            printOne(*(t->p));
        }
        t = t->next;
    }
    cout << "-----------------------" << endl;
}

Person *findByName(const string& name, Element *list) {
    Element * t = list;
    while (t) {
        if (t->p->name==name) {
            return t->p;
        }
        t = t->next;
    }
    return nullptr;
}

void printOne(const Person& p) {
    cout << p.id << " " << p.name << " " << p.city << " " << p.year << endl;
}

void print(Element * list) {
    Element * t = list;
    while (t) {
        printOne(*(t->p));
        t = t->next;
    }
    cout << "------------------------" << endl;
}