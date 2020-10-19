#pragma once
#include <iostream>
#include <vector>
#include <string>
// #include "database.h"
#include "person.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;


class App {
private: 
    Database db;

    void viewAll() const;
    int addRecord();
    int removeRecord();
    int searchRecord() const;
    int backOption() const;

public:
    App(){

    }
    ~App(){};
    void init();
    void menu();
};