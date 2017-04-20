#include <string>
#include <iostream>
#include "Screen.h"

int main() {
    Screen s(7, 20, '*');
    s.display();

    std::cout << std::endl << std::endl;

    s.move(2, 6).set('@').move(2, 13).set('@')
            .move(4,9).set('(').move(4, 10).set(')');

    s.display();

    std::cout << std::endl << std::endl;

    s.display();
}
