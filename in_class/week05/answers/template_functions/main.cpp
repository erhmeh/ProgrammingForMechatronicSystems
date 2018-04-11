#include <iostream>
#include <vector>
#include "bubble_sort.hpp"

int main () {

    std::vector<double> doubles{2.5, 5.0, 3.2, 0.5, 3.0, 10.0, 8.5, 6.5};
    printValues(doubles);
    bubbleSort(doubles);
    printValues(doubles);

    std::vector<int> ints{2, 5, 3, 0, 4, 10, 8, 6};
    printValues(ints);
    bubbleSort(ints);
    printValues(ints);

    return 0;
}
