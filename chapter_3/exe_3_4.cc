#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
    string s1, s2;
    cout << "Enter two string:" << endl;
    cin >> s1 >> s2;
#if 0   
    if (s1 == s2) {
        cout << "Strings are equal" << endl;
    } else if (s1 > s2) {
        cout << s1 << " is larger" << endl;
    } else {
        cout << s2 << " is larger" << endl;
    }
#endif
    if (s1.size() == s2.size()) {
        cout << "Strings have same length" << endl;
    } else if (s1.size() > s2.size()) {
        cout << s1 << " is longer" << endl;
    } else {
        cout << s2 << " is longer" << endl;
    }
}