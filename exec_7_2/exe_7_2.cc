#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin; using std::cout; using std::cerr; using std::endl;
using std::string;
using std::istream; using std::ostream;

// This function is intended to act like the compound assignment operator '+='.
// When we define a function that operates like a built-in operator, our 
//   function should mimic the behavior of that operator. The built-in 
//   assignment operators return their left-hand operand as an lvalue. To return
//   an lvalue, our combine function must return a reference.
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
        << sd.revenue << " " << sd.avg_price();
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
