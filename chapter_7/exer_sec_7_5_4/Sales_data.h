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


    Sales_data(): Sales_data("", 0, 0) {}

    // Every constructor that can be called with a single argument defines an
    //   implicit conversion to a class type. Such constructors are referred to
    //   as converting constructors.

    // Compiler will automatically apply only one class-type conversion.

    // We can suppress the implicit conversion defined by constructors by
    //   declaring the constructor as 'explicit'. The 'explicit' keyword is only
    //   meaningful on converting constructors, and it is used only on the
    //   constructor declaration inside the class.

    // Explicit constructors can be used only for direct initialization.

    // Although the compiler will not use an explicit constructor for an
    //   implicit conversion, we can use such constructors explicitly to force
    //   a conversion.
    explicit Sales_data(std::string s): Sales_data(s, 0, 0) {}

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
