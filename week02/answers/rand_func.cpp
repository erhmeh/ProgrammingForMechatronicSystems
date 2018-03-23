#include <iostream> // Includes std::cout and friends so we can output to console
#include <random> // Includes the random number generator
#include <chrono> // Includes the system clock

#define ARRAY_SIZE 100 // This macro sets the array length in our main function


// Create a function that accepts an integer array and assigns random values (between 1 and 100)
// to a random number of elements of the array (1 to max length)

// The function accepts an integer array and an array size
// ...and return the number of numbers that are changed in the array
int populateWithRandomNumbers(int num_array[], size_t array_size) {

    // Get a seed number from the system clock (using the chrono library)
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Create a random number generator (using the random library)
    std::default_random_engine generator(seed);
    // ...and two uniform distribution objects with the desired ranges
    std::uniform_int_distribution<int> value_distribution(1,100);
    std::uniform_int_distribution<int> n_distribution(1,array_size);

    // Draw a random number between 1 and array_size to decide how many
    // numbers to add to the array
    int n = n_distribution(generator);

    // Loop through the first n elements in the array...
    for (int i=0; i<n; i++) {
        // At each element draw a random number between
        // 1 and 100 set the value of the element accordingly
        num_array[i] = value_distribution(generator);
    }
    //Return the number of values that were changed in the array
    return n;
}

// This function loops through the first 'array_size'
// elements of the array and prints them
void printArray(int num_array[], size_t array_size) {
    std::cout << "Printing array: ";
    for (int i=0; i<array_size; i++) {
        std::cout << num_array[i] << " ";
    }
    std::cout << std::endl;
}

// Every executable needs a main function
// ...this is where program execution begins
int main () {
    // Create the array of integers with size given by ARRAY_SIZE
    int my_array[ARRAY_SIZE];

    //printArray(my_array, ARRAY_SIZE); // Uncomment this line to see the state of the array before we set any values

    // Call our function to modify the array
    int n = populateWithRandomNumbers(my_array, ARRAY_SIZE);

    // Report the return value of the function
    std::cout << "Generated " << n << " random numbers" << std::endl;

    // Print the values that were changed by the function
    printArray(my_array, n);
    return 0;
}
