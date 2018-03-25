// Includes std::cout and friends so we can output to console
#include <iostream>

// Every executable needs a main function which returns an integer
int main () {
    // Assign a double x of value 41012
    double x = 41012.0;

    // Use a pointer ip to point to x
    double *ip = &x;

    // Print the value of what ip is pointing to
    std::cout << "value pointed to by ip is " << *ip << std::endl;

    // Make y reference to x
    double &y = x;

    // Print the value of what y is referencing to
    std::cout << "value referenced by y is " << y << std::endl;

    // Create a double z of value 1
    double z = 1.0;

    // Use a pointer ip to point to z
    ip = &z;

    // Make y to reference to z
    // Can't be done because you can't change where a reference points after it is created

    // Print the value of what ip and y is referencing to
    std::cout << "value pointed to by ip is " << *ip << std::endl;
    std::cout << "value referenced by y is " << y << std::endl;

    // Main function should return an integer
    return 0;
}
