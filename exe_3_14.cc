#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
    int a;
    vector<int> ivec;

    std::cout << "Enter several integers:" << std::endl;
    while (std::cin >> a) {
        ivec.push_back(a);
    }

    std::cout << "Complete adding elements." << std::endl;
    std::cout << "Elements are: ";
    for (auto i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
