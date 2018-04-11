#include <deque>
#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include "shape.h"

void populateDeque(std::deque<double>& values, int num_values, double mean, double std_dev){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution (mean,std_dev);

    for (int i = 0; i<num_values; i++){
        values.push_back(distribution(generator));
    }
}

void operateDeque(std::deque<double>& values){
    for (int i = 0; i < 10; i++){
        double j = values.front();
        values.pop_front();
        j += values.front();
        j = j/2;
        values.push_back(j);
    }
}


void printDeque(const std::deque<double>& values){
    for (auto value : values){
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}

//void populateVector(std::vector<shape>& shapes){

//}

int main(){
    std::deque<double> values;
    populateDeque(values, 10, 8.0, 4.0);
    printDeque(values);
    operateDeque(values);
    printDeque(values);

//    std::vector<shape> shape;
//    populateVector(shapes);
    return 0;
}
