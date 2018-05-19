/**
 * radar.cpp
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */

#include "ranger.h"
#include "radar.h"
#include <chrono>
#include <random>
#include <iostream>
#include <tgmath.h>

/** Default values for the radar */
#define RADAR_BAUD_DEFAULT 38400
#define RADAR_FOV_DEFAULT  20.0
#define RADAR_MIN_DIST     0.2
#define RADAR_MAX_DIST     10.0
#define RADAR_DATA_RATE    10

/** When a radar object is initialised, it has all values set to default */
Radar::Radar()
{
    setBaudRate(RADAR_BAUD_DEFAULT);
    setMaxDistance(RADAR_MAX_DIST);
    setMinDistance(RADAR_MIN_DIST);
    dataRate_ = RADAR_DATA_RATE;
}

bool Radar::setFov(double i)
{
    if (i == 20 || i == 40)
    {
        fov_ = i;
        return true;
    }
    else
    {
        fov_ = RADAR_FOV_DEFAULT;
        return false;
    }
}
