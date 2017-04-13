#include <string>
#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
#if 0
    for (auto &c : s) {
        c = 'X';
    }
#endif
    decltype(s.size()) i = 0;

#if 0
    while (i < s.size()) {
        s[i] = 'X';
        i++;
    }
#endif
    for (; i < s.size(); i++) {
        s[i] = 'X';
    }
    
    std::cout << s << std::endl;
}