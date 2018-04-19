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
<<<<<<< HEAD
    bool setAngularRes(double i);
=======
    bool setXOffset(double i);
    bool setOOffset(double i);
protected:
>>>>>>> master
};

#endif // LASER_H
