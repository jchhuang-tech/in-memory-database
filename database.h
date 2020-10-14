#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Person {
private:
    
public:
    int id;
    int age;
    string faculty;

    Person(){
        id = 0;
        age = 0;
        faculty = "";
    }

    Person(int id, int age, string faculty)
    : id(id),
    age(age),
    faculty(faculty)
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

    Student(int id, int age, string faculty, float gpa)
    : Person(id, age, faculty),
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

    Teacher(int id, int age, string faculty, int salary)
    : Person(id, age, faculty),
    salary(salary)
    {

    }
    
    ~Teacher() = default;

    void print() const;
};

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
    int search(int key) const;
};