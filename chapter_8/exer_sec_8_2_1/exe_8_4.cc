#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::string;
using std::ifstream;
using std::vector;
using std::getline;

int main(int argc, char *argv[]) {
    string buf;
    vector<string> svec;

    if (argc < 2)
        return -1;

    ifstream ifs(argv[1]);

    //if (!ifs) { //same effect
    if (ifs.fail()) {
        std::cerr << "Open file failed." << std::endl;
        return -1;
    }

    //while (getline(ifs, buf)) { //read a line
    while (ifs >> buf) {
        svec.push_back(buf);    
    }

    std::cout << "File content:" << std::endl << "=============" << std::endl;
    for (auto e : svec) {
        std::cout << e << std::endl;
    }

    ifs.close();
    return 0;
}
