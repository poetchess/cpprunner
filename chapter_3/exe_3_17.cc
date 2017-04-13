#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

#define NUM_PER_LINE    8

int main() {
    string s;
    vector<string> svec;

    std::cout << "Enter several strings:" << std::endl;
    while (std::cin >> s) {
        svec.push_back(s);
    }

    std::cout << "Complete adding elements." << std::endl;
    for (auto &s : svec) {
        for (auto &c : s) {
            c = toupper(c);
        }
    }
    std::cout << "Uper Case Elements are: " << std::endl;
    int n = 1;
    for (auto s : svec) {
        if (n++ < NUM_PER_LINE) {
            std::cout << s << " ";
        } else {
            std::cout << s << std::endl;
            n = 1;
        }
    }
    
    std::cout << std::endl;
}
