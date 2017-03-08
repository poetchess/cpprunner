#include <iostream>

int main() {
    int sum = 0; int v = 0;
    std::cout << "Enter several integers: ";
    while (std::cin >> v) {
        sum += v;
    }
    std::cout << "sum is: " << sum << std::endl;
}
