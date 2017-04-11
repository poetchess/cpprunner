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
    is >> sd.bookNo >> sd.units_sold >> sd.revenue;
    return is;
}

ostream &print(ostream &os, const Sales_data &sd)
{
    os << sd.bookNo << " " << sd.units_sold << " " 
        << sd.revenue;
    if (sd.units_sold != 0)
        os << " " << sd.revenue / sd.units_sold;
    return os;
}

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
