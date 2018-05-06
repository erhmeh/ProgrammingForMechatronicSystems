#include <iostream>
#include "rectangle.h"

int main () {
    // Create a rectangle
    Rectangle rectangle;
    rectangle.setValues(4,6);

    // Print some info about it
    std::cout << "The area of box is " << rectangle.getArea() << std::endl;
    std::cout << "It is a " << rectangle.getDescription() << std::endl;

    // Does it make sense to create a shape like this ?
    Shape shape;
    std::cout << "The area of shape is " << shape.getArea() << std::endl;
    std::cout << "It is a " << shape.getDescription() << std::endl;

    // Can you implement the Triangle class as a sub-class of Shape?

    // How would we use the Shape class in our code to be shape agnostic
}
