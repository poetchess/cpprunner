#ifndef __WINDOW_MGR_H__
#define __WINDOW_MGR_H__

#include <string>
#include <vector>
#include "Screen.h"

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(5, 20, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

#endif
