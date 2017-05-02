#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> ivec1{1, 2, 3, 4, 5};
    vector<int> ivec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ivec3{1, 3, 4, 5};
    vector<int> ivec4{1, 2, 3, 4, 5};

    cout << "ivec1 < ivec2: " << std::boolalpha << (ivec1 < ivec2) << endl;
    cout << "ivec2 < ivec3: " << std::boolalpha << (ivec2 < ivec3) << endl;
    cout << "ivec1 == ivec4: " << std::boolalpha << (ivec1 == ivec4) << endl;
    
}
