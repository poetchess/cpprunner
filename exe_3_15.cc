#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
    string s;
    vector<string> svec;

    std::cout << "Enter several strings:" << std::endl;
    while (std::cin >> s) {
        svec.push_back(s);
    }

    std::cout << "Complete adding elements." << std::endl;
    std::cout << "Elements are: ";
    for (auto s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
