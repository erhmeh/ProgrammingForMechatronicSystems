#include <iostream>
#include <queue>
#include <chrono>
#include <random>

void populateQueue(std::queue<double>& values, int num_values, double mean, double std_dev) {
	// Create a random number generator and seed it from
	// the system clock so numbers are different each time
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
 	std::default_random_engine generator (seed);

 	// Create a distribution with the provided parameters
  	std::normal_distribution<double> distribution (mean, std_dev);

  	// Push the specified number of values,
  	// sampled from the distrubution
  	for (int i = 0; i<num_values; i++){
  		values.push(distribution(generator));
  	}
}

void printQueue(std::queue<double>& values) {
	// Loop through the queue and print the values
	for (int i = 0; i < values.size(); i++) {
		std::cout << values.front() << " ";
		values.push(values.front());
		values.pop();
	}
	std::cout << std::endl;
}

void smoothQueue(std::queue<double>& values) {
	// For a queue with n values
	// there are n-1 consecutive pairs
	for (int i = 0; i<values.size()-1; i++){
		// Get the front before popping
  		double popped = values.front();
  		values.pop();
  		// Get the front after popping
  		double front = values.front();

  		// Interpolate between them and push to the queue
  		double interp = (popped + front) / 2.0;
  		values.push(interp);
  	}
  	// Pop the last value, we have already
  	// used it in the last iteration of the loop
  	values.pop();
}

int main() {

	// Create an empty queue
	std::queue<double> values;
	// Populate it with random numbers
	populateQueue(values, 10, 8.0, 4.0);
	// Print the contents of the queue
	printQueue(values);
	// Interpolate between each pair of values
	smoothQueue(values);
	// Print the result
	printQueue(values);

	return 0;
} 