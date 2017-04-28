#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::stoi;
using std::cout;
using std::endl;

vector<int>::iterator iterator_from_value(vector<int>::iterator begin, 
                    vector<int>::iterator end, int needle) {
    while (begin != end) {
        if (*begin == needle)
            return begin;
        ++begin;
    }
    return end;
}

int main(int argc, char *argv[]) {
    vector<int> ivec{1, 2, 3, 4, 5, 9, 8, 7, 6, 0};
    auto b = ivec.begin() + 2;
    auto e = ivec.end() - 2;
    auto n = iterator_from_value(b, e, stoi(argv[1], nullptr));
    if (e != n)
        cout << "Looking for " << *n << ": in range." << endl;
    else
        cout << "Not in range" << endl;
}
