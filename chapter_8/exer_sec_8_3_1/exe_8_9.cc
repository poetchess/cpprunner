#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;
using std::string;
using std::istringstream;

istream &my_echo(istream &in) {
    string s;
    while (in >> s) {
        cout << s << endl;
    }
    in.clear();
    return in;
}

int main() {
    string buf;
    cout << "Enter something:" << endl;
    if (!getline(cin, buf)) {
        cerr << "Read input failed." << endl;
        return -1;
    }
    istringstream iss(buf);
    istream &is = my_echo(iss);
    cout << "currnt state of the input stream: " << is.rdstate() << endl;
    return 0;
}
