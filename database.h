#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "person.h"
// #include "app.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;



class Database {
private: 
    int size;
    vector<Person*> data;

public:
    Database(){
        size = 0;
    }
    ~Database();
    int getSize() const;
    void print() const;
    int insert(Person* p);
    int remove(int index);
    int search(int option, string key) const;
};