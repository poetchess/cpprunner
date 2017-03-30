#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
    string s, cs;
#if 0
    while (cin >> s) {
        cs += s;
    }
    cout << "concatenated string: " << cs << endl;
#endif
    while (cin >> s) {
        cs += s;
        cs += ' ';
    }
    cout << "concatenated string: " << cs << endl;
}