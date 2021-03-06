#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin; using std::cout; using std::cerr; using std::endl;
using std::string;
using std::istream; using std::ostream;

Sales_data & Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &sd)
{
    double price = 0;
    is >> sd.bookNo >> sd.units_sold >> price;
    sd.revenue = price * sd.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &sd)
{
    os << sd.bookNo << " " << sd.units_sold << " " 
        << sd.revenue << " " << sd.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main() {
    Sales_data item("112233", 5, 6);
    print(cout, item) << endl;

    string isbn("112233");

#if 0
    // works only if the constructor is not declared as explicit.
    item.combine(isbn);
    print(cout, item) << endl;
#endif

    // if the constructor is declared as explicit, we can still force a conversion.
    item.combine(static_cast<Sales_data>(isbn));
    print(cout, item) << endl;
}
