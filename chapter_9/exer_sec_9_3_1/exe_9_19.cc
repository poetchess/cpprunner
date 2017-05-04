#include <string>
#include <list>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main() {
    string buf;
    list<string> sl;
    while (cin >> buf) {
        sl.push_back(buf);
    }

    auto iter = sl.cbegin();
    while (iter != sl.cend()) {
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}