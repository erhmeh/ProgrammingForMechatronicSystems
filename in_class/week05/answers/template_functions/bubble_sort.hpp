#include <iostream>
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& values) {
	bool did_swap = true;
    while(did_swap) {
        did_swap = false;
        for (unsigned int i = 1; i < values.size(); i++) {
            // if this pair is out of order
            if (values.at(i-1) > values.at(i)) {
                // swap them and remember something changed 
                T temp = values.at(i);
                values.at(i) = values.at(i - 1);
                values.at(i - 1) = temp;
                did_swap = true;
            }
        }
	}

}

template <typename T>
void printValues(std::vector<T>& values) {
	for (auto value : values) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}
