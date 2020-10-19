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

void Student::print() const {
    cout << setw(10) << "Student"
    << setw(20) << id 
    << setw(15) << fName
    << setw(15) << lName
    << setw(10) << gpa 
    << setw(15) << "-" 
    << endl;
}

void Teacher::print() const {
    cout << setw(10) << "Teacher"
    << setw(20) << id 
    << setw(15) << fName
    << setw(15) << lName 
    << setw(10) << "-" 
    << setw(15) << salary 
    << endl;
}