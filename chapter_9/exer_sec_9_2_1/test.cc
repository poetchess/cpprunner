#include <list>
#include <iostream>

using std::cout;
using std::endl;
using std::list;

int main() {
    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    //while (iter1 < iter2) //compile time error: no match for 'operator<'
    while (iter1 != iter2)
    {
        cout << "Within the loop" << endl;
    }

    cout << "Expect to exit the loop" << endl;
}
