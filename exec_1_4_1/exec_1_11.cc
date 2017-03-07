#include <iostream>

int main() {
    int v1 = 0, v2 = 0, min, max;
    std::cout << "Enter two integers: " << std::endl;
    std::cin >> v1 >> v2;

    if (v1 > v2) {
        min = v2;
        max = v1;
    } else {
        min = v1;
        max = v2;
    }

    int i = min;
    while (i < max) {
        std::cout << i++ << " ";
    }
    std::cout << std::endl;
    return 0;
}
