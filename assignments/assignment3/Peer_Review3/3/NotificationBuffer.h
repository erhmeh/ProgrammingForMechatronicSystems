#ifndef ASSIGNMENT3_NOTIFICATIONBUFFER_H
#define ASSIGNMENT3_NOTIFICATIONBUFFER_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include "CustomTypes.h"


class RangerBuffer; //To allow declaration of temporary pointer to the ranger buffer which stores the rangerbuffer with
                    // the newest value. Otherwise cross reference to RangerBuffer results in compiler error


/*! \class NotificationBuffer
    \brief A class to allow thread safe multiple producer single consumer relationship of rangers and a ranger fusion
 *  \date      20.05.2018
    A NotificationBuffer can be used to allow waiting on a new measurement from multiple producer threads which have their
    individual RangerBuffer as a buffer for the data stream.
    A ranger fusion thread can wait for a notification of this buffer to fuse all measurements when a one ranger produces
    a new measurement
*/

class NotificationBuffer
{
private:
    /**
    * Mutex variable for this buffer
    */
    std::mutex mutex_;
    /**
    * Conditional variable of this buffer
    */
    std::condition_variable cv_;
    /**
    * Pointer to the ranger buffer which contains the latest result.
     * The pointer has to be safed to be forwarded to the waiting ranger fusion
    */
    RangerBuffer *ranger_buffer_latest_;

public:
    //! Function implementing a wait on the conditional variable of this pointer and forwards the buffer which holds the latest measurement
    /*!
      \return Pointer to the buffer which holds the latest measurement
    */
    RangerBuffer* wait_for_notification();

    //! Function called by a Ranger buffer when it receives a new measurement to notify the consumer
    /*!
      \param rangerBuffer Pointer to the ranger buffer which calls notify as it received a new measurement
    */
    void notify(RangerBuffer* rangerBuffer);
};


#endif //ASSIGNMENT3_NOTIFICATIONBUFFER_H
