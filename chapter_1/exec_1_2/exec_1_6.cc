#include <iostream>

int main() {
    int v1 = 0, v2 = 0;
    std::cout << "The sum of " << v1;
    //[g++ reported] error: expected primary-expression before ‘<<’ token
    //output operator (>> operator) needs two operands. In this case, the 
    //left-hand one was missing.
    << " and " << v2;
    << " is " << v1 + v2 << std::endl;
    return 0;
}
