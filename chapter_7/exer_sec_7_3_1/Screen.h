#include <string>
#include <iostream>

class Screen {
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

    void print(std::ostream &);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
