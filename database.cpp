#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "database.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::setw;

void Student::print() const {
    cout << setw(20) << id 
    << setw(10) << age 
    << setw(25) << faculty 
    << setw(10) << gpa 
    << setw(15) << "N/A" 
    << endl;
}

void Teacher::print() const {
    cout << setw(20) << id 
    << setw(10) << age 
    << setw(25) << faculty 
    << setw(10) << "N/A" 
    << setw(15) << salary 
    << endl;
}

void Database::print() const{
    cout << "----------" << endl;
    cout << setw(5) << "#"
    << setw(20) << "ID" 
    << setw(10) << "Age" 
    << setw(25) << "Faculty" 
    << setw(10) << "GPA" 
    << setw(15) << "Salary" 
    << endl;
    
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

int Database::search(int key) const{
    cout << "----------" << endl;
    cout 
    << setw(5) << "#"
    << setw(20) << "ID" 
    << setw(10) << "Age" 
    << setw(25) << "Faculty" 
    << setw(10) << "GPA" 
    << setw(15) << "Salary" 
    << endl;

    int count = 0;
    for (int i=0; i<size; i++){
        if(data[i]->id == key){
            cout << setw(5) << i;
            data[i]->print();
            count++;
        }
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
