#include <iostream>
#include "Sales_item.h"

int main() {
    std::cout << "Enter several transactions with SAME ISBN:" << std::endl;
    Sales_item b, bs;

    while (std::cin >> b) {
        bs += b;
    }

    std::cout << "The sum of transactions is: " << bs << std::endl;
    return 0;
}
