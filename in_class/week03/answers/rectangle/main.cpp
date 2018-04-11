#include <iostream>
#include "rectangle.h"

int main () {
    // Create a rectangle
    Rectangle rectangle;
    rectangle.setValues(4,6);

    // Print some info about it
    std::cout << "The area of box is " << rectangle.getArea() << std::endl;
    std::cout << "It is a " << rectangle.getDescription() << std::endl;

    // Change it to a square
    rectangle.setValues(4);

    // Print some info about it
    std::cout << "The area of box is " << rectangle.getArea() << std::endl;
    std::cout << "It is a " << rectangle.getDescription() << std::endl;
}
