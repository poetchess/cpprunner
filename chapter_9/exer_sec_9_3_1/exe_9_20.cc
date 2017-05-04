#include <deque>
#include <list>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::deque;

int main() {
    int a;
    deque<int> even;
    deque<int> odd;
    list<int> il;

    while (cin >> a) {
        il.push_back(a);
    }

    for (auto i : il) {
        if (i % 2)
            odd.push_back(i);
        else
            even.push_back(i);
    }

    cout << "Elements in the even deque:" << endl;
    for (auto i : even) {
        cout << i << " ";
    }

    cout << endl;
    cout << "Elements in the odd deque:" << endl;
    for (auto i : odd) {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}