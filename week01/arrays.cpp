// Includes std::cout and friends so we can output to console
#include <iostream>

// Create a macro (#define) to represent the array size
#define ARRAY_SIZE 10

// Every executable needs a main function which returns an int
int main () {
    // Create an array x of doubles with 10 elements
    // Populate the elements of array on creating of array, each element [i] has value i (INITIALISER LIST)
    double x[ARRAY_SIZE] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    // Can you create a loop to populate elements of x (each x[i] =i), how to code end of loop?) – (USE MACRO)
    for (int i = 0; i<ARRAY_SIZE; i++) {
        x[i] = i;
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    // Can you use a pointer and loop to initialise elements of array (*ip++)
    for (double *ip = x; ip<(x+ARRAY_SIZE); *ip++ = ip-x) {
        std::cout << "*ip = " << *ip << std::endl;
    }

    // Main function should return an integer
    return 0;
}
