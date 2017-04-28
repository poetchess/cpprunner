#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::stoi;
using std::cout;
using std::endl;

bool is_in_range(vector<int>::const_iterator begin, 
                    vector<int>::const_iterator end, int needle) {
    while (begin != end) {
        if (*begin == needle)
            return true;
        ++begin;
    }
    return false;
}

int main(int argc, char *argv[]) {
    vector<int> ivec{1, 2, 3, 4, 5, 9, 8, 7, 6, 0};
    auto b = ivec.cbegin();
    auto e = ivec.cend();
    if (is_in_range(b+2, e-2, stoi(argv[1], nullptr)))
        cout << "In range" << endl;
    else
        cout << "Not in range" << endl;
}
