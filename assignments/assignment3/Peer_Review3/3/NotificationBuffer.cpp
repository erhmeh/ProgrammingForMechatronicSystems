#include "NotificationBuffer.h"


RangerBuffer* NotificationBuffer::wait_for_notification() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock);
    return ranger_buffer_latest_;
}


void NotificationBuffer::notify(RangerBuffer* rangerBuffer) {
    std::unique_lock<std::mutex> lock(mutex_);
    ranger_buffer_latest_ = rangerBuffer;
    cv_.notify_all();
}