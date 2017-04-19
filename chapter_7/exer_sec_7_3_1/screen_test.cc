#include <string>
#include <iostream>
#include "Screen.h"

using std::string;
using std::cout;

int main() {
    Screen s0;
    Screen s1(30, 80);
    s1.print(cout);

}
