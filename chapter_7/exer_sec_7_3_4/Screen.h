#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>

class Screen {
    friend class Window_mgr;
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), 
                contents(ht * wd, c) {}

    // implicitly inline
    char get() const {return contents[cursor];}

    // explicitly declare a member function as inline
    inline char get(pos ht, pos wd) const;

    // specify inline on function definition
    Screen &move(pos r, pos c);

    // Functions that return a reference are lvalues, which means that they 
    //   return the object itself, not a copy of the object.
    Screen &set(char c) { contents[cursor] = c; return *this;}
    Screen &set(pos r, pos c, char nc);

    // We can overload a member function based on whether it is const for the
    //   same reason that we can overload a function based on whether a pointer
    //   parameter points to const.
    // When we call display on an object, const member function will be called
    //   on the const object while non-const member function will be called on
    //   non-const object since it is a better match.
    const Screen &display(std::ostream &) const;
    Screen &display(std::ostream &os = std::cout);
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

#endif
