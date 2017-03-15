#include <iostream>

/*
 * Type conversion:
 * 1) When we assign one of the nonbool arithmetic types to a bool object, the 
 *    result is false if the value is 0 and true otherwise.
 * 2) When we assign a bool to one of the other arithmetic types, the resulting
 *    value is 1 if the bool is true and 0 if the bool is false.
 * 3) When we assign a floating-point value to an object of integral type, the 
 *    value is truncated. The value that is stored is the part before the 
 *    decimal point.
 * 4) When we assign an integral value to an object of floating-point type, 
 *    the frac- tional part is zero. Precision may be lost if the integer has 
 *    more bits than the floating-point object can accommodate.
 * 5) If we assign an out-of-range value to an object of unsigned type, the 
 *    result is the remainder of the value modulo the number of values the 
 *    target type can hold.
 * 6) If we assign an out-of-range value to an object of signed type, the 
 *    result is undefined.
*/
int main() {

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;

    //Mixing signed and unsigned values can yield surprising results.
    //signed values are automatically converted to unsigned.
    //The result below will wrap around.
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
}
