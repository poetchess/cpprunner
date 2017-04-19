#include <string>
#include <iostream>
#include "Screen.h"

using std::ostream; using std::endl;

char Screen::get(pos r, pos c) const {
    if (r > height || c > width)
        return -1;

    pos row = r * width;
    pos index = row + c;
    return contents[index];
}

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::print(ostream &os) {
    for (pos r = 0; r < height; r++) {
        os << contents.substr(r * width, width);
        os << endl;
    }   
}
