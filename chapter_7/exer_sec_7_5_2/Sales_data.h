#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

class Sales_data {

// A class can allow another class or function to access its non-public members 
//   by making that class or function a friend.
// Friend declaration may appear only inside a class definition. Friends are not
//   members of the class and are not affected by the access specifier.
// A friend declaration only specifies access. It is not a general declaration 
//   of the function. If we want the users of a class to be able to call a 
//   friend function, we must declare it separately from the friend declaration.
friend Sales_data add(const Sales_data &, const Sales_data &);
friend std::istream &read(std::istream &, Sales_data &);
friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p*n) {
                    std::cout << "In Sales_data(s, n, p) body" << std::endl;
                }
    // C++11 delegating constructors
    // A delegating constructor uses another constructor from its own class to
    //   perform its initialization.
    // When a constructor delegates to another constructor, the constructor
    //   initializer list and function body of the delegated-to constructor
    //   are both executed.
    Sales_data(): Sales_data("", 0, 0) {
        std::cout << "In Sales_data() body" << std::endl;
    }
    Sales_data(std::string s): Sales_data(s, 0, 0) {
        std::cout << "In Sales_data(s) body" << std::endl;
    }
    Sales_data(std::istream &is): Sales_data() {
        std::cout << "In Sales_data(is) body" << std::endl;
        read(is, *this);
    }

    std::string isbn() const {return bookNo;}
    Sales_data & combine(const Sales_data &);
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

#endif
