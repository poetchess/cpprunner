#include <string>
#include <iostream>

using std::string;
using std::cin; using std::cout; using std::endl;

string s[5] = {"this", "is", "an", "insane", "world"};

#if 0
using T = string[5];
T & f(void) {
    return s;
}

decltype(s) &f(void) {
    return s;
}
#endif

auto f(void) -> string (&) [5]
{
    return s;
}

int main() {

    for (auto se : s) {
        cout << se << endl;
    }

    //T & srf = f();
    decltype(s) &srf = f();

    for (auto se : srf) {
        cout << se << endl;
    }
}