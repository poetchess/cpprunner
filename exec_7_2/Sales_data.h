#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

struct Sales_data {

    // member functions
    // Every member function must be declared inside its class.
    // Member functions can be defined inside or outside of the class body.
    // Functions defined inside of the class are implicitly inline.

    // Member functions access the object on which they were called through an
    //   extra, implicit parameter named 'this'. When we call a member function,
    //   'this' is initialized with the address of the object on which the 
    //   function was invoked. 'this' is intended to always refer to "this"
    //   object, 'this' is a const pointer.

    // The keyword 'const' following the parameter list is to modify the type 
    //   of the implicit 'this' pointer. By default, the type of 'this' is a 
    //   const pointer to the non-const version of the class type, which means 
    //   we cannot call an ordinary member function on a const object. A 'const'
    //   following the parameter list indicates that 'this' is a pointer to 
    //   'const'. Such a member function is const member function.
    std::string isbn() const {return bookNo;}
    Sales_data & combine(const Sales_data &);
    double avg_price() const;

    // data members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// Once the compiler sees the function name, the rest of the code is interpreted
// as being inside the scope of the class.
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

// nonmember interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

#endif
