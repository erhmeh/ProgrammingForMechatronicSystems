// Includes std::cout and friends so we can output to console
#include <iostream>

// Create a function that accepts a double value as a parameter and
// 1. Returns a square value
double squareOf(double value) {
    return value*value;
}

// 2. Returns a bool value if the double is greater than zero
// and the square value instead of initial passed value
bool squareOfCheckPositive(double &value) {
    bool is_positive = value > 0.0;
    value *= value;
    return is_positive;
}

// 3. Returns bool value if the double is greater than zero, the square value, the cube value and the passed value incremented by one
bool squareCubeIncrement(double value, double &square, double &cube, double &increment) {
    square = value*value;
    cube = square*value;
    incrment = value + 1;
    return value > 0.0;
}

// 4. Loop over item 3 for 1-20


// ADVANCED: How best protect the passed value?

// Every executable needs a main function which returns an int
int main () {

    double x = 2.0;

    // 1.
    std::cout << x << " squared is " << squareOf(x) << std::endl;

    // 2.
    y = x;
    std::cout << y << " is ";
    bool result = squareOfCheckPositive(y);
    if (result) {
        std::cout << "positive ";
    } else {
        std::cout << "not positive ";
    }
    std::cout << "and its square is " << y << std::endl;

    // 3.



    return 0;
}




