#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main() {

#if 0
    string line;
    while (std::getline(cin, line)) {
        cout << line << endl;
    }
#endif

    string word;
    while (cin >> word) {
        cout << word << endl;
    }
}