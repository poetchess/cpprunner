#include <string>
#include <iostream>
#include "Screen.h"

int main() {
    Window_mgr wm;
    Screen s(7, 20, '*');
    Window_mgr::ScreenIndex i = wm.addScreen(s);
    wm.clear(i);
}
