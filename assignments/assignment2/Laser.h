/* Laser.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#ifndef LASER_H
#define LASER_H

#include "Ranger.h"

class Laser : public Ranger
{
public:
    Laser();
    bool setAngularRes(double i);
protected:
};

#endif // LASER_H
