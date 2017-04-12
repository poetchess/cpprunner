#ifndef _PERSON_H_
#define _PERSON_H_

struct Person {
    string get_name() const {
        return name;
    }

    string get_address() const {
        return address;
    }
    
    string name;
    string address;
};

#endif