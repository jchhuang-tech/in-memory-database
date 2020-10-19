#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "database.h"
#include "person.h"
#include "app.h" 

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::setw;

void printHeader();

void Database::print() const{
    printHeader();
    
    for(int i=0; i<size; i++){
        cout << setw(5) << i;
        data[i]->print();
    }
    cout << "----------" << endl;
    cout << size << " record(s) in total" << endl;
}

int Database::getSize() const {
    return size;
}

int Database::insert(Person* p) {
    data.push_back(p);
    if(data.size() <= (size_t)size){
        return -1;
    }
    size++;
    return 0;
}

int Database::remove(int index) {
    data.erase(data.begin()+index);
    if(data.size() >= (size_t)size){
        return -1;
    }
    size--;
    return 0;
}

int Database::search(int option, string key) const{
    printHeader();
    int count = 0;
    switch(option){
        case 1:
            for (int i=0; i<size; i++){
                if(std::to_string(data[i]->id) == key){
                    cout << setw(5) << i;
                    data[i]->print();
                    count++;
                }
            }
            break;
        case 2:
            for (int i=0; i<size; i++){
                if(data[i]->fName == key){
                    cout << setw(5) << i;
                    data[i]->print();
                    count++;
                }
            }
            break;
        case 3:
            for (int i=0; i<size; i++){
                if(data[i]->lName == key){
                    cout << setw(5) << i;
                    data[i]->print();
                    count++;
                }
            }
            break;
    }

    cout << "----------" << endl;
    cout << count << " record(s) in total" << endl;
    return 0;
}

Database::~Database(){
    for (int i = 0; i < size; i++){
        Person* b = data[i];
        delete b;
    }
    data.clear();
}

void printHeader(){
    cout << "----------" << endl;
    cout << setw(5) << "#"
    << setw(10) << "Type"
    << setw(20) << "ID" 
    << setw(15) << "First Name" 
    << setw(15) << "Last Name" 
    << setw(10) << "GPA" 
    << setw(15) << "Salary" 
    << endl;
}