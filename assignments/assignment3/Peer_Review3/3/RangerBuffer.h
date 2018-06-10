#ifndef ASSIGNMENT3_RANGER_BUFFER_H
#define ASSIGNMENT3_RANGER_BUFFER_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include "CustomTypes.h"
#include "NotificationBuffer.h"


/*! \class RangerBuffer
    \brief A class to allow thread safe producer consumer realtionship of rangers and a ranger fusion
 *  \date      20.05.2018
    Each ranger is connected to the ranger fusion via a RangerBuffer. This allows thread safe producer consumer relationship.
    To allow waiting on multiple producer a NotificationBuffer is used as a global conditional variable which can be
    notified by all RangerBuffers when they receive a new measurement
*/

class RangerBuffer {
public:
    //!Constructor of the ranger buffer
    /*! Stores a pointer to a notification buffer to allow multiple ranger buffer to notify a waiting thread
      \param notificationBuffer A pointer to a notification buffer
    */
    RangerBuffer(NotificationBuffer *notificationBuffer);

    //! Adds a value to the buffer.
    /*! Thread safe add functionality which stores the measurement as the value and safes the last value
     *! Notifies all threads waiting on this buffers conditional variable as well as the notification buffer to allow
     *! multiple consumer
      \param measurement struct of type cMeasurement which contains the latest measurement
    */
    void addValue(cMeasurement measurement);
    //! Returns the stored values.
    /*! Thread safe get function returning the values as a pair
      \return Pair holding the latest(first) and the last(second) measurement struct
    */
    std::pair<cMeasurement, cMeasurement> getValues();


private:
    /**
    * Pointer to notification buffer for multiple producer notification
    */
    NotificationBuffer *notificationBuffer_;

    /**
    * Mutex variable for this buffer
    */
    std::mutex mutex_;
    /**
    * Conditional variable of this buffer
    */
    std::condition_variable cv_;

    /**
    * Member variable to store last cMeasurement struct
    */
    cMeasurement lastValue_;

    /**
    * Member variable to store latest cMeasurement struct
    */
    cMeasurement value_;
};


#endif //ASSIGNMENT3_RANGER_BUFFER_H
