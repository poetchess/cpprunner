#include <iostream>
#include <initializer_list>

using std::cout; using std::endl;
using std::initializer_list;

int sum_up(initializer_list<int> li) {

    //An initializer_list is a library type that represents an array of values 
    //of the specified type.

    int sum = 0;
    //Unlike vector, the elements in an initializer_list are always const 
    //values; there is no way to change the value of an element in an 
    //initializer_list.
    for (auto e : li) {
        sum += e;
    }
    return sum;
}

int main() {
    cout << sum_up({1, 2, 3, 4, 5}) << endl;
    cout << sum_up({-1, -2, -3, 1, 2, 3}) << endl;
}
