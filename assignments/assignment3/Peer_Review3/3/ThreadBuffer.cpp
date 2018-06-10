#include "ThreadBuffer.h"



void ThreadBuffer::addValue(std::pair<double,std::chrono::system_clock::time_point> value) {
    std::unique_lock<std::mutex> lock(mutex_);
    value_ = value;
    cv_.notify_all();
}



std::pair<double,std::chrono::system_clock::time_point> ThreadBuffer::getValues() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock);
    return value_;
}
