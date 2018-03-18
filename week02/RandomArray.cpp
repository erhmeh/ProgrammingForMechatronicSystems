#include "RandomArray.h"
#include <random>

void RandomArray::setSeed(int i){
        seed_ = i;
        srand(seed_); // Generate random seed
}

void RandomArray::setArraySize(int i){
        size_ = i;
        std::fill_n(randDoub_, size_, 0); // Clear array
}

void RandomArray::generate(void){
        for (int i = 0; i < size_; i++) {
                randDoub_[i] = (double)rand();
        }
}
