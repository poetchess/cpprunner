#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>

class Person {

friend std::istream & read(std::istream &, Person &);
friend std::ostream & print(std::ostream &, const Person &);

public:
    Person() = default;
    Person(std::istream &);

    string get_name() const {
        return name;
    }

    string get_address() const {
        return address;
    }
  
private:  
    string name;
    string address;
};

Person::Person(std::istream &is) {
    read(is, *this);
}

std::istream & read(std::istream &, Person &);
std::ostream & print(std::ostream &, const Person &);

#endif
