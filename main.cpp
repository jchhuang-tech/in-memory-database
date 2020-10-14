#include <iostream>
#include "database.h"
#include "menu.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Database db;

int backOption();
int addRecord();
int removeRecord();
int searchRecord();

int main(void){

    int option = 0;
    while (1){
        cout << endl << "Welcome to the students and faculty database!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. View the database" << endl;
        cout << "2. Add a record" << endl;
        cout << "3. Remove a record" << endl;
        cout << "4. Search for a record" << endl;
        cout << "5. Exit" << endl;
        cout << "Please type a number:" << endl;

        cin >> option;
        while (option < 1 || option > 5){
            cout << "Invalid option, input again:" << endl;
            cin >> option;
        }

        if (option == 1){ // print
            db.print();
            if (backOption() == 1){
                break;
            }
        } else if (option == 2){ // add
            addRecord();
            
            if (backOption() == 1){
                break;
            }
        } else if (option == 3){ //remove
            removeRecord();
            if (backOption() == 1){
                break;
            }
        } else if (option == 4){ //search
            searchRecord();
            if (backOption() == 1){
                break;
            }
        } else if (option == 5){
            break;
        }
    }

    return 0;
}

int addRecord(){
    cout << "Choose the type of record you want to add: " << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    int op;
    cin >> op;
    while (op != 1 && op != 2){
        cin.clear();
        cin.ignore();
        cout << "Invalid option, input again:" << endl;
        cin >> op;
    }

    int id;
    int age;
    string faculty;
    cout << "id: ";
    cin >> id;
    cout << "age: ";
    cin >> age;
    cout << "faculty: ";
    cin >> faculty;
    if(op == 1){
        float gpa;
        cout << "gpa: ";
        cin >> gpa;
        Student* p = new Student(id, age, faculty, gpa);
        db.insert(p);
    } else {
        int salary;
        cout << "salary: ";
        cin >> salary;
        Teacher* p = new Teacher(id, age, faculty, salary);
        db.insert(p);
    }

    return 0;
}

int removeRecord(){
    int index;
    cout << "input the index# of the person to be removed (0-" << db.getSize() << "): ";
    cin >> index;
    if (db.remove(index) == 0){
        cout << "removed successfully" << endl;
        return 0;
    } else {
        cout << "oops! something went wrong, please try again" << endl;
        return 1;
    }
}

int searchRecord(){
    // cout << "1. ID" << endl;
    // cout << "2. Age" << endl;
    // cout << "3. faculty" << endl;
    // cout << "Search by: " << endl;
    // int op;
    // cin >> op;
    int key;
    cout << "Search by ID: " << endl;
    cin >> key;
    db.search(key);
    return 0;
}

int backOption(){
    cout << endl;
    cout << "Go back to the menu?" << endl;
    cout << "1. Menu" << endl;
    cout << "2. Exit" << endl;
    int option = 0;
    cin >> option;
    while (option != 1 && option != 2){
            cout << "Invalid option, input again:" << endl;
            cin >> option;
    }
    if (option == 2){
        return 1;
    } else {
        return 0;
    }
}