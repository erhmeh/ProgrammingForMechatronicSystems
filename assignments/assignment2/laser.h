/* laser.h
 * Programming for Mechatronic systems
 * Assignment 2
 *
 * @author: Jamin Early 99133391
 * @date: Week 5-7 Autumn Semester 2018
 */

#ifndef LASER_H
#define LASER_H

#include "ranger.h"

class Laser : public Ranger
{
public:
  Laser();
  bool setAngularRes(double i);
  int sensorType_ = 1;
protected:
};

#endif // LASER_H
