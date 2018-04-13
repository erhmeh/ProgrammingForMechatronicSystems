#include <iostream> // Includes std::cout and friends so we can output to console
#include <random> // Includes the random number generator
#include <chrono> // Includes the system clock
#include <thread>
#include "VAccelerometer.h"
#include <math.h>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono; // //to enable sensor to operate at required frequency

#define ARRAY_SIZE 3 // This macro sets the array length in our main function

virtualAccelerometer::virtualAccelerometer(){}


void virtualAccelerometer::populateWithRandomNumbers(int num_array[], size_t array_size) {

    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> value_distribution(0,1023);
    
    for (int i=0; i<array_size; i++) {
        
        num_array[i] = value_distribution(generator);
    }
    

}

void virtualAccelerometer::setNumArray(int num_array[])
{

    xAxis_ = num_array[0];
    yAxis_ = num_array[1];
    zAxis_ = num_array[2];
    
}

void virtualAccelerometer::getRandomNumbers()
{
    sleep_for(milliseconds(100)); //10hz = 100ms This simulates a 10hz sample rate, however, doesn't account for the time taken to execute code (so output will be slightly slower than 10hz)
    int my_array[ARRAY_SIZE];
    populateWithRandomNumbers(my_array, ARRAY_SIZE);
    setNumArray(my_array);
}

void virtualAccelerometer::getAccelerationData(double &x, double &y, double &z)
{
    getRandomNumbers();
    x = xAxis_;
    y = yAxis_;
    z = zAxis_;
    
}



