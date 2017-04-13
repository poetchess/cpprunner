#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

struct Sales_data {

    // Classes control object initialization by defining constructor(s).
    // The job of a constructor is to initialize the data member of a class obj.
    // Constructors may not be declared as const. When we create a const object 
    //   of a class type, the object does not assume its constness until after
    //   the constructor completes the object's initialization.
    // A constructor is run whenever an object of a class type is created.

    // Synthesized default constructor:
    //   If the class does not explicitly define any constructors, the complier
    //   will implicitly define the default constructor for us. This synthesized
    //   one will initialize each data member as follows:
    //     1) If there is an inner-class initializer, use it to init the member.
    //     2) Otherwise, default initializa the member.

    // Three reasons why the class need to define its own default constructor:
    // 1) If we define any constructors, compiler will not generate a default 
    //      one for us. In this case, if we also need a default one, we need to
    //      define it explicitly.
    // 2) Sometimes, the complier is unable to synthesize a default constructor,
    //      in this case, if we need a default one, we need to define it.
    // 3) For some classes, the synthesized default constructor does the wrong 
    //      thing. i.e. members of built-in or compound type that are default 
    //      initialized will have undefined values. In this case, we should 
    //      either initialize those members inside the class or define our own
    //      version of the default constructor.

    // Under c++11 standard, if we want the default behavior, we can ask the 
    //   compiler to generate the constructor for us by using '= default' after
    //   the parameter list. It can appear with the declaration inside the class
    //   body or on the definition outside the class body.
    Sales_data() = default;

    // Constructor initialization list specifies initial values for one or more
    //   data members of the object being created. When a member is omitted from
    //   the constructor initializer list, it is implicitly initialized using 
    //   the same process as is used by synthesized default constructor.
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &);

    // Member functions
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

// nonmember interface functions, should be declared in the same header as the 
//   class itself.

// The IO classes are types that cannot be copied, so we may only pass them by 
//   reference. And reading or writing to a stream changes that stream, so both
//   read() and print() take ordinary reference.
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

// The constructor initializer list is empty. But the members of this object are
//   still initialized before the constructor body is executed.
Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}
#endif
