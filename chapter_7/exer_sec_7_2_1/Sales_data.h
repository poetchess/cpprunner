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
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &);

    std::string isbn() const {return bookNo;}
    Sales_data & combine(const Sales_data &);
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

#endif
