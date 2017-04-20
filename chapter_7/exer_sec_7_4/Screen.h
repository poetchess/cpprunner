#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <vector>
#include <iostream>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    ScreenIndex addScreen(const Screen &);
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), 
                contents(ht * wd, c) {}

    char get() const {return contents[cursor];}
    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    Screen &set(char c) { contents[cursor] = c; return *this;}
    Screen &set(pos r, pos c, char nc);

    const Screen &display(std::ostream &) const;
    Screen &display(std::ostream &os = std::cout);
    pos size() const;

private:
    void do_display(std::ostream &) const;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char nc) {
    pos row = c * width;
    contents[row + c] = nc; 
    return *this;
}

inline Screen::pos
Screen::size() const {
    return height * width;
}
inline void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}

#endif
