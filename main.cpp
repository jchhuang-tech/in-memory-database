#include <iostream>
#include <string>
#include "database.h"
#include "person.h"
#include "app.h" 

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void){

    App app;
    app.init();
    app.menu();

    return 0;
}