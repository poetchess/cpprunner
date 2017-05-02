#include <vector>
#include <iostream>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;

bool is_equal(const vector<int> &iv, const list<int> &il) {

    // different size
    if (il.size() != iv.size())
        return false;

    // same size, both are zero
    if (il.size() == 0)
        return false;

    auto list_iter = il.cbegin();
    auto vec_iter = iv.cbegin();
    for (; list_iter != il.cend(); list_iter++, vec_iter++) {
        if (*list_iter != *vec_iter)
            return false;
    }

    return (list_iter == il.cend());
}

int main() {
    vector<int> iv{1, 2, 3, 4, 5};
    list<int> il1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> il2{1, 3, 4, 5};
    list<int> il3{1, 2, 3, 4, 5};
    vector<int> iv2;
    list<int> il4;
    
    cout << "iv == il1: " << std::boolalpha << is_equal(iv, il1) << endl;
    cout << "iv == il2: " << std::boolalpha << is_equal(iv, il2) << endl;
    cout << "iv == il3: " << std::boolalpha << is_equal(iv, il3) << endl;
    cout << "iv2 == il4: " << std::boolalpha << is_equal(iv2, il4) << endl;
    return 0;
}
