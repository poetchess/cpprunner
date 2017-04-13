#include <iostream>
#include "Sales_item.h"

int main() {
    std::cout << "Enter two book transactions with SAME ISBN:" << std::endl;
    Sales_item b1, b2, bs;
    std::cin >> b1 >> b2;
    bs = b1 + b2;
    std::cout << "The sum of two transactions is: " << bs << std::endl;
    return 0;
}
