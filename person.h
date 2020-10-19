#pragma once
#include <iostream>
#include <vector>
#include <string>
// #include "database.h"
// #include "app.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Person {
private:
    
public:
    int id;
    string fName;
    string lName;

    Person(){
        id = 0;
        fName = "";
        lName = "";
    }

    Person(int id, string fName, string lName)
    : id(id),
    fName(fName),
    lName(lName)
    {

    }

    virtual ~Person() = default;
    
    virtual void print() const{};
};

class Student : public Person {
private:
    float gpa;

public:
    Student() : Person(){
        gpa = 0;
    }

    Student(int id, string fName, string lName, float gpa)
    : Person(id, fName, lName),
    gpa(gpa)
    {

    }

    ~Student() = default;

    void print() const;
};

class Teacher : public Person {
private:
    int salary;

public:
    Teacher() : Person(){
        salary = 0;
    }

    Teacher(int id, string fName, string lName, int salary)
    : Person(id, fName, lName),
    salary(salary)
    {

    }
    
    ~Teacher() = default;

    void print() const;
};