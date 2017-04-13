#include <iostream>

int main() {
    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers: ";
    std::cin >> v1 >> v2;
    //[build with g++] 
    //terminate called after throwing an instance of 'std::runtime_error'
    //  what():  Divid by zero error
    //Aborted (core dumped)
    if (v2 == 0) {
        throw std::runtime_error("Divid by zero error");
    }
    std::cout << "The result of dividing " << v1 << " by " << v2 << " is " 
              << v1 / v2 << std::endl;
    return 0;
}
