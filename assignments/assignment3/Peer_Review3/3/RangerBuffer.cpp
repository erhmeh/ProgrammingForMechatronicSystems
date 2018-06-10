#include "RangerBuffer.h"

RangerBuffer::RangerBuffer(NotificationBuffer *notificationBuffer) {
    notificationBuffer_ = notificationBuffer;
}


void RangerBuffer::addValue(cMeasurement measurement) {
    std::unique_lock<std::mutex> lock(mutex_);
    lastValue_ = value_;    //!Stores old value to enable extrapolation in ranger fusion
    value_ = measurement;
    cv_.notify_all();
    notificationBuffer_->notify(this); //!Notifies the notification buffer and passes itself as a pointer
}


std::pair<cMeasurement,cMeasurement> RangerBuffer::getValues() {
    std::unique_lock<std::mutex> lock(mutex_);
    return std::pair<cMeasurement,cMeasurement>(value_,lastValue_);
}

