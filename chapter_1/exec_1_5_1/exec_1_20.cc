#include <iostream>
#include "Sales_item.h"

int main() {
    std::cout << "Enter several books, the format is ISBN number price: " 
              << std::endl;
    
    Sales_item book;
    while (std::cin >> book) {
        std::cout << "You just entered: ";
        std::cout << book << std::endl;
    }
    std::cout << "Bye" << std::endl;
    return 0;
}
