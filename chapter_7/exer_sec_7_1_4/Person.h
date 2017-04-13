#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>

struct Person {

    Person() = default;
    Person(std::istream &);

    string get_name() const {
        return name;
    }

    string get_address() const {
        return address;
    }
    
    string name;
    string address;
};

std::istream & read(std::istream &, Person &);
std::ostream & print(std::ostream &, const Person &);

Person::Person(std::istream &is) {
    read(is, *this);
}
#endif
