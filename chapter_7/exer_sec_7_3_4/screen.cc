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

const Screen &Screen::display(ostream &os) const {
    do_display(os);
    return *this;
}

Screen &Screen::display(ostream &os) {
    do_display(os);
    return *this;
}

// When one member calls another, the 'this' pointer is passed implicitly.
//   Thus, when display calls do_display, its own 'this' pointer is implicitly 
//   passed to do_display. When the non-const version of display calls 
//   do_display, its 'this' pointer is implicitly converted from a pointer to
//   non-const to a pointer to const.
void Screen::do_display(ostream &os) const {
    for (pos r = 0; r < height; r++) {
        os << contents.substr(r * width, width);
        os << endl;
    }   
}
