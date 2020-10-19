#include <iostream>
#include <limits>
#include "database.h"
#include "person.h"
#include "app.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

template <typename T>
T input();

void App::init(){
    // default data in the db
    Student* r1 = new Student(305664530, "Bugs", "Bunny", 3.8);
    db.insert(r1);
    Student* r2 = new Student(371092301, "Luke", "Skywalker", 3.5);
    db.insert(r2);
    Teacher* r3 = new Teacher(69857, "Scrooge", "McDuck", 100000);
    db.insert(r3);
    Teacher* r4 = new Teacher(89695, "Emmett", "Brown", 80000);
    db.insert(r4);
    Student* r5 = new Student(587968089, "Charlie", "Brown", 3.2);
    db.insert(r5);
}

void App::viewAll() const{
    db.print();
}

void App::menu(){
    int option;
    while (1){
        cout << endl << "Welcome to the students and faculty database!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. View all records" << endl;
        cout << "2. Add a record" << endl;
        cout << "3. Remove a record" << endl;
        cout << "4. Search for a record" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter a number: ";

        option = input<int>();
        while (option < 1 || option > 5){
            cout << "Invalid input, enter again: ";
            option = input<int>();
        }

        switch(option){
            case 1: // print
                viewAll();
                break;
            case 2: // add
                addRecord();
                break;
            case 3: //remove
                removeRecord();
                break;
            case 4: //search
                searchRecord();
                break;
            case 5: //exit
                break;
        }

        if (option == 5 || backOption() == 1){
            break;
        }
    }
}

int App::addRecord(){
    cout << "\nChoose the type of record you want to add: " << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    cout << "Please enter a number: ";
    int type;
    type = input<int>();
    while (type != 1 && type != 2){
        cout << "Invalid input, enter again: ";
        type = input<int>();
    }

    int id;
    string fName;
    string lName;
    cout << "id: ";
    id = input<int>();
    cout << "first name: ";
    fName = input<string>();
    cout << "last name: ";
    lName = input<string>();
    int res = 0;
    if(type == 1){
        float gpa;
        cout << "gpa: ";
        gpa = input<float>();
        Student* p = new Student(id, fName, lName, gpa);
        res = db.insert(p);
    } else {
        int salary;
        cout << "salary: ";
        salary = input<int>();
        Teacher* p = new Teacher(id, fName, lName, salary);
        res = db.insert(p);
    }
    if(res == 0){
        cout << "Added successfully" << endl;
        return 0;
    } else {
        cout << "Oops! something went wrong, please try again" << endl;
        return -1;
    }
}

int App::removeRecord(){
    int index;
    cout << "\nInput the index# of the person to be removed (0-" << db.getSize()-1 << "): ";
    index = input<int>();
    if(index >= db.getSize() || index < 0){
        cout << "Invalid input, enter again: ";
        index = input<int>();
    }
    if (db.remove(index) == 0){
        cout << "Removed successfully" << endl;
        return 0;
    } else {
        cout << "Oops! something went wrong, please try again" << endl;
        return -1;
    }
}

int App::searchRecord() const{
    cout << "\nChoose which to search by: " << endl;
    cout << "1. ID" << endl;
    cout << "2. First Name" << endl;
    cout << "3. Last Name" << endl;
    cout << "Please enter a number: ";
    int option;
    option = input<int>();
    while (option < 1 || option > 2){
        cout << "Invalid input, enter again: ";
        option = input<int>();
    }
    string key;
    cout << "Enter the key: ";
    key = input<string>();
    db.search(option, key);
    return 0;
}

int App::backOption() const{
    cout << endl;
    cout << "Go back to the menu?" << endl;
    cout << "1. Menu" << endl;
    cout << "2. Exit" << endl;
    cout << "Please enter a number: ";
    int option;
    option = input<int>();
    while (option != 1 && option != 2){
        cout << "Invalid input, enter again: ";
        option = input<int>();
    }
    if (option == 2){
        return 1;
    } else {
        return 0;
    }
}

template <typename T>
T input(){
    T input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, enter again: ";
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // to make the function only read one word and discard the rest of the input
    return input;
}