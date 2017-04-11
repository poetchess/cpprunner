#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

struct Sales_data {
    std::string isbn() {return bookNo;}
    Sales_data &combine(Sales_data &);
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, Sales_data &);

#endif
