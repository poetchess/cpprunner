#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

class Sales_data {

friend Sales_data add(const Sales_data &, const Sales_data &);
friend std::istream &read(std::istream &, Sales_data &);
friend std::ostream &print(std::ostream &, const Sales_data &);

public:
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p*n) {}

    // The role of default constructor
    // The default constructor is used automatically whenever an object is
    //   default or value initialized.

    // Default initialization happens:
    // 1. When we define non-static  variables or arrays at block scope without
    //    initializers.
    // 2. When a class that itself has members of class type uses the
    //    synthesized default constructor.
    // 3. When members of class type are not explicitly initialized in a
    //    constructor initializer list.

    // Value initialization happens:
    // 1. During array initialization when we provide fewer initializers than
    //    the size of the array.
    // 2. When we define a local static object without an initializer.
    // 3. When we explicitly request value initialization by writing an
    //    expression of the form T() where T is the name of a type.

    Sales_data(): Sales_data("", 0, 0) {}

    Sales_data(std::string s): Sales_data(s, 0, 0) {}

    Sales_data(std::istream &is): Sales_data() {
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
