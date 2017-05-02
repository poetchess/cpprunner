#include <list>
#include <vector>
#include <iostream>

using std::list;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
    list<const char*> cl{"this", "is", "an", "insane", "world"};
    vector<string> svec;

    svec.assign(cl.cbegin(), cl.cend());

    for(auto e : svec) {
        cout << e << endl;
    }

    return 0;
}
