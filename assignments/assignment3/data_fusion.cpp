/**
 * data_fusion.cpp
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */

 #include "ranger.h"
 #include <iostream>
 #include <queue>
 #include <chrono>
 #include <math.h>
 #include <random>
 #include <mutex>
 #include <condition_variable>
 #include <thread>
 #include "data_fusion.h"

#define FUSE_RATE 5 /** Frequency of which a fusion occurs (3.c.i Produce a fused result at 5 Hz) */

DataFusion::DataFusion()
{
}

/** Start fusion member function. This accepts two references to queues (one for each sensor), mustex and condition variable and the selected fuse method */
void DataFusion::startFusion(queue<double> &stream1, queue<double> &stream2, mutex &mu, condition_variable &cond, int fuseMethod)
{
    fuseRate_ = 5;
    double updateRate = 1.0 / fuseRate_; /** Turn freqency (Hz) into a period */
    while (true)
    {
        bool newReading = false;
        mu.lock(); /** Lock mutex */
        if (!stream1.empty()) /** When a new reading is entered into stream1, update the local variable */
        {
            lastReading1_ = stream1.front(); /** Copy variable */
            stream1.pop(); /** Pop from front of queue */
            newReading = true; /** Change varaible to notify that a new variable has been entered (3.c.ii produce a fused result on each new piece of sensor data) */
        }
        if (!stream2.empty())/** When a new reading is entered into stream2, update the local variable */
        {
            lastReading2_ = stream2.front(); /** Copy variable */
            stream2.pop(); /** Pop from front of queue */
            newReading = true; /** Change varaible to notify that a new variable has been entered (3.c.ii produce a fused result on each new piece of sensor data) */
        }
        auto now = chrono::system_clock::now().time_since_epoch(); /** Set current time to now */
        std::chrono::duration<double> elapsed_seconds = now - lastFuseTime_; /** Calculate the duration since the last reading */
        if (elapsed_seconds.count() > updateRate || newReading) /** True if enough time has passed or a new reading has been taken */
        {
            /** Print out the reason why the event occured and reach sensor's reading */
            if (elapsed_seconds.count() > updateRate)
            {
                cout << fuseRate_ << "Hz fusion reading. Radar: " << lastReading1_ << " Sonar: " << lastReading2_ << endl;
            }
            if (newReading)
            {
                cout << "New reading detected. Radar: " << lastReading1_ << " Sonar: " << lastReading2_ << endl;
            }
            if (fuseMethod == 1) /** If the selected fusion method is minimum, compare the two readings and assign the smallest to the fusedData_ variable */
            {
                if (lastReading1_ <= lastReading2_)
                {
                    fusedData_ = lastReading1_;
                }
                else
                {
                    fusedData_ = lastReading2_;
                }
                cout << "Min: " << fusedData_ << endl; /** Print the minimum to the console */
            }
            if (fuseMethod == 2)
            {
                if (lastReading1_ >= lastReading2_)
                {
                    fusedData_ = lastReading1_;
                }
                else
                {
                    fusedData_ = lastReading2_;
                }
                cout << "Max: " << fusedData_ << endl;
            }
            if (fuseMethod == 3)
            {
                fusedData_ = (lastReading1_ + lastReading2_) / 2;
                cout << "Avg: " << fusedData_ << endl;
            }
            if (!newReading)
            {
                lastFuseTime_ = now;
            }
        }
        mu.unlock();
    }
}
