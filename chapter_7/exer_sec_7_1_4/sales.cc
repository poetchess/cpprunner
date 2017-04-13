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

// Although the function defines operation that is conceptually part of the 
//   interface of the class, it is not part of the class itself.
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

    Sales_data total(cin);
    if (!cin) {
        cerr << "No data?!" << endl;
        return -1;
    }

    while (cin) {
        Sales_data trans(cin);
        if (cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
    }
    
    print(cout, total) << endl;
    return 0;
}
