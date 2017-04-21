#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <vector>
#include <iostream>

class Screen;

// Class definitions are processed in two phases:
// 1. The member declarations are compiled.
// 2. Function bodies are compiled only after the entire class has been seen.

// Name lookup for class member declarations:
// Names used in declarations, including names used for the return type and
//   types in the parameter list, must be seen before they are used.
//   If a memeber declaration uses a name that has not yet been seen inside the
//   class, the compiler will look for that name in the scope(s) where the class
//   is defined.

// Type name lookup are special:
// In a class, if a member uses a name from an outer scope and that name is a
//   type, then the class may not redefine that name.

// Name lookup inside the member definitions:
// 1. Look for a declaration of the name inside the member function.
// 2. If the declaration is not found inside the member function, look for a
//    declaration inside the class. All the members of the class are considered.
// 3. If a declaration for the name is not found in the class, look for a
//    declaration that is in scope before the member function definition.
class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    ScreenIndex addScreen(const Screen &);
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

// Classes and non-member functions need not have been declared before they are
//   used in a friend declaration. When a name first appears in a friend
//   declaration, that name is implicitly assumed to be part of the surrounding
//   scope. However the friend itself is not actually declared in that scope.

// Making a member function a friend requires careful structuring:
// 1. Define the Window_mgr class which declares, but cannot define, clear.
//    Screen class must be declared before clear can use the members of Screen.
// 2. Define class Screen, including a friend declaration for clear.
// 3. Define clear, which can now refer to the members in Screen.

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
    friend void dummy_friend();
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

// The return type of a function normally appears before the function name,
//   if the function is defined outside the class body, any name used in the
//   return type is outside the class scope.
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
