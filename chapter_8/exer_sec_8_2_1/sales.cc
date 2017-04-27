#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"

using std::cout; 
using std::cerr; 
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::ifstream;

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

int main(int argc, char *argv[]) {

    if (argc < 2)
        return -1;

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "Open file failed." << endl;
        return -1;
    }

    Sales_data total(ifs);
    if (!ifs) {
        cerr << "No data?!" << endl;
        return -1;
    }

    while (ifs) {
        Sales_data trans(ifs);
        if (ifs) {
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
