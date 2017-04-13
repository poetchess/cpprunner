#include <iostream>

int main() {
    std::cout << "/*";
    std::cout << "*/";

    //[g++ reported] error: missing terminating " character
    std::cout << /* "*/" */;

    std::cout << /*  "*/" /*  "/*"  */;
    return 0;
}
