#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, current;
    int count;
    std::cout << "Enter several transactions:" << std::endl;

    if (std::cin >> current) {
        count = 1;
        while (std::cin >> item) {
            if (item.isbn() == current.isbn()) {
                count++;
            } else {
                std::cout << "ISBN: " << current.isbn() << ", number: " << count 
                          << std::endl;
                count = 1;
                current = item;
            }
        }
        std::cout << "ISBN: " << current.isbn() << ", number: " << count 
                  << std::endl;
    }
    return 0;
}
