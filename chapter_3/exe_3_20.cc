#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main() {
    int a;
    vector<int> ivec;

    std::cout << "Enter several integers:" << std::endl;
    while (std::cin >> a) {
        ivec.push_back(a);
    }

    std::cout << "Complete adding elements." << std::endl;
    std::cout << "Sums of pairs are: ";
    
    decltype(ivec.size()) i, n_elem = ivec.size();
    decltype(ivec.size()) n_pair = n_elem >> 1;
#if 0
    for (i = 0; i < n_pair; i++) {
        std::cout << ivec[i*2] + ivec[2*i+1] << " ";
    }

    if ((n_elem % 2) != 0)
        std::cout << ivec[n_elem -1];

    std::cout << std::endl;
#endif

    for (i = 0; i < n_pair; i++){
        std::cout << ivec[i] + ivec[n_elem-1-i] << " ";
    }

    if ((n_elem % 2) != 0)
        std::cout << ivec[n_pair];

    std::cout << std::endl;
}
