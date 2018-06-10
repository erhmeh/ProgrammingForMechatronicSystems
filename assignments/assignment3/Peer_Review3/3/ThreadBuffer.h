#ifndef ASSIGNMENT3_THREADBUFFER_H
#define ASSIGNMENT3_THREADBUFFER_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>


/*! \class ThreadBuffer
    \brief Class to hold the fused result of a RangerFusion to be forwarded to the main an printed by the print thread
 *  \date      20.05.2018
    Printing in the main is excecuted on every new fused measurement which is stored in a ThreadBuffer.
    The class implements a thread safe buffer functionality to hold a double-time_point pair.
*/
class ThreadBuffer
{
public:
    //! Adds a value to the buffer.
    /*! Thread safe add functionality which stores the pair of distance value and time point
     *! Notifies all threads waiting on this buffers conditional variable
      \param value pair holding the distance(first) and the time point(second)
    */
    void addValue(std::pair<double,std::chrono::system_clock::time_point> value);
    //! Returns the value time pair stored in this buffer.
    /*! Thread safe get functionality to retrieve the value - time pair stored in this buffer
      \return Pair holding the distance(first) and the time point(second)
    */
    std::pair<double,std::chrono::system_clock::time_point> getValues();

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
    * Pair holding the fused distance(first) and the time at which the measurement was produced(second).
    */
    std::pair<double,std::chrono::system_clock::time_point> value_;
};

#endif //ASSIGNMENT3_THREADBUFFER_H
