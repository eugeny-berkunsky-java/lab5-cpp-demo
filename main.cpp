#include <iostream>
#include "lab5.h"

using namespace std;

int menu();

int main() {

    Element * list = nullptr;

    int m;
    while ((m = menu())) {
        switch (m) {
            case 1: {
                print(list);
                break;
            }
            case 2: {
                cout << "Year:";
                int year;
                cin >> year;
                findByYear(year, list);
                break;
            }
            case 3: {
                cout << "City:";
                string city;
                cin >> city;
                findByCity(city, list);
                break;
            }
            case 4: {
                list = readFromTextFile("file.txt");
                cout << "read successful\n";
                break;
            }
            case 5: {
                string name;
                cout << "Input person name:";
                cin >> name;
                Person * p = findByName(name, list);
                if (p) {
                    printOne(*p);
                } else {
                    cout << "not found\n";
                }
                break;
            }
            default: {
                cout << "Error. Try again!\n";
            }
        }
    }
}



int menu() {
    cout << "1. Print all" << endl;
    cout << "2. Find by year" << endl;
    cout << "3. Find by city" << endl;
    cout << "4. Read from file" << endl;
    cout << "5. Find by name" << endl;
    cout << "0. Exit" << endl;
    int n;
    cin >> n;
    return n;
}

