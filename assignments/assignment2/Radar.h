/* Radar.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#ifndef RADAR_H
#define RADAR_H

#include "Ranger.h"

class Radar : public Ranger
{
public:
    Radar();
    double readingAtAngle(double angle);
    void takeReading();

};

#endif // RADAR_H
