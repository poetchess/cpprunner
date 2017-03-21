#include <iostream>

int main() {

    //Variables of built-in type defined inside a function are uninitialized.
    //The value of an uninitialized variable of built-in type is undefined.
    //It is an error to copy or otherwise try to access the value of a variable 
    //whose value is undefined.
    std::cin >> int input_value;

    //error: type 'double' cannot be narrowed to 'int' in initializer list
    int i = {3.14};

    //implicit conversion from 'double' to 'int' changes value from 3.14 to 3
    int j = 3.14;

    //use of undeclared identifier 'wage'
    double salary = wage = 9999.99;
}