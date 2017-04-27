#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using std::istream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;
using std::string;
using std::istringstream;
using std::vector;
using std::ifstream;

int main(int argc, char *argv[]) {

    if (argc < 2)
        return -1;

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "Open file failed." << endl;
        return -1;
    }

    vector<string > svec;
    string buf;
    while (getline(ifs, buf)) {
        svec.push_back(buf);
    }

    cout << "File contents:" << endl;
    istringstream iss;

    for (auto e : svec) {
        iss.str(e);
        while (iss >> buf) {
            cout << buf << endl;
        }

        //iss is defined outside the loop, need to clear the error status
        if (iss.eof()) {
            iss.clear();
        }
    }
    return 0;
}
