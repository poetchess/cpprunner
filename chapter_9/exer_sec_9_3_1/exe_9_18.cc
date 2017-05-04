#include <string>
#include <deque>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

int main() {
    string buf;
    deque<string> sq;
    while (cin >> buf) {
        sq.push_back(buf);
    }

    auto iter = sq.cbegin();
    while (iter != sq.cend()) {
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}