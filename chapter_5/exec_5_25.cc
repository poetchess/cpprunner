#include <iostream>

double do_division(double v1, double v2) {
    if (v2 == 0) {
        throw std::runtime_error("Divided by zero is not allowed");
    } else {
        return v1 / v2;
    }
}

int main() {
    double v1 = 0, v2 = 1, result;
    std::cout << "Enter two numbers: ";
    std::cin >> v1;
    while (std::cin >> v2) {
        try {
            result = do_division(v1, v2);
            std::cout << "The result of " << v1 << " divided by " << v2 
                      << " is " << result << std::endl;
            return 0;
        } catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
            std::cout << "Press Y to continue: ";
            char c;
            std::cin >> c; 
            if (!std::cin || c != 'Y')
                break;
            std::cout << "New 2nd number: ";
        }
    }
    std::cout << "Quit the program" << std::endl;
    return  -1;
}

