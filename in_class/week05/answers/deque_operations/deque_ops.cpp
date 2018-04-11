#include <iostream>
#include <deque>
#include <chrono>
#include <random>

void populateDeque(std::deque<double>& values, int num_values, double mean, double std_dev) {
	// Create a random number generator and seed it from
	// the system clock so numbers are different each time
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
 	std::default_random_engine generator (seed);

 	// Create a distribution with the provided parameters
  	std::normal_distribution<double> distribution (mean, std_dev);

  	// Push the specified number of values,
  	// sampled from the distrubution
  	for (int i = 0; i<num_values; i++){
  		values.push_back(distribution(generator));
  	}
}

void printDeque(std::deque<double>& values) {
	// Loop through the deque and print the values
	for (auto value : values) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

void smoothDeque(std::deque<double>& values) {
	// For a deque with n values
	// there are n-1 consecutive pairs
	for (int i = 0; i<values.size()-1; i++){
		// Get the front before popping
  		double popped = values.front();
  		values.pop_front();
  		// Get the front after popping
  		double front = values.front();

  		// Interpolate between them and push to the deque
  		double interp = (popped + front) / 2.0;
  		values.push_back(interp);
  	}
  	// Pop the last value, we have already
  	// used it in the last iteration of the loop
  	values.pop_front();
}

int main() {

	// Create an empty deque
	std::deque<double> values;
	// Populate it with random numbers
	populateDeque(values, 10, 8.0, 4.0);
	// Print the contents of the deque
	printDeque(values);
	// Interpolate between each pair of values
	smoothDeque(values);
	// Print the result
	printDeque(values);

	return 0;
} 