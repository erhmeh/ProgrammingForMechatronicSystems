/**
 * ranger.cpp
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

Ranger::Ranger()
{
    lastReading = chrono::system_clock::now().time_since_epoch();
}

/** Sets baud rate. Returns if sane */
bool Ranger::setBaudRate(int i)
{
    if (i == 38400 || i == 115200)
    {
        baudRate_ = i;
        return true;
    }
    else
    {
        return false;
    }
}

/** Returns baud rate */
int Ranger::getBaudRate()
{
    return baudRate_;
}

/** Sets port. Returns if sane */
bool Ranger::setTtyACM(int i)
{
    if (i == 0 || i == 1 || i == 2)
    {
        ttyACM_ = i;
        return true;
    }
    else
    {
        return false;
    }
}

/** Returns port */
int Ranger::getTty()
{
    return ttyACM_;
}

/** Returns field of view */
double Ranger::getFov()
{
    return fov_;
}

int Ranger::getDataRate()
{
    return dataRate_;
}

/** Sets minimum distance. Returns if sane */
bool Ranger::setMinDistance(double i)
{
    if (i >= 0)
    {
        minDist_ = i;
        return true;
    }
    else
    {
        return false;
    }
}

/** Returns minimum distance */
double Ranger::getMinDistance()
{
    return minDist_;
}

/** Sets maximum distance. Returns if sane */
bool Ranger::setMaxDistance(double i)
{
    if (i > 0)
    {
        maxDist_ = i;
        return true;
    }
    else
    {
        return false;
    }
}

/** Returns maximum distance */
double Ranger::getMaxDistance()
{
    return maxDist_;
}

void Ranger::takeReading(mutex &mu, condition_variable &cond)
{
    double updateRate = 1.0 / dataRate_;

    while (true)
    {
        mu.lock();
        auto now = chrono::system_clock::now().time_since_epoch();
        std::chrono::duration<double> elapsed_seconds = now - lastReading;
        if (elapsed_seconds.count() > updateRate)
        {
            double w = 0.31459;
            default_random_engine generator(now.count());
            normal_distribution<double> distribution(0, 0.1);
            double i = distribution(generator);
            dataStream_.push(6.0 + (4 * sin(w * now.count())) + i);
            lastReading = now;
        }
        mu.unlock();
        cond.notify_one();
    }
}
