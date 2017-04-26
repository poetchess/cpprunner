#include <iostream>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

istream &myread(istream &in) {
    string s;
    while (in >> s) {
        cout << s << endl;
    }
    in.clear();
    return in;
}

int main() {
    istream &is = myread(cin);
    cout << "currnt state of the input stream: " << is.rdstate() << endl;
    return 0;
}
