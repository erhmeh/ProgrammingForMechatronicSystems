/* sonar.cpp
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 3 Autumn Semester 2018
 */

#include "sonar.h"
#include "ranger.h"

#define SONAR_BAUD_DEFALUT 38400
#define SONAR_FOV          90
#define SONAR_MIN_DIST     0.2
#define SONAR_MAX_DIST     6.0
#define SONAR_DATA_RATE    3

Sonar::Sonar()
{
    setBaudRate(SONAR_BAUD_DEFALUT);
    setMinDistance(SONAR_MIN_DIST);
    setMaxDistance(SONAR_MAX_DIST);
    dataRate_ = SONAR_DATA_RATE;
    fov_ = SONAR_FOV;
}
